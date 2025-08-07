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
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *insertatbeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

struct node *insertatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// void deletenode(struct node **head, int key)
// {
//     if (*head == NULL)
//     {
//         printf("\nEmpty list. Deletion not possible.\n");
//         return;
//     }

//     struct node *curr = *head, *prev = NULL;
//     while (curr->data != key)
//     {
//         if (curr->next == *head)
//         {
//             printf("\nNode with value %d not found in the circular linked list.\n", key);
//             return;
//         }
//         prev = curr;
//         curr = curr->next;
//     }

//     // Case 1: Only one node in the list
//     if (curr->next == *head && prev == NULL)
//     {
//         free(curr);
//         *head = NULL;
//         return;
//     }

//     // Case 2: Node to be deleted is the head node
//     if (curr == *head)
//     {
//         prev = *head;
//         while (prev->next != *head)
//         {
//             prev = prev->next;
//         }
//         *head = (*head)->next;
//         prev->next = *head;
//         free(curr);
//     }
//     else
//     {
//         // Case 3: Node to be deleted is in the middle or end
//         prev->next = curr->next;
//         free(curr);
//     }
// }

void deleteNode(struct node *head, int key) {
  struct node *temp = head, *prev;

  if (temp != NULL && temp->data == key) {
    head = temp->next;
    free(temp);
    return;
  }

  while (temp->next != head && temp->next->data != key) {
    temp = temp->next;
  }

  if (temp->next->data == key) {
    prev = temp;
    temp = temp->next;
    prev->next = temp->next;
    free(temp);
  }
}

int main()
{
    struct node *head = createnode(45);
    struct node *first = createnode(21);
    struct node *second = createnode(23);
    struct node *third = createnode(76);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = head;

    printf("Circular linked list before insertion : \n");
    linkedlisttraversal(head);
    printf("\n");
    head = insertatbeg(head, 12);
    head = insertatend(head, 91);
    head = insertatindex(head, 75, 2);
    printf("Circular linked list after insertion : \n");
    linkedlisttraversal(head);
    // deletenode(&head,23); -> This is when double pointer one function is used that is void deletenode(struct node **head ,int key)
    deleteNode(head,12); // -> This is when function is used by taking single pointer.
    // There is some issue for the deletion at beginning by using this single pointer so need to check it.
    printf("Circular linked list after deletion : \n");
    linkedlisttraversal(head);
    return 0;
}