/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int column;
    int element;
    struct Node *next;
};

void CreateSparseMatrix(struct Node **X){
    int row, col, ele;
    struct Node *p;
    scanf("%d %d %d", &row, &col, &ele);
    if(X[row] == NULL){
        X[row] = (struct Node *) malloc(sizeof(struct Node));
        p = X[row];
        p->column = col;
        p->element = ele;
        p->next = NULL;
    }
    else{
        p = X[row];
        while(p->next != NULL){
            p = p->next;
        }
        struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
        temp->column = col;
        temp->element = ele;
        temp->next = NULL;
        p->next = temp;
    }
}

void DisplaySparseMatrix(struct Node **X, int m, int n){
    for(int i = 0; i < m; i++){
        struct Node *p = X[i];
        for(int j = 0; j < n; j++){
            if(p == NULL){
                printf("0 ");
            }
            else if(j == p->column){
                printf("%d ", p->element);
                if(p->next != NULL)
                    p = p->next;
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    int m, n, x;
    printf("Enter matrix dimensions: ");
    scanf("%d %d", &m, &n);
    printf("Enter total number of non-zero elements: \n");
    scanf("%d", &x);

    struct Node** A = (struct Node **) malloc(m * sizeof(struct Node*));

    // Initialize all pointers to NULL
    for(int i = 0; i < m; i++) {
        A[i] = NULL;
    }

    printf("Enter all non-zero elements:\n");
    for(int i = 1; i <= x; i++){
        printf("Enter row number, column number, and non-zero element: ");
        CreateSparseMatrix(A);
    }

    printf("\nSparse Matrix: \n");
    DisplaySparseMatrix(A, m, n);

    // Free the allocated memory
    for(int i = 0; i < m; i++) {
        struct Node *p = A[i];
        while (p != NULL) {
            struct Node *temp = p;
            p = p->next;
            free(temp);
        }
    }
    free(A);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a non-zero element in the sparse matrix
struct Node
{
    int row;
    int col;
    int value;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int row, int col, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the linked list representing the sparse matrix
struct Node *insert(struct Node *head, int row, int col, int value)
{
    struct Node *newNode = createNode(row, col, value);
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to create a sparse matrix from user input
struct Node *createSparseMatrix(int *rows, int *cols)
{
    int nonZeroElements;
    printf("Enter the number of rows: ");
    scanf("%d", rows);
    printf("Enter the number of columns: ");
    scanf("%d", cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &nonZeroElements);

    struct Node *head = NULL;
    for (int i = 0; i < nonZeroElements; i++)
    {
        int row, col, value;
        printf("Enter row index, column index and value for element %d: ", i + 1);
        scanf("%d %d %d", &row, &col, &value);
        head = insert(head, row, col, value);
    }
    return head;
}

// Function to print the sparse matrix with 0s and non-zero elements
void printMatrix(struct Node *head, int rows, int cols)
{
    struct Node *temp = head;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (temp != NULL && temp->row == i && temp->col == j)
            {
                printf("%d ", temp->value);
                temp = temp->next;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int rows, cols;
    struct Node *sparseMatrix = createSparseMatrix(&rows, &cols);
    printf("The full sparse matrix representation is:\n");
    printMatrix(sparseMatrix, rows, cols);
    return 0;
}
