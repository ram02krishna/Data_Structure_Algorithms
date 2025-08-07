#include <stdio.h>
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
    int max = A[0];
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
void Insert(Node **ptrBins, int value, int digit)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;

    if (ptrBins[digit] == NULL)
    { // ptrBins[digit] is the head pointer
        ptrBins[digit] = temp;
    }
    else
    {
        Node *p = ptrBins[digit];
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

// Function to perform Radix Sort
void RadixSort(int A[], int n)
{
    int max = Max(A, n);
    int exp = 1; // Initialize exponent to represent the digit position (1, 10, 100, etc.)

    // Create bins array
    Node **bins = (Node **)malloc(10 * sizeof(Node *));

    // Loop over each digit place (1s, 10s, 100s, ...)
    while (max / exp > 0)
    {
        // Initialize bins array with NULL for this digit
        for (int i = 0; i < 10; i++)
        {
            bins[i] = NULL;
        }

        // Insert elements into the bins based on the current digit
        for (int i = 0; i < n; i++)
        {
            int digit = (A[i] / exp) % 10;
            Insert(bins, A[i], digit);
        }

        // Collect sorted elements from the bins back into the array
        int j = 0;
        for (int i = 0; i < 10; i++)
        {
            while (bins[i] != NULL)
            {
                A[j++] = Delete(bins, i);
            }
        }

        // Move to the next digit
        exp *= 10;
    }
<<<<<<< HEAD

=======
>>>>>>> f106316000e140d2ba36ac08784af1c997a1a981
    // Free allocated memory for bins
    free(bins);
}

int main()
{
    int A[] = {170, 145, 75, 790, 802, 324, 292, 66, 349, 458};
    int n = sizeof(A) / sizeof(A[0]);

    Print(A, n, "A");
    RadixSort(A, n);
    Print(A, n, "Sorted A");
    printf("\n");

    return 0;
}
