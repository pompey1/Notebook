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

typedef TreeNode *Tree;

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

TreeNode *GetFirst(TreeNode *treeNode)
{
    while (treeNode->lTag == 0)
    {
        treeNode = treeNode->lchild;
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
    PrintPreThreadTree(tree);
}