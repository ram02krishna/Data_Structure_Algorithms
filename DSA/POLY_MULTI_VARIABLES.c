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
        while ((temp->next != NULL) && (temp->next->expX > exX) || (temp->next->expX == exX && temp->next->expY > exY) || (temp->next->expX == exX && temp->next->expY == exY && temp->next->expZ >= exZ))
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
            printf("(%0.1f", temp->coeff); // opening bracket

            if (temp->expX != 0)
                printf("x^%d", temp->expX);

            if (temp->expY != 0)
                printf("y^%d", temp->expY);

            if (temp->expZ != 0)
                printf("z^%d", temp->expZ);

            printf(")"); // closing bracket

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
