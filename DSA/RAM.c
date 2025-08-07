/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *next;
};
struct node *insert(struct node *head, float co, int ex);

struct node *create(struct node *head)
{
    int n;
    printf("Enter the No. of terms: ");
    scanf("%d", &n); // Remove unnecessary '\n'
    float coeff;     // Change to float
    int expo;        // Change to int
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%f", &coeff); // Use %f for float
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &expo); // Use %d for int
        head = insert(head, coeff, expo);
    }
    return head;
}

struct node *insert(struct node *head, float co, int ex)
{
    struct node *temp;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coeff = co;
    newNode->expo = ex;
    newNode->next = NULL;

    if (head == NULL || ex > head->expo)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->expo >= ex)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

struct node *Add(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
        while (ptr1->next != NULL)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        while (ptr2->next != NULL)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    return head3;
};

void display(struct node *head);

struct node *PolyMulti(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    display(head3);
};

void display(struct node *head)
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
            if (temp != NULL) // Move this condition inside the loop
            {
                printf(" + ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *result = NULL;

    printf("Enter the polynomial 1 :\n");
    head1 = create(head1);

    printf("Enter the polynomial 2 :\n");
    head2 = create(head2);

    result = Add(head1, head2);
    printf("Resultant Polynomial : \n");
    display(result);

    struct node* result_multi = NULL;
    result_multi = PolyMulti(head1,head2);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expX, expY, expZ; // Exponents for x, y, z
    struct node *next;
};

struct node *insert(struct node *head, float co, int exX, int exY, int exZ);

// Create function
struct node *create(struct node *head)
{
    int n;
    printf("Enter the no. of terms: ");
    scanf("%d", &n);
    int expX, expY, expZ;
    float coeff;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent for x in term %d: ", i + 1);
        scanf("%d", &expX);
        printf("Enter the exponent for y in term %d: ", i + 1);
        scanf("%d", &expY);
        printf("Enter the exponent for z in term %d: ", i + 1);
        scanf("%d", &expZ);
        head = insert(head, coeff, expX, expY, expZ);
    }
    return head;
}

// Insert function
// sorted singly linked list (inserting a new element)
struct node *insert(struct node *head, float co, int exX, int exY, int exZ)
{
    struct node *temp;
    struct node *newP = (struct node *)malloc(sizeof(struct node));
    newP->coeff = co;
    newP->expX = exX;
    newP->expY = exY;
    newP->expZ = exZ;
    newP->next = NULL;

    if (head == NULL || (exX > head->expX) || (exX == head->expX && exY > head->expY) || (exX == head->expX && exY == head->expY && exZ > head->expZ))
    {
        // Insert at the beginning
        newP->next = head;
        head = newP;
    }
    else
    {
        // Insert in the correct position
        temp = head;
        while ((temp->next != NULL) &&((temp->next->expX > exX )||(temp->next->expX == exX && temp->next->expY > exY) ||(temp->next->expX == exX && temp->next->expY == exY && temp->next->expZ >= exZ)))
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
            printf("(%0.1f", temp->coeff);

            if (temp->expX != 0)
                printf("x^%d", temp->expX);

            if (temp->expY != 0)
                printf("y^%d", temp->expY);

            if (temp->expZ != 0)
                printf("z^%d", temp->expZ);

            printf(")");

            temp = temp->next;
            if (temp != NULL)
            {
                printf(" + ");
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
