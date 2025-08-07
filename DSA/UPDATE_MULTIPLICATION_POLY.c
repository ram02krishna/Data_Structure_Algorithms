#include<stdio.h>
#include<stdlib.h> // for malloc

struct node {
    float coeff;
    int expo;
    struct node *next;
};

struct node* insert(struct node *head, float co, int ex) {
    struct node *temp;
    struct node *newP = (struct node *)malloc(sizeof(struct node));
    if (newP == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    newP->coeff = co;
    newP->expo = ex;
    newP->next = NULL;

    if (head == NULL || ex > head->expo) {
        newP->next = head;
        head = newP;
    } else {
        temp = head;
        while (temp->next != NULL && temp->next->expo >= ex) {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

struct node *create(struct node *head) {
    int n;
    float coeff;
    int expo;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return head;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        if (scanf("%f", &coeff) != 1) {
            printf("Invalid input.\n");
            return head;
        }

        printf("Enter the exponent for term %d: ", i + 1);
        if (scanf("%d", &expo) != 1) {
            printf("Invalid input.\n");
            return head;
        }

        head = insert(head, coeff, expo);
    }
    return head;
}

void print(struct node *head) {
    if (head == NULL) {
        printf("No Polynomial.\n");
    } else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("(%0.1fx^%d)", temp->coeff, temp->expo);
            temp = temp->next;
            if (temp != NULL) {
                printf(" + ");
            } else {
                printf("\n");
            }
        }
    }
}

void PolyMulti(struct node *head1, struct node *head2) {
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    if (head1 == NULL || head2 == NULL) {
        printf("Zero Polynomial\n");
        return;
    }

    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }

    printf("Before Simplification:\n");
    print(head3);

    // Simplify the polynomial
    struct node *ptr3 = head3;
    struct node *temp = NULL;

    while (ptr3 != NULL && ptr3->next != NULL) {
        if (ptr3->expo == ptr3->next->expo) {
            ptr3->coeff += ptr3->next->coeff;
            temp = ptr3->next;
            ptr3->next = ptr3->next->next;
            free(temp);
        } else {
            ptr3 = ptr3->next;
        }
    }

    printf("After Simplification:\n");
    print(head3);

    // Free the memory allocated for the result polynomial
    ptr3 = head3;
    while (ptr3 != NULL) {
        temp = ptr3;
        ptr3 = ptr3->next;
        free(temp);
    }
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    printf("Enter the first polynomial\n");
    head1 = create(head1);

    printf("Enter the second polynomial\n");
    head2 = create(head2);

    printf("The Resultant Polynomial is:\n");
    PolyMulti(head1, head2);

    // Free the memory allocated for the input polynomials
    struct node *temp;
    while (head1 != NULL) {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2 != NULL) {
        temp = head2;
        head2 = head2->next;
        free(temp);
    }

    return 0;
}
