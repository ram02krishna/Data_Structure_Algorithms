// properties of Binary search tree or to know whether it is binary tree or not
// 1. All nodes of the left subtree are lesser.
// 3.Left and right subtrees are also BST
// 2. All nodes of the right subtree are greater.
// 4. There are no duplicate nodes.
// 5. Inorder traversal of a BST gives an ascending sorted array.

// create tree using linked list.
/*
#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n; // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // setting the data
    n->left = NULL; // setting the left and right children to NULL
   n->right = NULL; // setting the left and right children to NULL
    return n;
}

int main()
{
    // Constructing the root node - using Function(recommended)
    struct node *p = createnode(5);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(3);

    // linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    return 0;
}
*/

// traversal in a binary tree.
// preorder traversal
// postorder traversal
// Inorder traversal

#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left and right children to NULL
    n->right = NULL;                                // setting the left and right children to NULL
    return n;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
        {
            return 1;
        }
}

int main()
{
    // Constructing the root node - using Function(recommended)
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);


    struct node *r = createnode(5);
    struct node *r1 = createnode(3);
    struct node *r2 = createnode(2);
    struct node *r3 = createnode(1);
    struct node *r4 = createnode(4);

    // linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    r->left = r1;
    r->right = r2;
    r1->left = r3;
    r1->right = r4;

    // preorder(p);
    // printf("\n");
    // postorder(p);
    // printf("\n");
    // inorder(p);

    inorder(p);
    printf("\n");
    printf("%d \n",isBST(p));

    inorder(r);
    printf("\n");
    printf("%d \n",isBST(r));

    return 0;
}