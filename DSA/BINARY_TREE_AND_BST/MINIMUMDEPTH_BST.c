#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the minimum depth of a binary tree
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    // If left subtree is NULL, consider the depth of the right subtree
    if (root->left == NULL) return rightDepth + 1;
    // If right subtree is NULL, consider the depth of the left subtree
    if (root->right == NULL) return leftDepth + 1;
    
    // Otherwise, return the minimum depth of the two subtrees
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    // Sample binary tree
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    printf("Minimum depth of the binary tree: %d\n", minDepth(root));
    
    return 0;
}
