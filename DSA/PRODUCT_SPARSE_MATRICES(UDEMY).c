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

struct sparse *multiply(struct sparse *s1, struct sparse *s2) {
    if (s1->n != s2->m) {  // Ensure matrix dimensions are compatible for multiplication
        printf("Matrix dimensions do not allow multiplication!\n");
        return NULL;
    }

    struct sparse *product = (struct sparse *)malloc(sizeof(struct sparse));
    product->m = s1->m;
    product->n = s2->n;
    product->e = (struct element *)malloc((s1->num * s2->num) * sizeof(struct element)); // Allocate enough space

    int k = 0;

    for (int i = 0; i < s1->num; i++) {
        for (int j = 0; j < s2->num; j++) {
            if (s1->e[i].j == s2->e[j].i) {  // Matching column of s1 with row of s2
                int found = 0;
                for (int l = 0; l < k; l++) {
                    if (product->e[l].i == s1->e[i].i && product->e[l].j == s2->e[j].j) {
                        product->e[l].x += s1->e[i].x * s2->e[j].x;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    product->e[k].i = s1->e[i].i;
                    product->e[k].j = s2->e[j].j;
                    product->e[k++].x = s1->e[i].x * s2->e[j].x;
                }
            }
        }
    }

    product->num = k;
    return product;
}

int main() {
    struct sparse s1, s2, *s3;

    printf("Create first matrix:\n");
    create(&s1);
    display(s1);

    printf("\nCreate second matrix:\n");
    create(&s2);
    display(s2);

    printf("\nMultiplying the two matrices:\n");
    s3 = multiply(&s1, &s2);

   display(*s3);

    return 0;
}
