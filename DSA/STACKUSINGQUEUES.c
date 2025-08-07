#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

struct queue *createQueue(int size) {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = size;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(size * sizeof(int));
    return q;
}

void enqueue(struct queue *q, int data) {
    if (q->r == q->size - 1) {
        printf("Queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = data;
    }
}

int dequeue(struct queue *q) {
    if (q->f == q->r) {
        printf("Queue is empty\n");
        return -1;
    } else {
        q->f++;
        return q->arr[q->f];
    }
}

void push(struct queue **q1, struct queue **q2, int data) {
    enqueue(*q2, data);
    while ((*q1)->f != (*q1)->r) {
        enqueue(*q2, dequeue(*q1));
    }
    struct queue *temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}

int pop(struct queue *q1) {
    if (q1->f == q1->r) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return dequeue(q1);
    }
}

int main() {
    struct queue *q1 = createQueue(10);
    struct queue *q2 = createQueue(10);

    push(&q1, &q2, 1);
    push(&q1, &q2, 2);
    push(&q1, &q2, 3);

    printf("%d\n", pop(q1));
    printf("%d\n", pop(q1));
    printf("%d\n", pop(q1));
    return 0;
}