// Given a linked list, check if the linked list has loop or not.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node{
    int data;
    struct Node* next;
};

//insert at the begining of the linkedlist
void insert_at_begining(struct Node **head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//detect loop using slow pointer and fast pointer
bool detect_loop(struct Node *head){
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;
    
    while(fast_ptr && fast_ptr->next){
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
        if (slow_ptr==fast_ptr){
            return true;
        }
    }
    
    return false;
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
    head->next->next->next->next->next->next = head;
    //print_list(head);

    (detect_loop(head)) ? printf("Loop is detected") : printf("There is no loop detected"); 
    return 0;
}