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

// Function to merge two binary trees
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) {
        return NULL;
    } else if (t1 == NULL) {
        return t2;
    } else if (t2 == NULL) {
        return t1;
    } else {
        struct TreeNode* newNode = createNode(t1->val + t2->val);
        newNode->left = mergeTrees(t1->left, t2->left);
        newNode->right = mergeTrees(t1->right, t2->right);
        return newNode;
    }
}

// Function to print the binary tree in preorder traversal
void printPreorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Constructing the first binary tree
    struct TreeNode* t1 = createNode(1);
    t1->left = createNode(3);
    t1->right = createNode(2);
    t1->left->left = createNode(5);

    // Constructing the second binary tree
    struct TreeNode* t2 = createNode(2);
    t2->left = createNode(1);
    t2->right = createNode(3);
    t2->left->right = createNode(4);
    t2->right->right = createNode(7);

    // Merge the two binary trees
    struct TreeNode* mergedTree = mergeTrees(t1, t2);

    // Print the merged tree
    printf("Merged Tree (Preorder traversal): ");
    printPreorder(mergedTree);
    printf("\n");

    return 0;
}
