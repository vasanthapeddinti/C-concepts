// get nth node in linked list
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

//get nth node
void get_n_node(struct Node *head, int n){
        if (head == NULL){
            return;
        }
        
        int count=0;
        struct Node *current;
        current = head;
        
        while(current!=NULL){
            if(n==count){
                printf("Position %d has data: %d",n,current->data);
                return;
            }
            count++;
            current = current->next;
        }
        printf("%d is greater than the length of the linked list",n);
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
    insert_at_begining(&head, 34);
    insert_at_begining(&head, 16);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 14);
    insert_at_begining(&head, 15);
    insert_at_begining(&head, 6);
    insert_at_begining(&head, 17);
    
    print_list(head);

    get_n_node(head, 2);
    return 0;
}