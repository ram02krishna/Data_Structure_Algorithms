#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));
    int left = low;
    int right = mid + 1;
    int k = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }

    while (right <= high)
    {
        temp[k++] = arr[right++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    free(temp);
}

void mS(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mS(arr, low, mid);
    mS(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void mergeSort(int arr[], int n)
{
    mS(arr, 0, n - 1);
}

int main()
{
    int n;
    printf("Enter the size of the array: \n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}