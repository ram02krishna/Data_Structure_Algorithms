#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} SparseElement;

void addSparseMatrices(SparseElement A[], int lenA, SparseElement B[], int lenB, SparseElement R[], int *lenR)
{
    int i = 0, j = 0, k = 0;

    while (i < lenA && j < lenB)
    {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
        {
            R[k++] = A[i++];
        }
        else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col))
        {
            R[k++] = B[j++];
        }
        else
        {
            R[k] = A[i];
            R[k++].value = A[i++].value + B[j++].value;
        }
    }

    while (i < lenA)
    {
        R[k++] = A[i++];
    }

    while (j < lenB)
    {
        R[k++] = B[j++];
    }

    *lenR = k;
}

int main()
{
    SparseElement A[] = {{0, 0, 15}, {0, 3, 2}, {0, 4, -15}, {1, 1, 11}};
    SparseElement B[] = {{0, 0, 10}, {0, 3, 3}, {1, 1, 12}, {2, 2, -6}};
    SparseElement R[20];
    int lenR;

    addSparseMatrices(A, 4, B, 4, R, &lenR);

    for (int i = 0; i < lenR; i++)
    {
        printf("(%d, %d, %d)\n", R[i].row, R[i].col, R[i].value);
    }

    return 0;
}
