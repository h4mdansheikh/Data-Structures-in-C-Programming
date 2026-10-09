#include <stdio.h>
#include <stdlib.h>

//=====================================================
// STACK IMPLEMENTATION USING A DYNAMICALLY ALLOCATED ARRAY
//=====================================================

typedef struct {
    int *arr;       // Pointer to the dynamically allocated array
    int top;        // Index of the current top element
    int capacity;   // Current allocated capacity of the array
} Stack;


//=====================================================
// CREATE STACK
//=====================================================

Stack* createStack(int initialCapacity) {
    Stack *s = (Stack*)malloc(sizeof(Stack));

    if (s == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    s->capacity = initialCapacity;
    s->top = -1;

    s->arr = (int*)malloc(s->capacity * sizeof(int));

    if (s->arr == NULL) {
        printf("Memory allocation failed\n");
        free(s);
        exit(1);
    }

    return s;
}


//=====================================================
// RESIZE STACK - DOUBLE THE CAPACITY
//=====================================================

void resizeStack(Stack *s) {
    s->capacity *= 2;

    int *temp = (int*)realloc(
        s->arr, s->capacity * sizeof(int)
    );

    if (temp == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }

    s->arr = temp;

    printf("[Resized stack to capacity %d]\n", s->capacity);
}


//=====================================================
// PUSH - INSERT AN ELEMENT
//=====================================================

void push(Stack *s, int item) {
    if (s->top == s->capacity - 1) {
        resizeStack(s);
    }

    s->arr[++(s->top)] = item;
}


//=====================================================
// POP - REMOVE THE TOP ELEMENT
//=====================================================

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    return s->arr[(s->top)--];
}


//=====================================================
// PEEK - VIEW THE TOP ELEMENT
//=====================================================

int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    return s->arr[s->top];
}


//=====================================================
// CHECK WHETHER THE STACK IS EMPTY
//=====================================================

int isEmpty(Stack *s) {
    return s->top == -1;
}


//=====================================================
// DISPLAY ALL STACK ELEMENTS
//=====================================================

void display(Stack *s) {
    printf("Stack (bottom -> top): ");

    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }

    printf("\n");
}


//=====================================================
// FREE ALLOCATED MEMORY
//=====================================================

void freeStack(Stack *s) {
    free(s->arr);
    free(s);
}


//=====================================================
// MAIN FUNCTION - TEST STACK OPERATIONS
//=====================================================

int main(void) {
    Stack *s = createStack(2);

    push(s, 10);
    push(s, 20);
    push(s, 30);  // Triggers automatic resizing
    push(s, 40);

    display(s);

    printf("Top element: %d\n", peek(s));
    printf("Popped: %d\n", pop(s));

    display(s);

    freeStack(s);

    return 0;
}
