#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

typedef TreeNode *Tree;

void CreateTree(Tree *tree, char *string, int *index)
{
    char tempChar = string[*index];
    *index += 1;
    // 暂存一下字符，免得index移动以后值发生改变
    if (tempChar == '#')
    {
        *tree = NULL;
        //这里要将tree设置为NULL,以此来将根节点的lchild和rchild设置为NULL，否则会无尽循环
    }
    else
    {
        *tree = (TreeNode *)malloc(sizeof(TreeNode));
        if (!*tree)
        {
            printf("malloc fail!");
        }
        (*tree)->data = tempChar;
        CreateTree(&((*tree)->lchild), string, index);
        CreateTree(&((*tree)->rchild), string, index);
    }
}

typedef struct QueueNode
{
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef QueueNode *Queue;

Queue InitQueue()
{
    Queue queue = (QueueNode *)malloc(sizeof(QueueNode));
    queue->treeNode = NULL;
    queue->next = NULL;
    return queue;
}

void Enqueue(TreeNode *treeNode, Queue head)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->treeNode = treeNode;
    node->next = head->next;
    head->next = node;
}

TreeNode *Dequeue(Queue head)
{
    QueueNode *pre = head;
    QueueNode *temp = head->next;
    while (temp->next)
    {
        pre = temp;
        temp = temp->next;
    }
    TreeNode *treeNode = temp->treeNode;
    pre->next = temp->next;
    // 这里一定要把前一个指针指向尾指针的next（即NULL），不然即使free也还是连着
    free(temp);
    return treeNode;
}

int IsEmpty(Queue head)
{
    if (head->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// void PrintQueue(Queue head)
// {
//     QueueNode *temp = head;
//     while (temp->next)
//     {
//         temp = temp->next;
//         printf("%c", temp->data);
//     }
// }

void TreeLevelTranversal(Queue queue, TreeNode *head)
{
    Enqueue(head, queue);
    while (!IsEmpty(queue))
    {
        TreeNode *treeNode = Dequeue(queue);
        printf("%c", treeNode->data);
        if (treeNode->lchild)
        {
            Enqueue(treeNode->lchild, queue);
        }
        if (treeNode->rchild)
        {
            Enqueue(treeNode->rchild, queue);
        }
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
        printf("%c", tree->data);
        //printf("%c", tree->data);
        PrintTree(tree->lchild); 
        //printf("%c", tree->data); 
        PrintTree(tree->rchild);
        //print当前节点（即他的左子树和右子树的根节点）的位置决定了他是前序中序还是后许遍历
    }
}
int main()
{
    Queue queue = InitQueue();
    Tree tree;
    int index = 0;
    CreateTree(&tree, "ABD##E##CF##G##", &index);
    //PrintTree(tree);
    TreeLevelTranversal(queue, tree);
}
