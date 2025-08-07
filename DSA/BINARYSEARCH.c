// Binary search is used for sorted array so that it can take less time.
//for binary seach,array should be sorted only.
#include<stdio.h>

// ITERATIVE METHOD
// FUNCTION FOR BINARYSEARCH
int binarysearch(int arr[],int size,int element)
{
    int low,mid,high;
    low = 0;
    high = size-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        else if(arr[mid]<element)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5,7,9,13,36,45,59,63,71,91,99};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element;
    printf("Enter the element u want to search : \n");
    scanf("%d",&element);
    int searchindex = binarysearch(arr,size,element);
    printf("The element %d is found at the index %d \n",element,searchindex);
    return 0;
}