#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void doublelinkedlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Create node in the doubly linked list
// we can use temp or ptr.
struct node *addtoempty(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node *insertatbeginning(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

struct node *insertatindex(struct node *head, int data, int index)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    struct node *q = NULL;
    temp = addtoempty(temp, data);
    while (index != 1)
    {
        p = p->next;
        index--;
    }
    q = p->next;
    p->next = temp;
    q->prev = temp;
    temp -> next = q;
    temp -> prev = p;
    return head;
}

struct node *insertatend(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
    return head;
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head = addtoempty(head, 60);
    head = insertatbeginning(head, 25);
    head = insertatbeginning(head, 34);
    head = insertatbeginning(head, 67);
    head = insertatend(head, 15);
    head = insertatend(head, 56);
    head = insertatindex(head, 37, 4);
    doublelinkedlist(head);
    return 0;
}