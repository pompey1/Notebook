#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef Node *List;

List InitList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("memory is over");
    }
    head->data = 0;
    head->next = head;
    return head;
}

void HeadInsert(int data, List head)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("memory is over");
    }
    node->data = data;
    node->next = head->next;
    head->next = node;
    head->data++;
}

void TailInsert(int data, List head)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("memory is over");
    }
    Node *tempNode = head;
    while (tempNode->next != head)
    {
        tempNode = tempNode->next;
    }
    node->data = data;
    node->next = head;
    tempNode->next = node;
    head->data++;
    // 重点：别把next的链接断了，优先接住next的地址
}

int Delete(int data, List head)
{
    Node *pre = head;
    Node *tempNode = head->next;
    while (tempNode != head)
    {
        if (tempNode->data == data)
        {
            pre->next = tempNode->next;
            free(tempNode);
            head->data--;
            return True;
        }
        pre = tempNode;
        tempNode = tempNode->next;
    }
    return False;
}

int PrintList(List head)
{
    Node *tempNode = head->next;
    while (tempNode != head)
    {
        printf("%d\n", tempNode->data);
        tempNode = tempNode->next;
    }
}

int main()
{
    List myList = InitList();
    HeadInsert(5, myList);
    HeadInsert(4, myList);
    HeadInsert(3, myList);
    HeadInsert(2, myList);
    HeadInsert(1, myList);
    TailInsert(6, myList);
    TailInsert(7, myList);
    TailInsert(8, myList);
    TailInsert(9, myList);
    TailInsert(10, myList);
    Delete(4, myList);
    Delete(1, myList);
    Delete(10, myList);
    PrintList(myList);
}