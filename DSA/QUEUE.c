// queue is first come first out (FIFO)
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f; // f -> front
    int r; // r -> rare
    int *arr;
};

int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isempty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("Queue OVERFLOW!");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("No element to dequeue");
    }
    // this is equivalent to isempty function
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 20;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 20);
    enqueue(&q, 1);
    printf("Dequeuing element %d \n", dequeue(&q));
    printf("Dequeuing element %d \n", dequeue(&q));

    if (isempty(&q))
    {
        printf("Queue is empty\n");
    }
    if (isfull(&q))
    {
        printf("Queue is full\n");
    }
    return 0;
} 