#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i; // Row index
    int j; // Column index
    int x; // Value
};

struct sparse
{
    int m;             // Number of rows
    int n;             // Number of columns
    int num;           // Number of non-zero elements
    struct element *e; // Array of non-zero elements
};

void create(struct sparse *s)
{
    printf("Enter the dimensions of the matrix (m x n): ");
    scanf("%d %d", &s->m, &s->n);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &s->num);

    // Allocate memory for non-zero elements
    s->e = (struct element *)malloc(s->num * sizeof(struct element));

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(struct sparse s)
{
    int i, j, k = 0;

    printf("Sparse Matrix:\n");
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (k < s.num && i == s.e[k].i && j == s.e[k].j)
            {
                printf("%d ", s.e[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct sparse *add(struct sparse *s1, struct sparse *s2)
{
    if (s1->m != s2->m || s1->n != s2->n)
    {
        printf("Matrix dimensions do not match!\n");
        return NULL;
    }

    struct sparse *sum = (struct sparse *)malloc(sizeof(struct sparse));
    sum->m = s1->m;
    sum->n = s2->n;
    sum->e = (struct element *)malloc((s1->num + s2->num) * sizeof(struct element));

    int i = 0, j = 0, k = 0;

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i ||
            (s1->e[i].i == s2->e[j].i && s1->e[i].j < s2->e[j].j))
        {
            sum->e[k++] = s1->e[i++];
        }
        else if (s1->e[i].i > s2->e[j].i ||
                 (s1->e[i].i == s2->e[j].i && s1->e[i].j > s2->e[j].j))
        {
            sum->e[k++] = s2->e[j++];
        }
        else
        {
            sum->e[k] = s1->e[i];
            sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
        }
    }

    // Copy remaining elements
    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i];
    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j];

    sum->num = k;

    return sum;
}

int main()
{
    struct sparse s1, s2, *s3;

    printf("Create first matrix:\n");
    create(&s1);
    display(s1);

    printf("\nCreate second matrix:\n");
    create(&s2);
    display(s2);

    printf("\nAdding the two matrices:\n");
    s3 = add(&s1, &s2);

    if (s3)
    {
        display(*s3);
    }

    return 0;
}
