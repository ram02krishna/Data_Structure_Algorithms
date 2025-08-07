// Selection sort is not stable.
// Selection sort is not adaptive means not useful even if the array is sorted.time complexity will not matters at all.
// sorting in minimum no of swaps by using selection sort.this is the advantage of using selection sort.
#include<stdio.h>

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selectionsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int indexofmin = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[indexofmin])
            {
                indexofmin = j;
            }
            // swap
            int temp = arr[i];
            arr[i] = arr[indexofmin];
            arr[indexofmin] = temp;
        }
    }
}

int main()
{
    int arr[] = {5,6,8,1,2,9,4,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    printarray(arr,n);
    selectionsort(arr,n);
    printf("Array after using selection sort : ");
    printarray(arr,n);
    return 0;
}