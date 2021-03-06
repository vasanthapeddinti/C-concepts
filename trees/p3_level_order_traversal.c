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

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*)*QUEUE_SIZE);
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



int main()
{
    struct Node *root = create_node(1);
    root->left        = create_node(2);
    root->right       = create_node(3);
    root->left->left  = create_node(4);
    root->left->right = create_node(5);

    printf("Level Order traversal of binary tree is \n");
    Level_order_traversal(root);

    return 0;
}
