// This program deletes linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

///insert at the begining of the linkedlist
void insert_at_begining(struct Node **head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//delete node at a position
void delete_linkedList(struct Node **head_ref){

    if((*head_ref) == NULL){
        printf("Linked List is empty");
        return;
    }

    struct Node* temp;
    while((*head_ref)!=NULL){
        temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
    }
    *head_ref = NULL;
}


//print
void print_list(struct Node *temp){
    
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    
    struct Node* head = NULL;

    printf("\nList before deleting:\n");
    insert_at_begining(&head, 34);
    insert_at_begining(&head, 16);
    insert_at_begining(&head, 17);
    
    print_list(head);
    printf("\nList after deleting:\n");
    delete_linkedList(&head);
    print_list(head);
    
    return 0;
}