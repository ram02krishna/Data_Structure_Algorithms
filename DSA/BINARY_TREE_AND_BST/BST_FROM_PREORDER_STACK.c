#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

typedef struct BST
{
    Node *root;
} BST;

BST *createBST()
{
    BST *bst = (BST *)malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *createNode(int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

void iInsert(BST *bst, int key)
{
    Node *t = bst->root;
    Node *p;
    Node *r;

    // root is empty
    if (bst->root == NULL)
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
            return; // Duplicate key
        }
    }

    // Now t points at NULL and r points at insert location
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

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d, ", p->data);
        Inorder(p->rchild);
    }
}

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
    return p; // key == p->data?
}

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

Node *InPre(Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

Node *InSucc(Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

int Height(Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

Node *Delete(Node *p, int key)
{
    Node *q;

    if (p == NULL)
    {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL)
    {
        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

void createFromPreorder(BST *bst, int *pre, int n)
{
    if (n == 0)
        return;

    // Create root node
    int i = 0;
    bst->root = createNode(pre[i++]);

    Node *t;
    Node *p = bst->root;
    Node *stack[n]; // Max size of the stack
    int top = -1;   // Stack pointer

    while (i < n)
    {
        // Left child case
        if (pre[i] < p->data)
        {
            t = createNode(pre[i++]);
            p->lchild = t;
            stack[++top] = p; // Push to stack
            p = t;
        }
        else
        {
            // Right child case
            if (pre[i] > p->data && (top == -1 || pre[i] < stack[top]->data))
            {
                t = createNode(pre[i++]);
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stack[top--]; // Pop from stack
            }
        }
    }
}

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
    Inorder(bst->root);
    printf("\n");

    // Iterative search
    Node *temp = iSearch(bst, 2);
    if (temp != NULL)
    {
        printf("%d\n", temp->data);
    }
    else
    {
        printf("Element not found\n");
    }

    // Recursive search
    temp = rSearch(bst->root, 20);
    if (temp != NULL)
    {
        printf("%d\n", temp->data);
    }
    else
    {
        printf("Element not found\n");
    }

    // Recursive insert
    bst->root = rInsert(bst->root, 50);
    bst->root = rInsert(bst->root, 70);
    bst->root = rInsert(bst->root, 1);
    Inorder(bst->root);
    printf("\n");

    // Inorder predecessor and inorder successor
    BST *bs = createBST();
    iInsert(bs, 5);
    iInsert(bs, 2);
    iInsert(bs, 8);
    iInsert(bs, 7);
    iInsert(bs, 9);
    iInsert(bs, 1);

    temp = InPre(bs->root);
    printf("InPre: %d\n", temp->data);

    temp = InSucc(bs->root);
    printf("InSucc: %d\n", temp->data);

    Inorder(bs->root);
    printf("\n");

    // Delete
    bs->root = Delete(bs->root, 5);
    Inorder(bs->root);
    printf("\n");

    // BST from Preorder traversal
    printf("BST from Preorder: ");
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre) / sizeof(pre[0]);

    BST *b = createBST();
    createFromPreorder(b, pre, n);
    Inorder(b->root);
    printf("\n");

    // Free allocated memory (not shown for simplicity)

    return 0;
}
