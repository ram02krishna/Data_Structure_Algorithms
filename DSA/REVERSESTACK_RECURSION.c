#include <stdio.h> 
#define MAX 7
#define TRUE 1
#define FALSE 0 
 
struct Stack {
    int top;
    int array[MAX];
} st;
 

void initialize() {
 st.top = -1;
}
 

int isFull() {   
    if(st.top >= MAX-1)
        return TRUE;
    else
        return FALSE;
}
 

int isEmpty() {
 if(st.top == -1)
     return TRUE;
 else
     return FALSE;
}
 

void push(int x) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        st.array[st.top + 1] = x;
        st.top++;
    }
}
 

int pop() {
    if (isEmpty())
        printf("Stack is Empty...\n");
    else {
     st.top = st.top - 1;
        return st.array[st.top+1];
    }
}
 
void printStack(){
 if(!isEmpty()){
     int temp = pop();
     printStack();
     printf(" %d ", temp);
     push( temp);
    }
}
void insertAtBottom(int y) {
    if (isEmpty()) {
        push(y);
    } else {
  
        
        int top = pop();
        insertAtBottom(item);
  
        
        push(top);
    }
}
 
void reverse() {
    if (!isEmpty()) {
        
        int top = pop();
        reverse();
  
        
        insertAtBottom(top);
    }
}

int getSize(){
 return st.top+1;
}
 
int main() {      
    initialize(st);
    push(0);
    push(9);
    push(4);
    push(6);
    push(7);
    printf("Given Input Stack\n");
    printStack();
    reverse();
    printf("\nReversed Given Input Stack\n");
    printStack();
    return 0;
}