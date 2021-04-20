// This program deletes a node at a position of the linked list
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
void delete_node_at_pos(struct Node **head_ref, int pos){
    int count=0;
    struct Node* current;
    struct Node* prev;
    current = (*head_ref);
    
    if((current != NULL)&&(pos == 0)){
        (*head_ref) = current->next;
        free(current);
        return;
    }
    
    while((current!=NULL)&&(count != pos)){
        count++;
        prev = current;
        current = current->next;
    }
    //if pos to delete is not present in linkedlist
    if (current==NULL){
        printf("Length of the list is less than position\n");
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
    delete_node_at_pos(&head, 3);
    print_list(head);
    
    return 0;
}