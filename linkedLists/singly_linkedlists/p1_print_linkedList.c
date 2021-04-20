// This program creates 3 linkedlist nodes, connect them and print the data values
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void print_list(int **head_ref){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = *head_ref;
    
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 6;
    head->next = second;
    
    second->data = 7;
    second->next = third;
    
    third->data = 8;
    third->next = NULL;
    
    print_list(&head);
    
    return 0;
}