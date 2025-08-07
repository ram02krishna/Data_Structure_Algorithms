
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void linkedlisttraversal(struct node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is FULL!\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct node *ptr;
    if (f == NULL)
    {
        printf("Queue is EMPTY!\n");
    }
    else
    {
        ptr = f;
        f = f->next;
        val = ptr->data;
        free(ptr);
        if (f == NULL)
        {
            r = NULL; // Update rear pointer if queue becomes empty
        }
    }
    return val;
}

int main()
{
    linkedlisttraversal(f);
    printf("Dequeuing element : %d \n",dequeue());
    printf("\n");
    enqueue(34);
    enqueue(45);
    enqueue(4);
    enqueue(17);
    printf("Dequeuing element : %d \n", dequeue());
    printf("Dequeuing element : %d \n", dequeue());
    linkedlisttraversal(f);
    return 0;
}
