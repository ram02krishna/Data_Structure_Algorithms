#include <stdio.h>

#define MAX 100

typedef struct
{
    int row;
    int col;
    int value;
} SparseMatrix;

void printSparseMatrix(SparseMatrix sparse[], int size)
{
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int addSparseMatrices(SparseMatrix mat1[], int size1, SparseMatrix mat2[], int size2, SparseMatrix result[])
{
    int i = 1, j = 1, k = 1;

    // First row of result stores the dimensions and total non-zero count
    result[0].row = mat1[0].row;
    result[0].col = mat1[0].col;

    while (i < size1 && j < size2)
    {
        if (mat1[i].row == mat2[j].row && mat1[i].col == mat2[j].col)
        {
            result[k].row = mat1[i].row;
            result[k].col = mat1[i].col;
            result[k].value = mat1[i].value + mat2[j].value;
            i++;
            j++;
            k++;
        }
        else if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col))
        {
            result[k] = mat1[i];
            i++;
            k++;
        }
        else
        {
            result[k] = mat2[j];
            j++;
            k++;
        }
    }

    // Add remaining elements from mat1
    while (i < size1)
    {
        result[k] = mat1[i];
        i++;
        k++;
    }

    // Add remaining elements from mat2
    while (j < size2)
    {
        result[k] = mat2[j];
        j++;
        k++;
    }

    result[0].value = k - 1; // Total number of non-zero elements
    return k;                // Return the size of the result
}

int main()
{
    SparseMatrix mat1[MAX], mat2[MAX], result[MAX];
    int size1, size2, size3;

    // Input Sparse Matrix 1
    printf("Enter number of rows, columns, and non-zero elements of Matrix 1:\n");
    scanf("%d %d %d", &mat1[0].row, &mat1[0].col, &mat1[0].value);
    size1 = mat1[0].value + 1;

    printf("Enter row, column, and value of each non-zero element of Matrix 1:\n");
    for (int i = 1; i < size1; i++)
    {
        scanf("%d %d %d", &mat1[i].row, &mat1[i].col, &mat1[i].value);
    }

    // Input Sparse Matrix 2
    printf("Enter number of rows, columns, and non-zero elements of Matrix 2:\n");
    scanf("%d %d %d", &mat2[0].row, &mat2[0].col, &mat2[0].value);
    size2 = mat2[0].value + 1;

    printf("Enter row, column, and value of each non-zero element of Matrix 2:\n");
    for (int i = 1; i < size2; i++)
    {
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].value);
    }

    // Add Sparse Matrices
    if (mat1[0].row == mat2[0].row && mat1[0].col == mat2[0].col)
    {
        size3 = addSparseMatrices(mat1, size1, mat2, size2, result);
        printf("Resultant Sparse Matrix:\n");
        printSparseMatrix(result, size3);
    }
    else
    {
        printf("Matrix addition not possible. Dimensions do not match.\n");
    }

    return 0;
}

/*
Input -->
Enter number of rows, columns, and non-zero elements of Matrix 1:
3 3 3
Enter row, column, and value of each non-zero element of Matrix 1:
0 0 5
0 2 8
2 2 6
Enter number of rows, columns, and non-zero elements of Matrix 2:
3 3 2
Enter row, column, and value of each non-zero element of Matrix 2:
0 1 4
2 2 7


Output -->
Resultant Sparse Matrix:
Row     Col     Value
3       3       4
0       0       5
0       1       4
0       2       8
2       2       13
    
*/