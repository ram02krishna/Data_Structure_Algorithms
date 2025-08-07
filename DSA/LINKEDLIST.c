/*
struct node{
    int data;
    struct node *next; -> this pointer is self referencing structure
};
*/
// time complexity for the n elements for traversal is bigoh of n that is O(n).



#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void linkedlisttraversal(struct node * ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d \n",ptr -> data);
        ptr = ptr -> next;
    }
}

int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node)); 
    fourth = (struct node *) malloc(sizeof(struct node)); 

    // link first and second nodes
    head -> data = 7;
    head -> next = second;

    //  link second and third nodes
    second -> data = 11;
    second -> next = third;

    // link third and fourth nodes
    third -> data = 66;
    third -> next = fourth;
    
    // terminate the list at the fourth node
    fourth -> data = 75;
    fourth -> next = NULL;

    linkedlisttraversal(head);
    return 0;
}





// create and transverse a node in linked list
// #include<stdio.h>
// #include<stdlib.h>

// // Define the structure for a node in the linked list
// struct node {
//     int data;
//     struct node* next;
// };

// // Function to create a new node
// struct node* createnode(int data) {
//     struct node* newnode = (struct node*)malloc(sizeof(struct node));
//     if (newnode == NULL) {
//         printf("Memory allocation failed.\n");
//         exit(EXIT_FAILURE);
//     }
//     newnode->data = data;
//     newnode->next = NULL;
//     return newnode;
// }

// // Function to traverse and print the linked list
// void traverseLinkedList(struct node* head) {
//     struct node* current = head;
//     while (current != NULL) {
//         printf("%d -> ", current->data);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     // Creating nodes
//     struct node* head = createnode(1);
//     struct node* second = createnode(2);
//     struct node* third = createnode(3);

//     // Connecting nodes to form the linked list
//     head->next = second;
//     second->next = third;

//     // Traversing and printing the linked list
//     printf("Linked List: ");
//     traverseLinkedList(head);

//     // Freeing allocated memory
//     free(head);
//     free(second);
//     free(third);

//     return 0;
// }