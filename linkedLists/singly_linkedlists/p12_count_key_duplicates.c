// Write a function that counts the number 
//of times a given int occurs in a Linked List

/*
Given a singly linked list and a key, count number 
of occurrences of given key in linked list. For 
example, if given linked list is 1->2->1->2->1->3->1 
and given key is 1, then output should be 4.
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

void count_key_duplicates(struct Node *head, int key){
    struct Node *current = head;
    int count=0;
    
    if(current == NULL)
        return;
        
    while(current!=NULL){
        if(key == current->data){
            count++;
        }
        current = current->next;
    }
    
    if(count){
        printf("%d key repeated for %d times", key, count);
        return;
    }
    printf("The key %d is not present",key);
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

    count_key_duplicates(head, 15);
    return 0;
}