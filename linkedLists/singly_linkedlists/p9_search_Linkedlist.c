// Search a key in linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

//search node 
bool serach_linkedList(struct Node **head_ref, int key){
    
    struct Node* temp = *head_ref;
    
    while(temp!=NULL){

        if (key == temp->data)
            return true;
        temp=temp->next;
    }
    printf("The key is not found\n");
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
    insert_at_begining(&head, 34);
    insert_at_begining(&head, 16);
    insert_at_begining(&head, 17);
    
    print_list(head);

    if(serach_linkedList(&head, 4))
        printf("true");
    else
        printf("false");

    
    return 0;
}