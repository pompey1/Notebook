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
    struct TreeNode *lchild;
    struct TreeNode *rchild;
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
        TryCreateTree(&(*tree)->lchild, string, index);
        TryCreateTree(&(*tree)->rchild, string, index);
    }
    return true;
}

typedef struct StackNode
{
    ElementType data;
    struct StackNode *next;
} StackNode;

typedef StackNode *Stack;

Stack InitStack()
{
    Stack stack = (StackNode *)malloc(sizeof(StackNode));
    stack->data = 0;
    stack->next = NULL;
    return stack;
}

Bool Push(ElementType element, Stack head)
{
    StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode));
    if (stackNode == NULL)
    {
        printf("Push Fail!");
        return false;
    }
    stackNode->data = element;
    stackNode->next = head->next;
    head->next = stackNode;
    return true;
}

Bool IsEmpty(Stack head)
{
    if (head->next == NULL)
    {
        return true;
    }
    return false;
}

StackNode *Pop(Stack head)
{
    if (IsEmpty(head))
    {
        printf("The stack is empty!Pop fail!");
        return NULL;
    }
    StackNode *tempNode = head->next;
    head->next = tempNode->next;
    return tempNode;
}

void PrintStack(Stack head)
{
    while (head->next)
    {
        head = head->next;
        printf("%d", head->data);
    }
}

void PreOrder(Tree tree)
{
    Stack stack = InitStack();
    TreeNode *node = tree;
    while (node || !IsEmpty(stack))
    {
        if (node)
        {
            Push(node, stack);
            printf("%c", node->data);
            node = node->lchild;
        }
        else
        {
            node = Pop(stack)->data;
            node = node->rchild;
        }
    }
}

void InOrder(Tree tree)
{
    Stack stack = InitStack();
    TreeNode *node = tree;
    while (node || !IsEmpty(stack))
    {
        if (node)
        {
            Push(node, stack);
            node = node->lchild;
        }
        else
        {
            node = Pop(stack)->data;
            printf("%c", node->data);
            node = node->rchild;
        }
    }
}

int main()
{
    Tree tree;
    int index = 0;
    TryCreateTree(&tree, "ABD##E##CF##G##", &index);
    PreOrder(tree);
    printf("\n");
    InOrder(tree);
}
