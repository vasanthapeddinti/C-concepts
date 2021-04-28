// Depth First Search Traversal

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create_node(int key){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return (new_node);
}

//Pre-order traversal (D L R)
void print_preorder(struct Node *node){
    
    if (node == NULL)
        return;
    printf("%d\t",node->data);
    print_preorder(node->left);
    print_preorder(node->right);
    
}

//inorder traversal (L D R)
void print_inorder(struct Node *node){

    if (node == NULL)
        return;
    print_inorder(node->left);
    printf("%d\t", node->data);
    print_inorder(node->right);
    
}

//post order traversal (L R D)
void print_postorder(struct Node *node){
    
    if (node == NULL)
        return;
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d\t",node->data);
    
}

int main() {
    
    struct Node *root;
    
    //creating a binary tree
    root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);
    

    printf("Pre-order traversal of the binary tree is:\n");
    print_preorder(root);
    
    printf("\nIn-order traversal of the binary tree is:\n");
    print_inorder(root);
    
    printf("\nPost-order traversal of the binary tree is:\n");
    print_postorder(root);
    
    
    return 0;
}