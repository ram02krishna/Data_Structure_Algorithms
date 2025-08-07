#include <stdio.h>
#include <stdlib.h>

struct element {
    int i; // Row index
    int j; // Column index
    int x; // Value
};

struct sparse {
    int m; // Number of rows
    int n; // Number of columns
    int num; // Number of non-zero elements
    struct element *e; // Array of non-zero elements
};

void create(struct sparse *s) {
    printf("Enter the dimensions of the matrix (m x n): ");
    scanf("%d %d", &s->m, &s->n);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &s->num);

    // Allocate memory for non-zero elements
    s->e = (struct element *)malloc(s->num * sizeof(struct element));

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < s->num; i++) {
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(struct sparse s) {
    int i, j, k = 0;

    printf("Sparse Matrix:\n");
    for (i = 0; i < s.m; i++) {
        for (j = 0; j < s.n; j++) {
            if (k < s.num && i == s.e[k].i && j == s.e[k].j) {
                printf("%d ", s.e[k++].x);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct sparse *subtract(struct sparse *s1, struct sparse *s2) {
    if (s1->m != s2->m || s1->n != s2->n) {
        printf("Matrix dimensions do not match!\n");
        return NULL;
    }

    struct sparse *difference = (struct sparse *)malloc(sizeof(struct sparse));
    difference->m = s1->m;
    difference->n = s2->n;
    difference->e = (struct element *)malloc((s1->num + s2->num) * sizeof(struct element));

    int i = 0, j = 0, k = 0;

    while (i < s1->num && j < s2->num) {
        if (s1->e[i].i < s2->e[j].i || 
            (s1->e[i].i == s2->e[j].i && s1->e[i].j < s2->e[j].j)) {
            difference->e[k++] = s1->e[i++];
        } else if (s1->e[i].i > s2->e[j].i || 
                   (s1->e[i].i == s2->e[j].i && s1->e[i].j > s2->e[j].j)) {
            difference->e[k] = s2->e[j];
            difference->e[k++].x = -s2->e[j++].x;
        } else {
            difference->e[k] = s1->e[i];
            difference->e[k++].x = s1->e[i++].x - s2->e[j++].x;
        }
    }

    // Copy remaining elements from s1
    for (; i < s1->num; i++) difference->e[k++] = s1->e[i];
    // Copy remaining elements from s2, but negate the values
    for (; j < s2->num; j++) {
        difference->e[k] = s2->e[j];
        difference->e[k++].x = -s2->e[j].x;
    }

    difference->num = k;

    return difference;
}

int main() {
    struct sparse s1, s2, *s3;

    printf("Create first matrix:\n");
    create(&s1);
    display(s1);

    printf("\nCreate second matrix:\n");
    create(&s2);
    display(s2);

    printf("\nSubtracting the two matrices:\n");
    s3 = subtract(&s1, &s2);

    if (s3) {
        display(*s3);
    }



    return 0;
}
