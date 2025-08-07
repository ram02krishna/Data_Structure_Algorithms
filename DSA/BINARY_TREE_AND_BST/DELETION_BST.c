#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the inorder successor
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with given key from BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) 
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->val = temp->val;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Function to print the binary tree in inorder traversal
void printInorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

int main() {
    // Constructing the binary search tree
    struct TreeNode* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    // Print original tree
    printf("Original Tree (Inorder traversal): ");
    printInorder(root);
    printf("\n");

    // Delete node with key 30
    root = deleteNode(root, 30);

    // Print tree after deletion
    printf("Tree after deleting node with key 30 (Inorder traversal): ");
    printInorder(root);
    printf("\n");

    return 0;
}
