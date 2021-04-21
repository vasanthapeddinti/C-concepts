//Function to check if a singly linked list is palindrome
/*
1) Get the middle of the linked list. 
2) Reverse the second half of the linked list. 
3) Check if the first half and second half are identical. 
4) Construct the original linked list by reversing the 
second half again and attaching it back to the first half


When number of nodes are even, the first and second half 
contain exactly half nodes. The challenging thing in this 
method is to handle the case when number of nodes are odd. 
We don’t want the middle node as part of any of the lists 
as we are going to compare them for equality. For odd case, 
we use a separate variable ‘midnode’. 
*/

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

void reverse(struct Node **head_ref){
    struct Node *cur = *head_ref;
    struct Node *cur_next = NULL;
    struct Node *prev = NULL;
    
    while(cur!=NULL){
        cur_next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = cur_next;
    }
    *head_ref = prev;
}

bool compare(struct Node* head1, struct Node* head2)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
 
    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }
    
    if (temp1 == NULL && temp2 == NULL)
        return 1;
 
    return 0;
}

//length of loop
void check_palindrome(struct Node *head){

    bool res;
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
    struct Node *prev_slow_ptr;
    
    //go to  mid element
    while(fast_ptr!=NULL && fast_ptr->next!=NULL){
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    
    struct Node *second_half;
    //only for odd length
    struct Node *mid_node=NULL;
    
    if(fast_ptr!=NULL){
        mid_node = slow_ptr;
        second_half = slow_ptr->next;
    }
    else{
        second_half = slow_ptr;
    }
    prev_slow_ptr->next=NULL;
    reverse(&second_half);
    res = compare(head, second_half);
    
    reverse(&second_half);
    
    if (mid_node){
        prev_slow_ptr->next = mid_node;
        mid_node->next = second_half;
    }
    else{
        prev_slow_ptr->next = second_half;
    }
    
    if (res){
        printf("Linked list is palindrome\n");
        return;
    }
    else{
        printf("Linked list is not palindrome\n");
        return;
    }
}



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
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 3);
    print_list(head);

    check_palindrome(head);
    print_list(head);
    
    return 0;
}