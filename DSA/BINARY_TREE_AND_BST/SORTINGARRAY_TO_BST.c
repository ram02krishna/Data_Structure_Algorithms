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

// Function to convert a sorted array to a BST
struct TreeNode* sortedArrayToBST(int* nums, int left, int right) {
    if (left > right) return NULL;
    
    int mid = (left + right) / 2;
    struct TreeNode* root = newNode(nums[mid]);
    
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);
    
    return root;
}

// Function to print inorder traversal of BST
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    struct TreeNode* root = sortedArrayToBST(nums, 0, n - 1);
    
    printf("Inorder Traversal of constructed BST: ");
    inorderTraversal(root);
    
    return 0;
}
