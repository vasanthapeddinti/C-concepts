//Swap nodes in a linked list without swapping data
/*
    Input : 1->2->3->4->5->6->NULL
    Output : 2->1->4->3->6->5->NULL

    Input : 1->2->3->4->5->NULL
    Output : 2->1->4->3->5->NULL

    Input : 1->NULL
    Output : 1->NULL
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

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void pairwise_swap(struct Node* head)
{
    struct Node* cur = head;
  
    while (cur != NULL && cur->next != NULL) {
        swap(&cur->data, &cur->next->data);
        cur = cur->next->next;
    }
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
    printf("After pairwise swapping:\n");
    pairwise_swap(head);
    print_list(head);

    return 0;
}