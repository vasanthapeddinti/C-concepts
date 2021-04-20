// This program inserts node in the middle of the linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

///insert in the mid of the linkedlist after a given node
void insert_mid(struct Node* prev_node, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    if (prev_node == NULL){
        printf("The given node is not present.");
        return;
    }

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

//print
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
    
    
    insert_mid(second, 45);
    insert_mid(second, 60);
    printf("new list is:\n");
    print_list(&head);
    
    return 0;
}