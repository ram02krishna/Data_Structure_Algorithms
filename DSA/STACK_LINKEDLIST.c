#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflown\n");
    }
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{
    struct node *top = NULL; // This means linked list is empty,here head is used as top.
    top = push(top, 45);
    top = push(top, 36);
    top = push(top, 69);
    top = push(top, 56);
    linkedlisttraversal(top);
    int element = pop(&top);
    printf("\n");
    printf("popped element is %d \n", element);
    linkedlisttraversal(top);
    return 0;
}