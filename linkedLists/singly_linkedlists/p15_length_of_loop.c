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

//length of loop
void length_of_loop(struct Node *head){
    
    
    int flag=1;
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
    
    while(fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr){
            printf("loop is detected\n");
            flag = 0;
            break;
        }
    }
    if (flag){
        printf("loop is not detected\n");
        return;
    }

    int loop_length=1;    
    struct Node *temp = slow_ptr->next;
    while(slow_ptr!=temp){
        temp=temp->next;
        loop_length++;
    }
    printf("Length of the loop is %d",loop_length);
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

    head->next->next->next->next->next->next=head;
    length_of_loop(head);
    
    return 0;
}