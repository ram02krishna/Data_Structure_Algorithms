#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *next;
};

struct node *insert(struct node *head, float co, int ex); // Must be declared first because using insert function in create function before not declaring will show an error.

// Create function
struct node *create(struct node *head)
{
    int n;
    printf("Enter the no. of terms: ");
    scanf("%d", &n);
    int expo;
    float coeff;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

// Insert function
// sorted singly linked list(inserting a new element)
struct node *insert(struct node *head, float co, int ex)
{
    struct node *temp;
    struct node *newP = (struct node *)malloc(sizeof(struct node));
    newP->coeff = co;
    newP->expo = ex;
    newP->next = NULL;

    if (head == NULL || ex > head->expo) // This code is for inserting element at the beginning.
    {
        newP->next = head;
        head = newP;
    }
    else
    // This code if for inserting at the index by comparing the exponent.
    {
        temp = head;
        while (temp->next != NULL && temp->next->expo >= ex)
        {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

void print(struct node *head)
{
    if (head == NULL)
    {
        printf("No Polynomial\n");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("(%0.1fx^%d)", temp->coeff, temp->expo);
            temp = temp->next;
            if (temp != NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

int main()
{
    struct node *head = NULL;
    printf("Enter the polynomial\n");
    head = create(head);
    print(head);
    return 0;
}
