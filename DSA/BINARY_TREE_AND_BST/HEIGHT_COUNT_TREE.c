#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

// Function for preorder traversal
void preorderTraversal(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d, ", p->data);
        preorderTraversal(p->lchild);
        preorderTraversal(p->rchild);
    }
}

// Function for inorder traversal
void inorderTraversal(struct Node *p)
{
    if (p != NULL)
    {
        inorderTraversal(p->lchild);
        printf("%d, ", p->data);
        inorderTraversal(p->rchild);
    }
}

// Function for postorder traversal
void postorderTraversal(struct Node *p)
{
    if (p != NULL)
    {
        postorderTraversal(p->lchild);
        postorderTraversal(p->rchild);
        printf("%d, ", p->data);
    }
}

// Function to calculate the height of the tree
int height(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int leftHeight = height(p->lchild);
    int rightHeight = height(p->rchild);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to count the total number of nodes
int countNodes(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return countNodes(p->lchild) + countNodes(p->rchild) + 1;
}

// Function to calculate the sum of all node values
int sumOfNodes(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return sumOfNodes(p->lchild) + sumOfNodes(p->rchild) + p->data;
}

// Function to count the number of nodes with two children (degree 2 nodes)
int countDeg2Nodes(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int leftCount = countDeg2Nodes(p->lchild);
    int rightCount = countDeg2Nodes(p->rchild);
    if (p->lchild && p->rchild)
    {
        return leftCount + rightCount + 1;
    }
    return leftCount + rightCount;
}

// Function to build the tree from inorder and preorder arrays
struct Node *buildTree(int inorder[], int preorder[], int inStart, int inEnd, int *preIndex)
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    struct Node *node = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
    {
        return node;
    }

    int splitIndex;
    for (splitIndex = inStart; splitIndex <= inEnd; splitIndex++)
    {
        if (inorder[splitIndex] == node->data)
        {
            break;
        }
    }

    node->lchild = buildTree(inorder, preorder, inStart, splitIndex - 1, preIndex);
    node->rchild = buildTree(inorder, preorder, splitIndex + 1, inEnd, preIndex);

    return node;
}

int main()
{
    int preorderArr[] = {8, 3, 12, 4, 9, 7, 5, 10, 6, 2};
    int inorderArr[] = {12, 9, 4, 7, 3, 8, 10, 5, 2, 6};
    int size = sizeof(inorderArr) / sizeof(inorderArr[0]);

    int preIndex = 0;
    struct Node *root = buildTree(inorderArr, preorderArr, 0, size - 1, &preIndex);

    printf("Preorder: ");
    preorderTraversal(root);
    printf("\nInorder: ");
    inorderTraversal(root);
    printf("\nPostorder: ");
    postorderTraversal(root);

    printf("\nHeight: %d\n", height(root));
    printf("Node Count: %d\n", countNodes(root));
    printf("Sum of Node Values: %d\n", sumOfNodes(root));
    printf("Degree 2 Nodes: %d\n", countDeg2Nodes(root));

    return 0;
}
