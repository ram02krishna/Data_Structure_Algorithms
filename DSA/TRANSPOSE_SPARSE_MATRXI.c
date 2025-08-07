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
    printf("Enter dimensions: ");
    scanf("%d %d", &s->m, &s->n);
    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->num);
    s->e = (struct element *)malloc(s->num * sizeof(struct element));
    printf("Enter all elements (row column value):\n");
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(struct sparse s)
{
    int i, j, k = 0;
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

struct sparse transpose(struct sparse s)
{
    struct sparse t;
    t.m = s.n;
    t.n = s.m;
    t.num = s.num;
    t.e = (struct element *)malloc(t.num * (sizeof(struct element)));


}

int main()
{
    struct sparse s, t;

    create(&s);
    printf("Original matrix:\n");
    display(s);

    t = transpose(s);
    printf("Transposed matrix:\n");
    display(t);

    return 0;
}
