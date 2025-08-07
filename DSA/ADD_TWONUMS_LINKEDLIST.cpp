/*
Logic For adding two numbers using linked list
1.Represent an n-digit number using linked list.
2.Rverse the numbers for addition.
3.Add the numbers and store the result in the resultant singly linked list

Let say we have a 4-digit number 3687 and also,we have a 3-digit number 567

This means we must have n nodes in the linked list for an  n -digit number where each node is capable of storing a single digit of the number.

Simple logic to get one digit at a time
1.Divide the number by 10
for example : 567 % 10 = 7
2.Inorder to get the second last digit of the number 567,we will first divide the number by 10 and then take the mod of the resultant with 10
for example : 567 / 10 = 56
              56 % 10 = 6
3.Inorder to get the third last digit of the number 567,we will first divide the result that we get previously on diving 10 that is quotient of the last time that is 56 here and the take the mod of the resultant with the 10
for example : 56 / 10 = 5
               5 % 10 = 5
4.This process will continue until we will get o from the result of division.
for example : 5 /10 = 0
              0 % 10 = 0

*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *insert_node(struct node *head, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->link = NULL;

    newNode->link = head;
    head = newNode;
    return head;
}

struct node *linkedlist(struct node *head, int n)
{
    while (n != 0)
    {
        head = insert_node(head, n % 10);
        n = n / 10;
    }
    return head;
}

struct node *reverse_List(struct node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else
    {
        struct node *current = NULL;
        struct node *next = head->link;
        head->link = NULL;

        while (next != NULL)
        {
            current = next;
            next = next->link;
            current->link = head;
            head = current;
        }
        return head;
    }
}

void print(struct node *ptr)
{
    if (ptr == NULL)
    {
        cout << "No number" << endl;
    }
    else
    {
        cout << "Elements : " << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->link;
        }
    }
}

struct node *add(struct node *head1, struct node *head2)
{
    if (head1->data == 0)
    {
        return head2;
    }
    if (head2->data == 0)
    {
        return head1;
    }

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    int carry = 0, sum;

    while (ptr1 != NULL || ptr2 != NULL)
    {
        sum = carry;

        if (ptr1 != NULL)
        {
            sum += ptr1->data;
            ptr1 = ptr1->link;
        }

        if (ptr2 != NULL)
        {
            sum += ptr2->data;
            ptr2 = ptr2->link;
        }

        carry = sum / 10;
        head3 = insert_node(head3, sum % 10);
    }

    if (carry)
    {
        head3 = insert_node(head3, carry);
    }

    return head3;
}

int main()
{
    int a, b;
    cout << "Enter the numbers a and b : " << endl;
    cin >> a >> b;

    struct node *head1 = NULL;
    struct node *head2 = NULL;

    head1 = linkedlist(head1, a);
    head2 = linkedlist(head2, b);

    cout << "First number as linked list:" << endl;
    print(head1);
    cout << endl;

    cout << "Second number as linked list:" << endl;
    print(head2);

    cout << endl;
    head1 = reverse_List(head1);
    head2 = reverse_List(head2);

    cout << "Reversed Linked Lists : " << endl;
    print(head1);
    cout << endl;
    print(head2);
    cout << endl;

    struct node *head3 = NULL;
    head3 = add(head1, head2);
    cout << "Resultant after adding Two Numbers : " << endl;
    print(head3);
    return 0;
}
