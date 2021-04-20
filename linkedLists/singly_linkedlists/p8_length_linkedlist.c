// This program calculates the length of the linkedlist
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


//print
int Length_of_LinkedList(struct Node *temp){
    
    int length=0;
    
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    return (length);
}

int main() {
    
    struct Node* head = NULL;

    printf("\nLinked List:\n");
    insert_at_begining(&head, 34);
    insert_at_begining(&head, 16);
    insert_at_begining(&head, 17);
    insert_at_begining(&head, 17);
    insert_at_begining(&head, 17);
    insert_at_begining(&head, 17);
    
    printf("Length of the Linked List is %d", Length_of_LinkedList(head));
    return 0;
}