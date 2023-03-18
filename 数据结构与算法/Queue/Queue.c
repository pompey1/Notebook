#include <stdio.h>
#include <stdlib.h>

typedef enum bool
{
    false,
    true
} bool;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef Node *Queue;

Queue InitQueue()
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("The memory is over");
    }
    node->data = 0;
    node->next = NULL;
}

bool IsEmpty(Queue head)
{
    if (head->next == NULL)
    {
        printf("Queue is empty");
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue(int data, Queue head)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("The memory is over");
    }
    node->data = data;
    node->next = head->next;
    head->next = node;
    head->data++;
}

int Dequeue(Queue head)
{
    if (IsEmpty(head))
    {
        return -1;
    }
    Node *preNode = head;
    Node *tempNode = head->next;
    while (tempNode->next != NULL)
    {
        preNode = tempNode;
        tempNode = tempNode->next;
    }
    preNode->next = NULL;
    int data = tempNode->data;
    head->data--;
    return data;
}

void PrintQueue(Queue head){
    Node* tempNode = head->next;
    while(tempNode!=NULL){
        printf("%d",tempNode->data);
        printf("\n");
        tempNode=tempNode->next;
    }
}

int main(){
    Queue queue = InitQueue();
    Enqueue(1, queue);
    Enqueue(2, queue);
    Enqueue(3, queue);
    Enqueue(4, queue);
    Enqueue(5, queue);
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    PrintQueue(queue);
}
