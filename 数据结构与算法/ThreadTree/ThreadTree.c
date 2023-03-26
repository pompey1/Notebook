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

void PrintThreadTree(Tree tree)
{
    TreeNode *node = GetFirst(tree);
    while (node != NULL)
    {
        printf("%c", node->data);
        node = GetNext(node);
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
    PrintThreadTree(tree);
}