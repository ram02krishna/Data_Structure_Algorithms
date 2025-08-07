#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Structure for stack
struct Stack {
    struct StackNode* top;
};

// Function to create a new stack node
struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push an element to the top of the stack
void push(struct Stack* stack, int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = stack->top;
    stack->top = stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to pop an element from the top of the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1; // Stack is empty
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Structure for queue using two stacks
struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = (struct Stack*)malloc(sizeof(struct Stack));
    queue->stack1->top = NULL;
    queue->stack2 = (struct Stack*)malloc(sizeof(struct Stack));
    queue->stack2->top = NULL;
    return queue;
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int data) {
    push(queue->stack1, data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue is empty\n");
        return -1;
    }

    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    return 0;
}
