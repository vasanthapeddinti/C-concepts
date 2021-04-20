// This program inserts node at the begining of the linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

///insert at the begining of the linkedlist
void insert_at_begining(int **head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
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
    
    insert_at_begining(&head, 66);
    insert_at_begining(&head, 789);
    
    printf("new list is:\n");
    print_list(&head);
    
    return 0;
}