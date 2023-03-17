#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *pre;
    struct Node *next;
    int data;
} Node;

typedef Node *List;

List InitList()
{
    List list = (Node *)malloc(sizeof(Node));
    if (list == NULL)
    {
        printf("memory is over");
    }
    list->pre = list;
    list->next = list;
    list->data = 0;
}

void HeadInsert(int data, List head)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("memory is over");
    }
    node->data = data;
    node->pre = head;
    node->next = head->next;
    node->pre->next = node;
    node->next->pre = node;
    head->data++;
}

void TailInsert(int data, List head)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("memory is over");
    }
    Node *tail = head->pre;
    node->data = data;
    node->pre = tail;
    node->next = head;
    node->pre->next = node;
    node->next->pre = node;
    head->data++;
}

void Delete(int data, List head)
{
    Node *tempNode = head->next;
    while (tempNode != head)
    {
        if (tempNode->data == data)
        {
            tempNode->pre->next = tempNode->next;
            tempNode->next->pre = tempNode->pre;
            free(tempNode);
            head->data--;
            return;
        }
        tempNode = tempNode->next;
    }
}

void PrintList(List head)
{
    Node *tempNode = head->next;
    while (tempNode != head)
    {
        printf("%d", tempNode->data);
        printf("\n");
        tempNode = tempNode->next;
    }
}

int main()
{
    List list = InitList();
    HeadInsert(1, list);
    HeadInsert(2, list);
    HeadInsert(3, list);
    HeadInsert(4, list);
    HeadInsert(5, list);
    TailInsert(6, list);
    TailInsert(7, list);
    TailInsert(8, list);
    TailInsert(9, list);
    TailInsert(10, list);
    Delete(1, list);
    Delete(5, list);
    Delete(10, list);
    PrintList(list);
}