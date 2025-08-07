#include<stdio.h>

//Function for display
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//Function for insertion 
int indInsertion(int arr[],int size,int element,int capacity,int index)
{
    if(size>=capacity)
    {
        return -1;
    }
    for(int i=size-1; i>=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {1,2,60,27,88};
    int size = 5, element = 45, index=3;
    display(arr,5);
    indInsertion(arr,size,element,100,index);
    size+=1;
    display(arr,size);

    return 0;
}