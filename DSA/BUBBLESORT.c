// Analysis criteria for sorting algorithm
/*1.Time complexity : how much time is taken in getting output
2.space complexity : inplace sorting algorithm(space must not increase with time)
3.stability
4.Internal sorting algorithm : all the data is loaded into the memory
External sorting algorithm : all the data is not loaded into the memory
5.Adaptive : already sorted data takes less time
6.Recursive/non recursive sorting algorithm : Recursive if it uses recursion.
*/

#include<stdio.h>

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void bubblesort(int arr[],int size)
{
    for(int i=0;i<size-1;i++) // for no. of passes
    {
        for(int j=0;j<size-1-i;j++) // for comparison in each pass
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {5,2,9,7,3,11,6,1,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    printarray(arr,size);
    printf("\n");
    bubblesort(arr,size);
    printf("Sorted array by using bubble sort is : \n");
    printarray(arr,size);
    return 0;
}