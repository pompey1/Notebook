#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
    int data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

typedef TreeNode *Tree;

void InsertBst(Tree *tree, int data)
{
    if (*tree == NULL)
    {
        *tree = (TreeNode *)malloc(sizeof(TreeNode));
        (*tree)->data = data;
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
    }
    else
    {
        if ((*tree)->data < data)
        {
            InsertBst(&((*tree)->rchild), data);
        }
        else
        {
            InsertBst(&((*tree)->lchild), data);
        }
    }
}

Tree SearchBst(Tree tree, int data)
{
    if (tree->data == data)
    {
        return tree;
    }
    else
    {
        if (tree->data < data)
        {
            return SearchBst(tree->rchild, data);
        }
        else
        {
            return SearchBst(tree->lchild, data);
        }
    }
}

void PrintInOrder(Tree tree)
{
    if (tree == NULL)
    {
        return;
    }
    PrintInOrder(tree->lchild);
    printf("%d", tree->data);
    PrintInOrder(tree->rchild);
}

int main()
{
    Tree tree;
    int a[6] = {2, 1, 5, 3, 4, 6};
    for (int i = 0; i < 6; i++)
    {
        InsertBst(&tree, a[i]);
    }
    PrintInOrder(tree);
    printf("\n");
    printf("%d", SearchBst(tree, 3)->data);
}
