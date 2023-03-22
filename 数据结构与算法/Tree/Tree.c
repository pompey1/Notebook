#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
} TreeNode;

typedef TreeNode *Tree;

void CreateTree(Tree* tree, char *string, int *index)
{
    char tempChar = string[*index];
    *index = *index + 1;
    if (tempChar == '#')
    {
        *tree = NULL;
    }
    else
    {
        *tree = (TreeNode *)malloc(sizeof(TreeNode));
        if (!*tree)
        {
            printf("malloc fail!");
        }
        (*tree)->data = tempChar;
        CreateTree(&(*tree)->lChild, string, index);
        CreateTree(&(*tree)->rChild, string, index);
    }
}

void PrintTree(Tree tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        //printf("%c", tree->data);
        PrintTree(tree->lChild); 
        //printf("%c", tree->data); 
        PrintTree(tree->rChild);
        printf("%c", tree->data);
        //print当前节点（即他的左子树和右子树的根节点）的位置决定了他是前序中序还是后许遍历
    }
}

int main()
{
    Tree tree;
    char *string = "ABD##E##CF##G##";
    int index = 0;
    CreateTree(&tree, string, &index);
    PrintTree(tree);
}