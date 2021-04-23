// Remove duplicates from a sorted linked list

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

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void last_first_swap(struct Node* head)
{
    struct Node* last = head;
  
    while (last->next != NULL) {
        last = last->next;
    }
    swap(&head->data, &last->data);
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
    insert_at_begining(&head, 15);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 15);
    insert_at_begining(&head, 17);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 17);
    print_list(head);
    printf("After last and first elements's swap:\n");
    last_first_swap(head);
    print_list(head);

    return 0;
}