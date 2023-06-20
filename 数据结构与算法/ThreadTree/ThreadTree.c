#include <stdio.h>
#include <stdlib.h>
#define ElementType struct TreeNode *

typedef enum Bool
{
    false,
    true
} Bool;

typedef struct TreeNode
{
    char data;
    int flag;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
    int lTag;
    int rTag;
} TreeNode;

typedef struct TripleTreeNode
{
    char data;
    int flag;
    struct TripleTreeNode *lchild;
    struct TripleTreeNode *rchild;
    struct TripleTreeNode *parent;
    int lTag;
    int rTag;
} TripleTreeNode;

typedef TreeNode *Tree;
typedef TripleTreeNode *TripleTree;

Bool TryCreateTree(Tree *tree, char *string, int *index)
{
    char tempChar = string[*index];
    *index += 1;
    if (tempChar == '#')
    {
        *tree = NULL;
        return true;
    }
    else
    {
        *tree = (TreeNode *)malloc(sizeof(TreeNode));
        if (*tree == NULL)
        {
            printf("Create Tree Fail!");
            return false;
        }
        (*tree)->data = tempChar;
        (*tree)->lTag = 0;
        (*tree)->rTag = 0;
        (*tree)->flag = 0;
        TryCreateTree(&(*tree)->lchild, string, index);
        TryCreateTree(&(*tree)->rchild, string, index);
    }
    return true;
}

Bool TryCreateTripleTree(TripleTree *tree, char *string, int *index, TripleTree parent)
{
    char tempChar = string[*index];
    *index += 1;
    if (tempChar == '#')
    {
        *tree = NULL;
        return true;
    }
    else
    {
        *tree = (TripleTreeNode *)malloc(sizeof(TripleTreeNode));
        if (*tree == NULL)
        {
            printf("Create Tree Fail!");
            return false;
        }
        (*tree)->data = tempChar;
        (*tree)->lTag = 0;
        (*tree)->rTag = 0;
        (*tree)->flag = 0;
        (*tree)->parent = parent;
        TryCreateTripleTree(&(*tree)->lchild, string, index, *tree);
        TryCreateTripleTree(&(*tree)->rchild, string, index, *tree);
    }
    return true;
}

void InThreadTree(Tree tree, TreeNode **pre)
{
    if (tree != NULL)
    {
        InThreadTree(tree->lchild, pre);
        if (!tree->lchild)
        {
            tree->lchild = *pre;
            tree->lTag = 1;
        }
        if ((*pre) != NULL && !(*pre)->rchild)
        {

            (*pre)->rchild = tree;
            (*pre)->rTag = 1;
        }
        *pre = tree;
        InThreadTree(tree->rchild, pre);
    }
}

void PreThreadTree(Tree tree, TreeNode **pre)
{
    if (tree != NULL)
    {
        if (!tree->lchild)
        {
            tree->lchild = *pre;
            tree->lTag = 1;
        }
        if ((*pre) != NULL && !(*pre)->rchild)
        {

            (*pre)->rchild = tree;
            (*pre)->rTag = 1;
        }
        *pre = tree;
        if (tree->lTag == 0)
        {
            PreThreadTree(tree->lchild, pre);
            PreThreadTree(tree->rchild, pre);
        }
    }
}

void PostThreadTree(TripleTree tree, TripleTreeNode **pre)
{
    if (tree != NULL)
    {
        PostThreadTree(tree->lchild, pre);
        PostThreadTree(tree->rchild, pre);
        if (!tree->lchild)
        {
            tree->lchild = *pre;
            tree->lTag = 1;
        }
        if ((*pre) != NULL && !(*pre)->rchild)
        {

            (*pre)->rchild = tree;
            (*pre)->rTag = 1;
        }
        *pre = tree;
    }
}

TreeNode *GetFirst(TreeNode *treeNode)
{
    while (treeNode->lTag == 0)
    {
        treeNode = treeNode->lchild;
    }
    return treeNode;
}

TripleTreeNode *GetFirstPostOrder(TripleTreeNode *treeNode)
{
    while (treeNode->lTag == 0)
    {
        treeNode = treeNode->lchild;
    }
    if (treeNode->rTag == 0 && treeNode->rchild != NULL)
    {
        if (GetFirstPostOrder(treeNode->rchild) != NULL)
        {
            treeNode = GetFirstPostOrder(treeNode->rchild);
        }
    }
    return treeNode;
}

TreeNode *GetNext(TreeNode *treeNode)
{
    if (treeNode->rTag == 1)
    {
        return treeNode->rchild;
    }
    else
    {
        return GetFirst(treeNode->rchild);
    }
}

TreeNode *GetNextPreOrder(TreeNode *treeNode)
{
    if (treeNode->rTag == 1 || treeNode->lTag == 1)
    {
        return treeNode->rchild;
    }
    else
    {
        return treeNode->lchild;
    }
}
TripleTreeNode *GetNextPostOrder(TripleTreeNode *treeNode)
{
    if (treeNode->rTag == 1)
    {
        return treeNode->rchild;
    }
    else
    {
        if (treeNode->parent == NULL)
        {
            return NULL;
        }
        if (treeNode->parent->rchild == treeNode || treeNode->parent->rchild == NULL)
        {
            return treeNode->parent;
        }
        else
        {
            return GetFirstPostOrder(treeNode->parent->rchild);
        }
    }
}
void PrintInThreadTree(Tree tree)
{
    TreeNode *node = GetFirst(tree);
    while (node != NULL)
    {
        printf("%c", node->data);
        node = GetNext(node);
    }
}

void PrintPreThreadTree(Tree tree)
{
    while (tree != NULL)
    {
        printf("%c", tree->data);
        tree = GetNextPreOrder(tree);
    }
}
void PrintPostThreadTree(TripleTree tree)
{
    TripleTreeNode *node = GetFirstPostOrder(tree);
    while (node != NULL)
    {
        printf("%c", node->data);
        node = GetNextPostOrder(node);
    }
}

int main()
{
    Tree tree;
    int index = 0;
    TryCreateTree(&tree, "ABD##E##CF##G##", &index);
    TreeNode *treeNode = NULL;
    InThreadTree(tree, &treeNode);
    treeNode->rchild = NULL;
    treeNode->rTag = 1;
    PrintInThreadTree(tree);
    printf("\n");

    tree = NULL;
    index = 0;
    TryCreateTree(&tree, "ABD##E##CF##G##", &index);
    treeNode = NULL;
    PreThreadTree(tree, &treeNode);
    treeNode->rchild = NULL;
    treeNode->rTag = 1;
    PrintPreThreadTree(tree);
    printf("\n");

    TripleTree tripleTree;
    index = 0;
    TryCreateTripleTree(&tripleTree, "ABD##E##CF##G##", &index, tripleTree);
    TripleTreeNode *tripleTreeNode = NULL;
    PostThreadTree(tripleTree, &tripleTreeNode);
    // printf(GetFirstPostOrder(tripleTree)->data);
    PrintPostThreadTree(tripleTree);
}