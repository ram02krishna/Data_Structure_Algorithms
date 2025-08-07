#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int expX, expY, expZ; // Exponents for x, y, z
    struct node *next;
};

// Function prototypes
struct node *insert(struct node *head, float co, int exX, int exY, int exZ);
struct node *create(struct node *head);
void print(struct node *head);
struct node *PolyAdd(struct node *head1, struct node *head2);
struct node *PolySub(struct node *head1, struct node *head2);
struct node *PolyMul(struct node *head1, struct node *head2);
struct node *PolyDiv(struct node *dividend, struct node *divisor, struct node **remainder);

// Function to insert a new node in the polynomial
struct node *insert(struct node *head, float co, int exX, int exY, int exZ) {
    struct node *temp;
    struct node *newP = (struct node *)malloc(sizeof(struct node));
    newP->coeff = co;
    newP->expX = exX;
    newP->expY = exY;
    newP->expZ = exZ;
    newP->next = NULL;

    if (head == NULL || (exX > head->expX) ||
        (exX == head->expX && exY > head->expY) ||
        (exX == head->expX && exY == head->expY && exZ > head->expZ)) {
        newP->next = head;
        head = newP;
    } else {
        temp = head;
        while (temp->next != NULL &&
               ((temp->next->expX > exX) ||
                (temp->next->expX == exX && temp->next->expY > exY) ||
                (temp->next->expX == exX && temp->next->expY == exY && temp->next->expZ >= exZ))) {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

// Function to create a polynomial
struct node *create(struct node *head) {
    int n, i;
    float coeff;
    int expX, expY, expZ;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
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

// Function to print the polynomial
void print(struct node *head) {
    if (head == NULL) {
        printf("No Polynomial.\n");
    } else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("(%0.1f", temp->coeff);

            if (temp->expX != 0)
                printf("x^%d", temp->expX);

            if (temp->expY != 0)
                printf("y^%d", temp->expY);

            if (temp->expZ != 0)
                printf("z^%d", temp->expZ);

            printf(")");

            temp = temp->next;
            if (temp != NULL) {
                printf(" + ");
            } else {
                printf("\n");
            }
        }
    }
}

// Function to add two polynomials
struct node *PolyAdd(struct node *head1, struct node *head2) {
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expX == ptr2->expX && ptr1->expY == ptr2->expY && ptr1->expZ == ptr2->expZ) {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expX, ptr1->expY, ptr1->expZ);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if ((ptr1->expX > ptr2->expX) || 
                   (ptr1->expX == ptr2->expX && ptr1->expY > ptr2->expY) || 
                   (ptr1->expX == ptr2->expX && ptr1->expY == ptr2->expY && ptr1->expZ > ptr2->expZ)) {
            head3 = insert(head3, ptr1->coeff, ptr1->expX, ptr1->expY, ptr1->expZ);
            ptr1 = ptr1->next;
        } else {
            head3 = insert(head3, ptr2->coeff, ptr2->expX, ptr2->expY, ptr2->expZ);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        head3 = insert(head3, ptr1->coeff, ptr1->expX, ptr1->expY, ptr1->expZ);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        head3 = insert(head3, ptr2->coeff, ptr2->expX, ptr2->expY, ptr2->expZ);
        ptr2 = ptr2->next;
    }

    return head3;
}

// Function to subtract two polynomials
struct node *PolySub(struct node *head1, struct node *head2) {
    struct node *ptr2 = head2;

    // Negate all coefficients in head2
    while (ptr2 != NULL) {
        ptr2->coeff = -ptr2->coeff;
        ptr2 = ptr2->next;
    }

    // Use PolyAdd to subtract
    return PolyAdd(head1, head2);
}

// Function to multiply two polynomials
struct node *PolyMul(struct node *head1, struct node *head2) {
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    while (ptr1 != NULL) {
        ptr2 = head2;
        while (ptr2 != NULL) {
            head3 = insert(head3,
                           ptr1->coeff * ptr2->coeff,
                           ptr1->expX + ptr2->expX,
                           ptr1->expY + ptr2->expY,
                           ptr1->expZ + ptr2->expZ);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return head3;
}

// Function to divide two polynomials
struct node *PolyDiv(struct node *dividend, struct node *divisor, struct node **remainder) {
    struct node *quotient = NULL;
    struct node *tempDivisor = NULL;

    while (dividend != NULL &&
           (dividend->expX > divisor->expX ||
            (dividend->expX == divisor->expX && dividend->expY > divisor->expY) ||
            (dividend->expX == divisor->expX && dividend->expY == divisor->expY && dividend->expZ >= divisor->expZ))) {
        
        float coeffQuotient = dividend->coeff / divisor->coeff;
        int expXQuotient = dividend->expX - divisor->expX;
        int expYQuotient = dividend->expY - divisor->expY;
        int expZQuotient = dividend->expZ - divisor->expZ;

        quotient = insert(quotient, coeffQuotient, expXQuotient, expYQuotient, expZQuotient);

        tempDivisor = insert(tempDivisor, coeffQuotient, expXQuotient, expYQuotient, expZQuotient);
        struct node *product = PolyMul(tempDivisor, divisor);
        dividend = PolySub(dividend, product);

        tempDivisor = NULL;
    }

    *remainder = dividend;
    return quotient;
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *quotient = NULL;
    struct node *remainder = NULL;

    printf("Enter the Dividend Polynomial\n");
    head1 = create(head1);
    printf("Enter the Divisor Polynomial\n");
    head2 = create(head2);

    quotient = PolyDiv(head1, head2, &remainder);

    printf("Quotient polynomial is: ");
    print(quotient);

    printf("Remainder polynomial is: ");
    print(remainder);

    return 0;
}
