/*
The program implements Binary Search Tree with Breadth First Search traversal
*/

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 100

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

struct Node** CreateQueue(int *front, int *rear){

    struct Node** queue = (struct Node**)malloc(sizeof(struct ode*)*QUEUE_SIZE);
    *front = *rear = 0;

    return queue;
}

void enqueue(struct Node** queue, int *rear, struct Node* new_node){

    queue[*rear] = new_node;
    (*rear)++;
}

struct Node* dequeue(struct Node** queue, int *front){

    (*front)++;
    return queue[*front -1];
}


void Level_order_traversal(struct Node* root){

    int front, rear;

    struct Node** queue = CreateQueue(&front, &rear);
    struct Node* temp = root;

    while(temp){
        printf("%d\n", temp->data);

        if(temp->left){
            enqueue(queue, &rear, temp->left);
        }

        if(temp->right){
            enqueue(queue, &rear, temp->right);
        }

        temp = dequeue(queue, &front);
    }
}

//insert node for BST
struct Node*  InsertNode(struct Node* root, int data){
    if (root == NULL){
        return create_node(data);
    }

    if (data<=root->data){
        root->left = InsertNode(root->left, data);
    }
    else if (data>root->data){
        root->right = InsertNode(root->right, data);
    }

    return root;
}

struct Node* Search(struct Node* root, int key){
    if (root == NULL){
        printf("%d is not found", key);
        return root;
    }

    if (root->data == key)
        return root;

    if(key<root->data)
        return Search(root->left, key);
    return Search(root->right, key);
}




int main()
{
    struct Node *root = create_node(3);
    InsertNode(root, 1);
    InsertNode(root, 2);
    InsertNode(root, 4);
    InsertNode(root, 5);


    printf("Level Order traversal of binary tree is \n");
    Level_order_traversal(root);

    if(Search(root, 33)){
     printf("found!");
    }


    return 0;
}
