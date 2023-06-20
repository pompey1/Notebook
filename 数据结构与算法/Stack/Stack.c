# include<stdio.h>
# include<stdlib.h>

typedef enum bool{
    false,
    true
}bool;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef Node* Stack;

Stack InitStack(){
    Node* head = (Node*)malloc(sizeof(Node));
    if(head==NULL){
        printf("init fail");
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

bool IsEmpty(Stack head){
    if(head->next == NULL){
        return true;
    }else{
        return false;
    }
}

int Pop(Stack head){
    if(IsEmpty(head)){
        printf("The stack is empty!");
        return -1;
    }else{
        Node* tempNode = head->next;
        head->next = head->next->next;
        head->data--;
        free(tempNode);
        return head->data;
    }
}

void Push(int data, Stack head){
    Node* node = (Node*)malloc(sizeof(Node));
    if(node==NULL){
        printf("push fail");
    }
    node->data = data;
    node->next = head->next;
    head->next = node;
    head->data++;
}

void PrintStack(Stack head){
    Node* node = head->next;
    while(node!=NULL){
        printf("%d",node->data);
        printf("\n");
        node = node->next;
    }
}

int main(){
    Stack stack = InitStack();
    Push(5, stack);
    Push(4, stack);
    Push(3, stack);
    Push(2, stack);
    Push(1, stack);
    Push(0, stack);
    Pop(stack);
    Pop(stack);
    PrintStack(stack);
}