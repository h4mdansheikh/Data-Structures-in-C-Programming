#include <stdio.h>

// Creating a stack
int maxSize = 1000;
int size = 0;
int top = -1;
int a[1000];

// Pushing an element onto the stack(Method 1[Static Array])
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


// Creating a Stack
struct stack {
    int maxSize;
    int size;
    int top;
    int a[1000];
};

// Pushing an element at the top of the stack(Method 2[Dynamic Array])
void push(struct stack *s, int e) {
    if (s->size == s->maxSize) {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->a[s->top] = e;
    s->size++;

    printf("%d is pushed to stack\n", e);
}

//Popping an element from a stack(Method 1[Static array])

int pop(){
    if(size==-){
        printf("Stack Underflow\n");
        return -1;
    }
    int e=a[top];
        top--;
        size--;
        return e;
}
 // Popping an element from the stack (Method 2)

int pop(struct stack *s) {
    if (s->size == 0) {
        printf("Stack Underflow\n");
        return -1;
    }

    int e = s->a[s->top];

    s->top--;
    s->size--;

    return e;
}
