#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Linked List node
typedef struct Node
{
    int value;
    struct Node *next;
} Node;

// Function to print the array
void Print(int *vec, int n, const char *Array)
{
    printf("%s: [", Array);
    for (int i = 0; i < n; i++)
    {
        printf("%d", vec[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to find the maximum element in the array
int Max(int A[], int n)
{
    // int max = A[0]; //or
    int max = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

// Function to insert a value into the bin (linked list)
void Insert(Node **ptrBins, int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;

    if (ptrBins[value] == NULL)
    { // ptrBins[value] is the head pointer
        ptrBins[value] = temp;
    }
    else
    {
        Node *p = ptrBins[value];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

// Function to delete a node from the bin and return its value
int Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx]; // ptrBins[idx] is the head pointer
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    free(p);
    return x;
}

// Function to perform Bin Sort
void BinSort(int A[], int n)
{
    int max = Max(A, n);

    // Create bins array
    Node **bins = (Node **)malloc((max + 1) * sizeof(Node *));

    // Initialize bins array with NULL
    for (int i = 0; i < max + 1; i++)
    {
        bins[i] = NULL;
    }

    // Insert elements into the bins
    for (int i = 0; i < n; i++)
    {
        Insert(bins, A[i]);
    }

    // Collect sorted elements from the bins back into the array
    int i = 0;
    int j = 0;
    while (i < max + 1)  // Can use for loop also
    {
        while (bins[i] != NULL)
        {
            A[j++] = Delete(bins, i);
        }
        i++;
    }

    // Free allocated memory for bins
    free(bins);
}

int main()
{
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A) / sizeof(A[0]);

    Print(A, n, "A");
    BinSort(A, n);
    Print(A, n, "Sorted A");
    printf("\n");

    return 0;
}
