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
        (*tree)->flag = 0;
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

Bool IsEmpty(Stack head)
{
    if (head->next == NULL)
    {
        return true;
    }
    return false;
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

StackNode *GetTop(Stack head)
{
    if (IsEmpty(head))
    {
        return NULL;
    }
    else
    {
        return head->next;
    }
}

void PrintStack(Stack head)
{
    while (head->next)
    {
        head = head->next;
        printf("%c", head->data->data);
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
    // 重点，当你把数据存放在数据结构中的时候你是不能访问到他的，所以打印数据结构内容的行为必须放在入栈之前或者出栈之后
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

void PostOrder(Tree tree)
{
    Stack stack = InitStack();
    TreeNode *node = tree;
    while (node || !IsEmpty(stack))
    {
        // 必须要判断是否压入过栈，否则会死循环
        if (node && node->flag == 0)
        {
            node->flag = 1;
            Push(node, stack);
            node = node->lchild;
        }
        else
        {
            node = GetTop(stack)->data;
            // 为什么试图取出空指针指向的数据就直接终止了呢
            if (node->rchild && node->rchild->flag == 0)
            {
                node = node->rchild;
            }
            else
            {
                Pop(stack);
                printf("%c", node->data);
            }

            // 虽然栈顶元素改变了，但是node没有改变，因为出栈的内存没有free，仍然存在在内存中
        }
    }
}

void PostOrder2(Tree tree)
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
            TreeNode *top = GetTop(stack)->data;
            // 千万别把这部用来判断，把栈顶的元素用来判断是否要压入栈永远没有结果
            if (top->rchild && top->rchild->flag == 0)
            {
                top = top->rchild;
                Push(top, stack);
                top->flag = 1;
                node = top->lchild;
                //这里的node纯粹只是为了循环条件的判断，真实的内存读取是靠栈顶指针top
            }
            else
            {
                // 核心思路，node一直为null的时候会一直出栈并打印
                printf("%c", Pop(stack)->data->data);
            }
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
    printf("\n");
    PostOrder2(tree);
}
