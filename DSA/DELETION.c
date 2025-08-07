#include<stdio.h>

//Function for display
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

//Function for deletion
void deletion(int arr[],int size,int index)
{
    for(int i=index;i<size-1;i++)
    {
        arr[i] = arr[i+1];
    }
}

int main()
{
    int arr[100] = {5,6,9,8,7,4,3};
    int size = 7,index = 3;
    display(arr,7);
    deletion(arr,size,index);
    size -= 1;
    display(arr,size);
    return 0;
}