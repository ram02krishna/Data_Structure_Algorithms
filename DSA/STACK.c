// code to know whether stack is empty or not

// #include <stdio.h>
// #include <stdlib.h>

// struct stack
// {
//     int size;
//     int top;
//     int *arr;
// };

// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int main()
// {
//     // struct stack s;
//     // s.size = 80;
//     // s.top = -1; //-1 denotes that the stack is empty
//     // s.arr = (int *)malloc(s.size * sizeof(int));

//     // Here above s is stack whereas below s is a pointer of struct stack so both are right.

//     struct stack *s;
//     s->size = 5;
//     s->top = -1; //-1 denotes that the stack is empty
//     s->arr = (int *)malloc(s->size * sizeof(int));

//     // Pushing an element manually
//     s -> arr[0] = 7;
//     s -> arr[1] = 3;
//     s -> arr[2] = 5;
//     s -> arr[3] = 1;
//     s -> arr[4] = 4;
//     s -> top++;

//     // Check if stack is empty
//     // if(isEmpty(s))
//     // {
//     //     printf("The stack is empty");
//     // }
//     // else
//     // {
//     //     printf("The stack is not empty");
//     // }

//     // Check if stack is full
//     if(isFull(s))
//     {
//         printf("The stack is full");
//     }
//     else{
//         printf("The stack is not full");
//     }
//     return 0;
// }



// Implement of push pop property in the array

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr -> top--;
        return val;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    // struct stack *sp;
    sp->size = 7;
    sp->top = -1;
    sp->arr = (int *)malloc((sp->size) * sizeof(int));

    printf("Before pushing,Full : %d\n", isFull(sp));
    printf("Before pushing,Empty : %d\n", isEmpty(sp));
    push(sp, 12);
    push(sp, 15);
    push(sp, 23);
    push(sp, 2);
    push(sp, 19);
    push(sp, 32);
    push(sp, 7);
    push(sp, 10); // Stack Overflow since the size of the stack is 7.
    printf("Ater pushing,Full : %d\n", isFull(sp));
    printf("Ater pushing,Empty : %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n",pop(sp));//Last in first out!
    printf("Popped %d from the stack\n",pop(sp));//Last in first out!
    printf("Popped %d from the stack\n",pop(sp));//Last in first out!
    return 0;
}