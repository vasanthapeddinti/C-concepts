// Basic Tree Program

#include <stdio.h>
#include <stdlib.h>

//node declaration
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

//a function to create new node which has a 
//return type of structure to pinter variable
struct Node* new_node(int key){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->left=NULL;
    node->right=NULL;
    
    return node;
}

int main() {
    
    struct Node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);


    return 0;
}