#include <stdio.h>
#include <stdlib.h>

// Function to insert an element into an array (max heap insertion)
void InsertA(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2])
    {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

// Function to print an array (for heap visualization)
void Print(int *arr, int n)
{
    printf("Max Heap: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50}; // Predefined array
    int n = sizeof(a) / sizeof(a[0]);                 // Get the size of the array

    // Insert element 50 into the max heap
    InsertA(a, 9);

    // Print the array as a max heap
    Print(a, n);

    return 0;
}
