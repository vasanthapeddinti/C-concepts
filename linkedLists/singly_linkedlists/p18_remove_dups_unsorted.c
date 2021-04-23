// Remove duplicates from a unsorted linked list
// below code has order of n^2
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
    struct Node *temp1=head;
    struct Node *temp2;
    struct Node *dup;
    
    while(temp1!=NULL && temp1->next!=NULL){
        temp2=temp1;
        while(temp2->next!=NULL){
            if(temp1->data == temp2->next->data){
                dup = temp2->next;
                temp2->next = temp2->next->next;
                free(dup);
            }
            else{
                temp2=temp2->next;
            }
        }//inner while loop
        temp1 = temp1->next;
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
    insert_at_begining(&head, 33);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 15);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 15);
    insert_at_begining(&head, 15);
    insert_at_begining(&head, 17);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 17);
    print_list(head);
    printf("After removing dupliactes:\n");
    remove_duplicates(head);
    print_list(head);

    return 0;
}