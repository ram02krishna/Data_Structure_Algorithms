#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetricHelper(struct TreeNode *leftSubtree, struct TreeNode *rightSubtree) {
    // If both subtrees are empty, they are symmetric
    if (leftSubtree == NULL && rightSubtree == NULL)
        return true;

    // If one subtree is empty and the other is not, they are not symmetric
    if (leftSubtree == NULL || rightSubtree == NULL)
        return false;

    // If values at current nodes are different, they are not symmetric
    if (leftSubtree->val != rightSubtree->val)
        return false;

    // Recursively check if left subtree's left is symmetric to right subtree's right
    // and left subtree's right is symmetric to right subtree's left
    return isSymmetricHelper(leftSubtree->left, rightSubtree->right) &&
           isSymmetricHelper(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(struct TreeNode *root) {
    if (root == NULL)
        return true;

    // Call helper function to check symmetry of left and right subtrees
    return isSymmetricHelper(root->left, root->right);
}

// Utility function to create a new tree node
struct TreeNode* createNode(int data){
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (node != NULL) {
        node->val = data;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

int main() {
    
    // Constructing a symmetric tree
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    // Checking if the tree is symmetric
    if (isSymmetric(root))
        printf("The tree is symmetric.\n");
    else
        printf("The tree is not symmetric.\n");

    // Free memory allocated for the tree nodes
    // Add additional code to free all nodes in the tree

    return 0;
}
