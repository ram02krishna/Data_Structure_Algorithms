#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findMax(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void count_sort(int A[], int n)
{
    int max = findMax(A, n);
    int *C = (int *)malloc((max + 1) * sizeof(int));

    for (int i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        C[A[i]]++;
    }

    int j = 0;
    for (int i = 0; i < max+1; i++)
    {
        while (C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
    }

    free(C);
}

int main()
{
    int A[] = {4, 7, 6, 7, 3, 2, 9, 11, 13};
    int n = sizeof(A) / sizeof(A[0]); 

    count_sort(A, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
