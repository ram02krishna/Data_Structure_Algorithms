// case 1 : Insert at the beginning
// time complexity for this is bigO(1)
// case 2 : Insert in between
// time complexity for this is bigO(n)
// case 3 : Insert at the end
// time complexity for this is bigO(n)
// case 4 : Insert after a node
// time complexity for this is bigO (1)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// ptr is same as temp variable.so, can replace ptr by temp.

void linkedlisttraversal(struct node * ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d\n",ptr -> data);
        ptr = ptr -> next;
    }
}

// Case 1
struct node * insertAtFirst(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr; 
}

// Case 2
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
    // pehle p -> next jisko point kar rha tha vo ab ptr -> next ko point kar rha he
    p->next = ptr;
    // aur ab p -> next ptr ko point kr rha
    return head;
}

// Case 3
struct node * insertAtEnd(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
struct node * insertAfternode(struct node *head, struct node *prevnode, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevnode->next; 
    prevnode->next = ptr;
    //OR 
    // ptr -> next = q -> next;
    // q ->next = ptr;
    
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

     // link first and second nodes
    head -> data = 7;
    head -> next = second;

    //  link second and third nodes
    second -> data = 11;
    second -> next = third;

    // link third and fourth nodes
    third -> data = 66;
    third -> next = NULL;

    printf("Linked list before insertion\n");
    linkedlisttraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    head = insertAfternode(head, third, 45);
    printf("\nLinked list after insertion\n");
    linkedlisttraversal(head);

    return 0;
}