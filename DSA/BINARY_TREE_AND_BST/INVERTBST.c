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

// Function to invert a binary tree
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;

    // Swap left and right subtrees recursively
    struct TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

// Function to print the binary tree in inorder traversal
void Inorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->val);
    Inorder(root->right);
}

int main() {
    // Constructing the binary tree
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(9);

    // Print original tree
    printf("Original Tree (Inorder traversal): ");
    Inorder(root);
    printf("\n");

    // Invert the binary tree
    root = invertTree(root);

    // Print inverted tree
    printf("Inverted Tree (Inorder traversal): ");
    Inorder(root);
    printf("\n");

    return 0;
}
