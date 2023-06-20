#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef enum bool
{
    false,
    true
} bool;

typedef struct Queue
{
    int front;
    int rear;
    int data[MAX_SIZE];
} Queue;

Queue *InitQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("Malloc fail");
    }
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

bool IsEmpty(Queue *queue)
{
    if (queue->front == queue->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 只有线性结构需要判断结构是否已满
bool IsFull(Queue *queue)
{
    if ((queue->rear + 1) % (MAX_SIZE) == queue->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Enqueue(int data, Queue *queue)
{
    if (IsFull(queue))
    {
        printf("The queue is full\n");
        return -1;
    }
    queue->data[queue->rear] = data;
    // 通过mod操作实现index的循环
    queue->rear = (queue->rear + 1) % (MAX_SIZE);
    // queue->rear++;
    return data;
}

int Dequeue(Queue *queue)
{
    if (IsEmpty(queue))
    {
        printf("The queue is empty\n");
        return -1;
    }
    int tempData = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    // queue->front++;
    return tempData;
}

void PrintLoopQueue(Queue *queue)
{
    int length = (queue->rear - queue->front + MAX_SIZE) % MAX_SIZE;
    for (int i = 0; i < length; i++)
    {
        printf("%d", queue->data[(queue->front + i) % MAX_SIZE]);
        printf("\n");
    }
}

int main()
{
    Queue *queue = InitQueue();
    Enqueue(1, queue);
    Enqueue(2, queue);
    Enqueue(3, queue);
    Enqueue(4, queue);
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    PrintLoopQueue(queue);
}
