#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    struct Node *lchild; // Pointer to left child
    int data;            // Node value
    struct Node *rchild; // Pointer to right child
} Node;

// BST structure
typedef struct
{
    Node *root; // Pointer to root node
} BST;

// Function prototypes
BST *createBST();
Node *createNode(int data);
void iInsert(BST *bst, int key);
void inorder(Node *p);
Node *iSearch(BST *bst, int key);
Node *rInsert(Node *p, int key);
Node *rSearch(Node *p, int key);
Node *deleteNode(Node *p, int key);
int height(Node *p);
Node *inPre(Node *p);
Node *inSucc(Node *p);
void freeTree(Node *p);

int main()
{
    BST *bst = createBST();

    // Iterative insert
    iInsert(bst, 10);
    iInsert(bst, 5);
    iInsert(bst, 20);
    iInsert(bst, 8);
    iInsert(bst, 30);

    // Inorder traversal
    printf("Inorder traversal: ");
    inorder(bst->root);
    printf("\n");

    // Iterative search
    Node *temp = iSearch(bst, 2);
    if (temp != NULL)
    {
        printf("Found: %d\n", temp->data);
    }
    else
    {
        printf("Element not found\n");
    }

    // Recursive search
    temp = rSearch(bst->root, 20);
    if (temp != NULL)
    {
        printf("Found: %d\n", temp->data);
    }
    else
    {
        printf("Element not found\n");
    }

    // Recursive insert
    bst->root = rInsert(bst->root, 50);
    bst->root = rInsert(bst->root, 70);
    bst->root = rInsert(bst->root, 1);
    printf("Inorder after recursive insert: ");
    inorder(bst->root);
    printf("\n");

    // Inorder predecessor and successor
    BST *bs = createBST();
    iInsert(bs, 5);
    iInsert(bs, 2);
    iInsert(bs, 8);
    iInsert(bs, 7);
    iInsert(bs, 9);
    iInsert(bs, 1);

    temp = inPre(bs->root);
    printf("InPre: %d\n", temp->data);

    temp = inSucc(bs->root);
    printf("InSucc: %d\n", temp->data);

    printf("Inorder of bs: ");
    inorder(bs->root);
    printf("\n");

    // Delete
    bs->root = deleteNode(bs->root, 7);
    printf("Inorder after deleting 7: ");
    inorder(bs->root);
    printf("\n");

    // Free allocated memory
    freeTree(bst->root);
    free(bst);
    freeTree(bs->root);
    free(bs);

    return 0;
}

// Create a new BST
BST *createBST()
{
    BST *bst = (BST *)malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

// Create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// Iterative insert
void iInsert(BST *bst, int key)
{
    Node *t = bst->root;
    Node *p;
    Node *r = NULL;

    // If tree is empty
    if (t == NULL)
    {
        bst->root = createNode(key);
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return; // Key already exists
        }
    }

    // Create a new node
    p = createNode(key);
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

// Inorder traversal
void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d, ", p->data);
        inorder(p->rchild);
    }
}

// Iterative search
Node *iSearch(BST *bst, int key)
{
    Node *t = bst->root;
    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

// Recursive insert
Node *rInsert(Node *p, int key)
{
    if (p == NULL)
    {
        return createNode(key);
    }

    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }
    return p; // Key already exists
}

// Recursive search
Node *rSearch(Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (key == p->data)
    {
        return p;
    }
    else if (key < p->data)
    {
        return rSearch(p->lchild, key);
    }
    else
    {
        return rSearch(p->rchild, key);
    }
}

// Delete a node
Node *deleteNode(Node *p, int key)
{
    Node *q;

    if (p == NULL)
    {
        return NULL; // Key not found
    }

    if (key < p->data)
    {
        p->lchild = deleteNode(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = deleteNode(p->rchild, key);
    }
    else
    {
        // Node to be deleted found
        if (p->lchild == NULL && p->rchild == NULL)
        {
            free(p);
            return NULL; // No children
        }
        else if (p->lchild == NULL)
        {
            Node *temp = p->rchild;
            free(p);
            return temp; // One child (right)
        }
        else if (p->rchild == NULL)
        {
            Node *temp = p->lchild;
            free(p);
            return temp; // One child (left)
        }
        else
        {
            // Node with two children
            q = inPre(p->lchild);
            p->data = q->data; // Replace with inorder predecessor
            p->lchild = deleteNode(p->lchild, q->data);
        }
    }
    return p;
}

// Get the height of the tree
int height(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int x = height(p->lchild);
    int y = height(p->rchild);
    return (x > y ? x : y) + 1;
}

// Get the inorder predecessor
Node *inPre(Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

// Get the inorder successor
Node *inSucc(Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

// Free allocated memory
void freeTree(Node *p)
{
    if (p)
    {
        freeTree(p->lchild);
        freeTree(p->rchild);
        free(p);
    }
}
