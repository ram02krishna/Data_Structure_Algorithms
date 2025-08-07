#include<stdio.h>

// FUNCTION FOR LINEARSEARCH
int linearsearch(int arr[],int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {4,6,7,9,21,16,17,13,11,8,19,35,29};
    int size = sizeof(arr)/sizeof(int);
    //int size = sizeof(arr)/sizeof(arr[0]);
    int element;
    printf("Enter the element u want to search : \n");
    scanf("%d",&element);
    int searchindex = linearsearch(arr,size,element);
    printf("The element %d was found at index %d",element,searchindex);
    return 0;
}