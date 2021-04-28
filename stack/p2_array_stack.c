#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Stack{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack* CreateStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(sizeof(int));
    return stack;
}

int isFull(struct Stack* stack){
    return stack->capacity == stack->top+1;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

void Push(struct Stack* stack, int item){
    if (isFull(stack))
        return;
    
    //If stack is not full
    stack->top++;
    stack->array[stack->top] = item;
    printf("%d pushed to stack\n",item);
}

int Pop(struct Stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
        
    //If stack is not empty
    return stack->array[stack->top--];
}

int Peek(struct Stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
    
    return stack->array[stack->top];
}

int main() {
    // Write C code here
    struct Stack* stack = CreateStack(10);
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    Push(stack, 40);
    
    printf("%d is the top of the element\n", Peek(stack));
    
    
    printf("Element popped in the stack is %d\n", Pop(stack));
    
    while(!isEmpty(stack)){
        printf("Elements in the stack is %d\n",Pop(stack));
    }
    
    
    return 0;
}