/*
summary of the insertion sort
1.Total passes = n-1 here n is the size of the element 
Total comparison = 1+2+3+4+5....+n-1 = n(n-1)/2 which is O(n^2) for the worst case.
2.Best case = O(n) when array is sorted.
3.Stable : yes it is stable.
4.Adaptive : yes it is adaptive as fayda utha pa rh ahe.
*/

#include<stdio.h>

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void insertionsort(int arr[],int n)
{
    // loop for passes
    for(int i=1;i<n;i++)
    {
        int j,key;
        j = i-1;
        key = arr[i];
        // loop for each pass
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {12,54,65,7,23,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printarray(arr,n);
    printf("\n");
    insertionsort(arr,n);
    printarray(arr,n);
    return 0;
}