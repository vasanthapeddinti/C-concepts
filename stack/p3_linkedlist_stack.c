//insert or delete operation for stack linkedlist is done from head

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct StackNode{
    int data;
    struct StackNode* next;
};

struct StackNode* CreateStack(int item){
    struct StackNode* stacknode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stacknode->data = item;
    stacknode->next = NULL;
    return stacknode;
}

int isEmpty(struct StackNode *top){
    return (!top);
}

void Push(struct StackNode **top, int item){
    struct StackNode* stacknode = CreateStack(item);
    stacknode->next = *top;
    *top = stacknode;
}

int Pop(struct StackNode **top){
    if(isEmpty(*top)){
        return INT_MIN;
    }
    struct StackNode* temp = *top;
    (*top) = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int Peek(struct StackNode *top){
    if(isEmpty(top)){
        return INT_MIN;
    }
    return top->data;
}

int main() {
    struct StackNode* top = NULL;
    Push(&top, 10);
    Push(&top, 20);
    Push(&top, 30);
    Push(&top, 40);
    
    printf("%d is the top element\n", Peek(top));
    printf("%d is the popped element\n", Pop(&top));
    printf("%d is the top element\n", Peek(top));
    
    return 0;
}