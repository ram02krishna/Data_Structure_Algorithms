#include <stdio.h>
#include <stdlib.h>

struct element
{
    int row;   // Row index
    int col;   // Column index
    int value; // Value
};

struct sparse
{
    int rows;                 // Number of rows
    int cols;                 // Number of columns
    int num;                  // Number of non-zero elements
    struct element *elements; // Array of non-zero elements
};

void create(struct sparse *s)
{
    printf("Enter the dimensions of the matrix (rows x cols): ");
    scanf("%d %d", &s->rows, &s->cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &s->num);

    // Allocate memory for non-zero elements
    s->elements = (struct element *)malloc(s->num * sizeof(struct element));

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->elements[i].row, &s->elements[i].col, &s->elements[i].value);
    }
}

void display(struct sparse s)
{
    int row, col, k = 0;

    printf("Sparse Matrix:\n");
    for (row = 0; row < s.rows; row++)
    {
        for (col = 0; col < s.cols; col++)
        {
            if (k < s.num && row == s.elements[k].row && col == s.elements[k].col)
            {
                printf("%d ", s.elements[k++].value);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct sparse *multiply(struct sparse *s1, struct sparse *s2)
{
    if (s1->cols != s2->rows)
    { // Ensure matrix dimensions are compatible for multiplication
        printf("Matrix dimensions do not allow multiplication!\n");
        return NULL;
    }

    struct sparse *product = (struct sparse *)malloc(sizeof(struct sparse));
    product->rows = s1->rows;
    product->cols = s2->cols;
    product->elements = (struct element *)malloc((s1->num * s2->num) * sizeof(struct element)); // Allocate enough space

    int k = 0;

    for (int i = 0; i < s1->num; i++)
    {
        for (int j = 0; j < s2->num; j++)
        {
            if (s1->elements[i].col == s2->elements[j].row)
            { // Matching column of s1 with row of s2
                int found = 0;
                for (int l = 0; l < k; l++)
                {
                    if (product->elements[l].row == s1->elements[i].row &&
                        product->elements[l].col == s2->elements[j].col)
                    {
                        product->elements[l].value += s1->elements[i].value * s2->elements[j].value;
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    product->elements[k].row = s1->elements[i].row;
                    product->elements[k].col = s2->elements[j].col;
                    product->elements[k++].value = s1->elements[i].value * s2->elements[j].value;
                }
            }
        }
    }

    product->num = k;
    return product;
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

    printf("\nMultiplying the two matrices:\n");
    s3 = multiply(&s1, &s2);

    if (s3 != NULL)
    {
        display(*s3);
        free(s3->elements);
        free(s3);
    }

    free(s1.elements);
    free(s2.elements);

    return 0;
}
