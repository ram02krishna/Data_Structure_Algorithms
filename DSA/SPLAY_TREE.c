#include <stdio.h>
#include <stdlib.h>

// Node structure for Splay Tree
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node
Node *createNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Right rotate
Node *rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotate
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation
Node *splay(Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }

    // Zig -> Right Rotation (In this the right rotation is being performed on the parent of the child as root does not have grandparent.)
    // Zag -> Left Rotation (In this the left rotation is being performed on the parent of the child as root does not have grandparent.)

    // Zig Zig -> Two times right rotations are being performed,First right rotation on the grandparent of the chid and second right rotation on the parent of the child
    // Zag Zag -> Two times left rotations are being performed,First left rotation on the grandparent of the chid and second left rotation on the parent of the child

    // Zig Zag -> One time right rotation and other time left rotation,First Zig(Right) rotation on the parent of the root and secondly, Zag(Left) rotation on the grand parent of the root
    // Zag Zig -> One time left rotation and other time right rotation,First Zag(Left) rotation on the parent of the root and secondly, Zig(Right) rotation on the grand parent of the root

    // Key lies in the left subtree
    if (key < root->key)
    {
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key)
        {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key lies in the right subtree
    else
    {
        if (root->right == NULL)
            return root;

        // Zag-Zig (Right Left)
        if (key < root->right->key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (key > root->right->key)
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Insert operation
Node *insert(Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    root = splay(root, key);

    if (root->key == key)
        return root; // Key already exists

    Node *newNode = createNode(key);
    if (key < root->key)
    {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    }
    else
    {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }
    return newNode;
}

// Delete operation using top-down approach
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    root = splay(root, key);

    // If key is not found, return the current tree
    if (root->key != key)
        return root;

    Node *temp;
    if (root->left == NULL)
    {
        temp = root->right;
    }
    else
    {
        // Splay the largest node in the left subtree to the root
        temp = splay(root->left, key);
        temp->right = root->right;
    }

    free(root);
    return temp;
}

// Preorder traversal
void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Main function
int main()
{
    Node *root = NULL;

    // Insert keys
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder traversal of the splay tree:\n");
    preorder(root);
    printf("\n");

    // Delete key
    printf("Deleting key 20...\n");
    root = deleteNode(root, 20);
    printf("Preorder traversal after deletion:\n");
    preorder(root);
    printf("\n");

    // Delete another key
    printf("Deleting key 30...\n");
    root = deleteNode(root, 30);
    printf("Preorder traversal after deletion:\n");
    preorder(root);
    printf("\n");

    return 0;
}
