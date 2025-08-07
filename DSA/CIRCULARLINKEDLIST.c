// Create a node in circular singly linked list by using function
/*
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
 struct node *circularsingly(int data)
 {
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    return temp;
 }

 int main()
 {
    int data = 34;
    struct node *tail;
    tail = circularsingly(data);

    printf("%d\n", tail -> data);
    return 0;
 }
 */



// Circular linked list
/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *head)
{
    // struct node *ptr = head;
    // printf("Element is %d\n", ptr->data);
    // ptr = ptr->next;

    // while (ptr != head)
    // {
    //     printf("Element : %d\n", ptr->data);
    //     ptr = ptr->next;
    // }

    //  OR
    struct node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 12;
    head->next = first;

    first->data = 25;
    first->next = second;

    second->data = 36;
    second->next = third;

    third->data = 31;
    third->next = fourth;

    fourth->data = 13;
    fourth->next = head;

    linkedlisttraversal(head);
    return 0;
}
*/



// Insertion in circular linkedlist
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *head)
{
    struct node *ptr = head;
    
    do
    {
        printf("Element is %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Insertion in the beginning
struct node *insertatbeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// Insertion at the end
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p -> next = ptr;
    ptr -> next = head;
    return head;
}

//Insertion at the index 
struct node * insertAtIndex(struct node *head, int data, int index){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    struct node * p = head; // head node ko hmne p mana he initially
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    //  p head ki jagah index-1 wale node ko point kar rha he
    ptr->data = data;
    ptr->next = p->next;
    // pehle p -> next jisko point kar rha tha vo ab ptr -> next point kar rha he
    p->next = ptr;
    // aur ab p -> next ptr ko point kr rha
    return head;
}

int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 15;
    head->next = first;

    first->data = 19;
    first->next = second;

    second->data = 25;
    second->next = third;

    third->data = 36;
    third->next = head;

    printf("Circular Linked list before insertion : \n");
    linkedlisttraversal(head);
    printf("\n");
    // printf("Circular Linked list after insertion at the beginning: \n");
    // head = insertatbeg(head, 82);

    // printf("Circular linked list after insertion at the end \n");
    // head = insertatend(head,53);

    printf("Circular linked list after insertion at the index : \n");
    head = insertAtIndex(head,43,2);
    linkedlisttraversal(head);

    return 0;
}