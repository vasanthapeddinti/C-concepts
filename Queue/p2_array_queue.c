// Implementing a queue using an array uses an idea called 
// circular array. It creates an illusion that the array is 
// circular(element access) eventhough the array is implemented as a linear 
// array


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{
    int front, rear, size;
    int* array;
    unsigned capacity;
};


struct Queue* Createqueue(int capacity){
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue){
    return (queue->size == 0);
}

int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}

//changes rear side and size
void Enqueue(struct Queue* queue, int item){
    if(isFull(queue))
        return;
    
    queue->rear = (queue->rear + 1)%(queue->capacity);
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    return;
}


//changes front side and size
int Dequeue(struct Queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
        
    int item = queue->array[queue->front];
    queue->front = queue->front + 1;
    queue->size = queue->size - 1;
    return item;
}

int Front(struct Queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
    
    return queue->array[queue->front];
}

int Rear(struct Queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
    
    return queue->array[queue->rear];
}


int main() { 
    
    struct Queue* queue = Createqueue(10);
    Enqueue(queue,10);
    Enqueue(queue, 20);
    Enqueue(queue, 30);
    Enqueue(queue, 40);
    
    printf("%d - Front, %d - Rear\n", Front(queue), Rear(queue));
    
    Dequeue(queue);
    printf("%d - Front, %d - Rear\n", Front(queue), Rear(queue));

    Enqueue(queue, 50);
    printf("%d - Front, %d - Rear", Front(queue), Rear(queue));

    
    return 0;
}