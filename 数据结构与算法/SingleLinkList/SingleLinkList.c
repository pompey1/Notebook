#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *Next;
} Node;

typedef Node *List;

List InitList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->Next = NULL;
    return head;
}

void HeadInsert(int data, List head)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->Next = head->Next;
    head->Next = node;
    head->data++;
}

void TailInsert(int data, List head)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->Next = NULL;
    Node *tempNode = head;
    while (tempNode->Next)
    {
        tempNode = tempNode->Next;
    }
    tempNode->Next = node;
    head->data++;
}

void Delete(int data, List head)
{
    Node *pre = head;
    Node *tempNode = head->Next;
    while (tempNode)
    {
        if (tempNode->data == data)
        {
            pre->Next = tempNode->Next;
            free(tempNode);
            head->data--;
            break;
        }
        pre = tempNode;
        tempNode = tempNode->Next;
    }
}

void PrintList(List head)
{
    Node* list = head->Next;
    while (list)
    {
        printf("%d", list->data);
        printf("\n");
        list = list->Next;
    }
}

int main()
{
    List testList = InitList();
    HeadInsert(1, testList);
    HeadInsert(2, testList);
    HeadInsert(3, testList);
    HeadInsert(4, testList);
    HeadInsert(5, testList);
    TailInsert(6, testList);
    TailInsert(7, testList);
    TailInsert(8, testList);
    TailInsert(9, testList);
    TailInsert(10, testList);
    Delete(5, testList);
    Delete(10,testList);
    Delete(7,testList);
    PrintList(testList);
}