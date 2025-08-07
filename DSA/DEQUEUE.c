#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int deque[MAX_SIZE];
int f = -1;
int r = -1;

bool isEmpty() {
    return f == -1;
}

bool isFull() {
    return (r + 1) % MAX_SIZE == f;
}

void insertFront(int val) {
    if (!isFull()) {
        if (f == -1) {
            f = r = 0;
            deque[f] = val; //This dequeue is the name of the function.
        } 
        else {
            if (f == 0) {
                f = MAX_SIZE - 1;
            } else {
                f--;
            }  
            deque[f] = val;
        }
    }
}

void insertRear(int val) {
    if (!isFull()) {
        if (r == -1) {
            f = r = 0;
            deque[r] = val;
        } 
        else {
            if (r == MAX_SIZE - 1) {
                r = 0;
            } else {
                r++;
            }
            deque[r] = val;
        }
    }
}

void deleteFront() {
    if (!isEmpty()) {
        if (f == r) {
            f = r = -1;
        } 
        else {
            if (f == MAX_SIZE - 1) {
                f = 0;
            } else {
                f++;
            }
        }
    }
}

void deleteRear() {
    if (!isEmpty()) {
        if (f == r) {
            f = r = -1;
        } 
        else {
            if (r == 0) {
                r = MAX_SIZE - 1;
            } else {
                r--;
            }
        }
    }
}

int getFront() {
    if (!isEmpty()) {
        return deque[f];
    }
    return -1;
}

int getRear() {
    if (!isEmpty()) {
        return deque[r];
    }
    return -1;
}

int main() {
    insertFront(5);
    insertRear(10);
    insertRear(11);
    insertFront(19);
    printf("%d\n", getFront());
    printf("%d\n", getRear());
    if (isFull()) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    deleteRear();
    printf("%d\n", getRear());
    deleteFront();
    printf("%d\n", getFront());
    if (isEmpty()) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}
