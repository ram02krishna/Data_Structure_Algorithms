#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Structure for a queue node
struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
};

// Structure for a queue
struct Queue {
    struct QueueNode *f, *r;
};

// Function to create a new queue node
struct QueueNode* createQueueNode(struct TreeNode *node) {
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->f = queue->r = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->f == NULL;
}

// Function to enqueue a tree node
void enqueue(struct Queue *queue, struct TreeNode *node) {
    struct QueueNode *newNode = createQueueNode(node);
    if (isEmpty(queue))
        queue->f = queue->r = newNode;
    else {
        queue->r->next = newNode;
        queue->r = newNode;
    }
}

// Function to dequeue a tree node
struct TreeNode* dequeue(struct Queue *queue) {
    if (isEmpty(queue))
        return NULL;
    struct QueueNode *temp = queue->f;
    struct TreeNode *node = temp->node;
    queue->f = queue->f->next;
    if (queue->f == NULL)
        queue->r = NULL;
    free(temp);
    return node;
}

// Function to find the maximum depth of a binary tree using BFS
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    
    struct Queue *queue = createQueue();
    enqueue(queue, root);
    int depth = 0;
    
    while (!isEmpty(queue)) {
        int levelSize = queue->r - queue->f + 1;
        depth++;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode *node = dequeue(queue);
            if (node->left != NULL)
                enqueue(queue, node->left);
            if (node->right != NULL)
                enqueue(queue, node->right);
        }
    }
    
    free(queue);
    return depth;
}

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Constructing the binary tree
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    root->right->right->left = createNode(8);

    // Finding and printing the maximum depth of the binary tree
    printf("Maximum Depth of the Binary Tree: %d\n", maxDepth(root));

    return 0;
}
