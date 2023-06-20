#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *
{
    int data;
    int height;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}
TreeNode;

int getHeight(TreeNode *node)
{
    return node ? node->height : 0;
}

void llRotation(TreeNode *node, TreeNode **root)
{
    //
}

void AVLInsert(int data, TreeNode **T)
{
    if (*T == NULL)
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->height = 0;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        (*T)->height = 0;
    }
    else if (data < (*T)->data)
    {
        AVLInsert(data, (*T)->lchild);
        int lHeight = getHeight(*T->lchild);
        int rHeight = getHeight(*T->rchild);
        if (data < (*T)->lchild->data)
        {
            // LL调整
        }
        else
        {
            // LR调整
        }
    }
    else if (data > (*T)->data)
    {
        AVLInsert(data, (*T)->rchild);
        int lHeight = getHeight(*T->lchild);
        int rHeight = getHeight(*T->rchild);
        if (data > (*T)->lchild->data)
        {
            // RR调整
        }
        else
        {
            // RL调整
        }
    }
}

void preOrder(TreeNode *T)
{
    if (T)
    {
        printf("%d", T->data);
        preOrder(T->lchild);
        preOrder(T->rchlid);
    }
}

int main()
{
    TreeNode *T = NULL;
    int nums[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        AVLInsert(nums[i], &T);
    }
}