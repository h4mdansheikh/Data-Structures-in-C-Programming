#include <stdio.h>
#include <stdbool.h>

// ==================================================
//               STACK IMPLEMENTATION
// ==================================================

// Stack configuration and initialization
int maxSize = 1000;
int size = 0;
int top = -1;
int a[1000];


// ==================================================
//             PUSH - INSERT AN ELEMENT
// ==================================================

// Inserts a new element at the top of the stack
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


// ==================================================
//             POP - REMOVE AN ELEMENT
// ==================================================

// Removes and returns the top element of the stack
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


// ==================================================
//             PEEK - VIEW THE TOP ELEMENT
// ==================================================

// Displays the top element without removing it
void peek() {
    if (size == 0) {
        printf("Stack Empty\n");
        return;
    }

    printf("Top element is: %d\n", a[top]);
}


// ==================================================
//           isEmpty - CHECK STACK STATUS
// ==================================================

// Returns true if the stack is empty; false otherwise
bool isEmpty() {
    if (size == 0) {
        return true;
    } else {
        return false;
    }
}


// ==================================================
//                  MAIN FUNCTION
// ==================================================

// Demonstrates the basic operations of a stack
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
