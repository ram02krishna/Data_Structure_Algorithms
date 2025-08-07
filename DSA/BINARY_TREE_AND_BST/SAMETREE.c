#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int data)
{
    struct TreeNode *n;                                     // creating a node pointer
    n = (struct TreeNode *)malloc(sizeof(struct TreeNode)); // Allocating memory in the heap
    n->val = data;                                          // Setting the data
    n->left = NULL;                                         // Setting the left child to NULL
    n->right = NULL;                                        // Setting the right child to NULL
    return n;                                               // Finally returning the created node
}

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    // If both trees are empty, they are same
    if (p == NULL && q == NULL)
        return true;

    // If one tree is empty and the other is not, they are not the same
    if (p == NULL || q == NULL)
        return false;

    // Check if values are same and recursively check left and right subtrees
    return (p->val == q->val) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main()
{
    // Example usage

    // Constructing the root node - Using Function (Recommended)
    struct TreeNode *p = createNode(5);
    struct TreeNode *p1 = createNode(3);
    struct TreeNode *p2 = createNode(6);
    struct TreeNode *p3 = createNode(1);
    struct TreeNode *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct TreeNode *r = createNode(5);
    struct TreeNode *r1 = createNode(3);
    struct TreeNode *r2 = createNode(7);
    struct TreeNode *r3 = createNode(5);
    struct TreeNode *r4 = createNode(4);

    // Linking the root node with left and right children
    r->left = r1;
    r->right = r2;
    r1->left = r3;
    r1->right = r4;

    // Check if p and r are same tree or not
    if (isSameTree(p, r))
        printf("Tree 1 and Tree 2 are the same.\n");
    else
        printf("Tree 1 and Tree 2 are not the same.\n");

    return 0;
}
