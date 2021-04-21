// Find the middle of a given linked list
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

//mid element using slow pointer and fast pointer
void mid_element(struct Node *head){
    
    if (head==NULL){
        printf("Empty list is provided");
        return;
    }
    
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;
    
    while((fast_ptr!=NULL) && (fast_ptr->next!=NULL)){
        
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    }
    printf("%d is the mid element",slow_ptr->data);
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
    print_list(head);

    mid_element(head);
    
    return 0;
}