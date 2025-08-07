#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *left;  // Pointer to the left child
    struct Node *right; // Pointer to the right child
} Node;

// Function prototypes
Node *createNode(int data);
void insert(Node **root, int data);
void inorder(Node *root);
Node *search(Node *root, int data);

int main()
{
    Node *root = NULL; // Initialize the root of the BST

    // Insert elements into the BST
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 20);
    insert(&root, 8);
    insert(&root, 30);

    // Inorder traversal
    printf("Inorder traversal (incremented by 1): ");
    inorder(root);
    printf("\n");

    // Search for an element
    int searchValue = 8;
    Node *foundNode = search(root, searchValue);
    if (foundNode)
    {
        printf("Element %d found in the BST.\n", foundNode->data);
    }
    else
    {
        printf("Element %d not found in the BST.\n", searchValue);
    }

    return 0;
}

// Create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new value into the BST
void insert(Node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data); // If tree is empty, create a new node
    }
    else if (data < (*root)->data)
    {
        insert(&(*root)->left, data); // Insert into the left subtree
    }
    else if (data > (*root)->data)
    {
        insert(&(*root)->right, data); // Insert into the right subtree
    }
}

// Inorder traversal of the BST
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);            // Visit left subtree
        printf("%d, ", root->data + 1); // Increment and print the node's value
        inorder(root->right);           // Visit right subtree
    }
}

// Search for a value in the BST
Node *search(Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root; // Return the node if found or NULL if not found
    }
    if (data < root->data)
    {
        return search(root->left, data); // Search in the left subtree
    }
    return search(root->right, data); // Search in the right subtree
}
