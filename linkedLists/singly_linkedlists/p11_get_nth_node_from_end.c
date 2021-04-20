// Program for n’th node from the end of a Linked List
/*
We can solve the problem by calculating the total length and 
then subtracting the k length from total. But, this will take 
order of n^2

The other solution is to use two pointer variables. Move the 
first pointer to n nodes from the begining. Then, move the 1st
and 2nd pointers simultaneously. When the first pointer reaches 
the null, second pointer reaches the nth node from the end of the 
linked list. This has the oreder of n
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

//get nth node from the end of the linked list
void get_n_node_from_end(struct Node *head, int index){
    struct Node *main_ptr=head;
    struct Node *ref_ptr = head;
    int count =0;

if(head != NULL)
{
	while( count < index )
    	{
    		if(ref_ptr == NULL)
    		{
    		printf("%d is greater than the no. of "
    					"nodes in list", index);
    		return;
    		}
    		ref_ptr = ref_ptr->next;
    		count++;
    	} //End of while
	if(ref_ptr == NULL)
    	{
    		head = head->next;
    		if(head != NULL)
    			printf("Node no. %d from last is %d ", index, main_ptr->data);
    	}
	else
    	{
    	while(ref_ptr != NULL)
    	{
    		main_ptr = main_ptr->next;
    		ref_ptr = ref_ptr->next;
	    }
	    printf("Node no. %d from last is %d ", index, main_ptr->data);
	    }
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
    insert_at_begining(&head, 34);
    insert_at_begining(&head, 16);
    insert_at_begining(&head, 1);
    insert_at_begining(&head, 14);
    insert_at_begining(&head, 15);
    insert_at_begining(&head, 6);
    insert_at_begining(&head, 17);
    
    print_list(head);

    get_n_node_from_end(head, 2);
    return 0;
}