// case 1 : Deleting the first node
// time complexity is O(1)
// case 2 : Deleting a node in between
// time complexity is O(n)
// case 3 : Deleting the end node
// time complexity is O(n)
// case :  

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversallinkedlist(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d\n",ptr -> data);
        ptr = ptr -> next;
    }
}

// case 1:Deleting the first node element from the linked list.
struct node *deleteFirstnode(struct node *head)
{
    struct node * ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

// case 2:Deletiing the element at a given index from the linked list.
struct node *deleteAtIndex(struct node *head,int index)
{
    struct node *p = head;
    struct node *q = head -> next;
    for(int i=0;i<index-1;i++)
    {
        p = p -> next;
        q = q -> next;
    }
    p->next = q->next ;
    free(q);
    return head;
}

// case 3:Deleting the element from the last node
struct node *deleteEndNode(struct node *head)
{
    struct node *p = head;
    struct node *q = head -> next;
    while(q -> next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }
    p -> next = NULL;
    free(q);
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
    
    head -> data = 93;
    head -> next = first;

    first -> data = 45;
    first -> next = second;
    
    second -> data = 65;
    second -> next = third;

    third -> data = 81;
    third -> next = NULL;

    printf("Linked list before deleting the first node \n");
    traversallinkedlist(head);
    // printf("Linked list after deleting node from first position : \n");
    // head = deleteFirstnode(head);
    // printf("Linked list after deleting a node from a index is : \n");
    // head = deleteAtIndex(head,2);
    printf("Linked list after deleting the element from the end node : \n");
    head = deleteEndNode(head);
    traversallinkedlist(head);

    return 0;
}