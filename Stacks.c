
#include <stdio.h>
#include <stdbool.h>

// Creating a stack
int maxSize = 1000;
int size = 0;
int top = -1;
int a[1000];

// Push operation
void push(int e) {
    if (size == maxSize) {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    a[top] = e;
    size++;

    printf("%d is pushed to stack\n", e);
}

// Pop operation
int pop() {
    if (size == 0) {
        printf("Stack Underflow\n");
        return -1;
    }

    int e = a[top];
    top--;
    size--;

    return e;
}

// Peek operation
void peek() {
    if (size == 0) {
        printf("Stack Empty\n");
        return;
    }

    printf("Top element is: %d\n", a[top]);
}

// Check if stack is empty
bool isEmpty() {
     if(size==0){
        return true;
    }else{
        return false;
    }
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);

    peek();

    printf("Popped element: %d\n", pop());

    peek();

    printf("Is stack empty? %s\n",
           isEmpty() ? "Yes" : "No");

    return 0;
}
