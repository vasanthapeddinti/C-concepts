// Remove duplicates from a sorted linked list
/*
Write a function which takes a list sorted in 
non-decreasing order and deletes any duplicate 
nodes from the list. The list should only be 
traversed once. 
*/
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

void remove_duplicates(struct Node *head){
    struct Node *current = head;
    struct Node *current_next;
    
    current_next = current->next;
    while(current_next!=NULL){
        if(current->data == current_next->data){
            current->next = current_next->next;
            free(current_next);
            current_next = current -> next;
        }
        else{
            current = current_next;
            current_next = current->next;
        }
    }
    return;
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

    printf("\nLinked List:\n");
    insert_at_begining(&head, 3);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 15);
    insert_at_begining(&head, 15);
    insert_at_begining(&head, 17);
    insert_at_begining(&head, 17);
    print_list(head);
    printf("After removing dupliactes:\n");
    remove_duplicates(head);
    print_list(head);

    return 0;
}