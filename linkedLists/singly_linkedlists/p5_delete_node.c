// This program deletes a node in the linked list, if it is present
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

//delete node
void delete_node(struct Node **head_ref, int key){
    struct Node* current;
    struct Node* prev;
    current = (*head_ref);
    
    if((current != NULL)&&(key == current->data)){
        (*head_ref) = current->next;
        free(current);
        return;
    }
    
    while((current!=NULL)&&(key!=current->data)){
        prev = current;
        current = current->next;
    }
    //if data to delete is not present in linkedlist
    if (current==NULL){
        printf("Element to be deleted is not available\n");
        return;
    }
    prev->next = current->next;
    free(current);
    
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
    delete_node(&head, 16);
    print_list(head);
    
    return 0;
}