/* Program: Evaluate a postfix expression (single-digit operands) using a stack */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char postfix[]) {
    int i, op1, op2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            push(c - '0'); /* convert char digit to int */
        } else {
            op2 = pop(); /* right-hand operand, popped first */
            op1 = pop(); /* left-hand operand */

            switch (c) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = (int) pow(op1, op2); break;

                default:
                    printf("Invalid operator: %c\n", c);
                    exit(1);
            }

            push(result);
        }
    }

    return pop(); /* final answer left on stack */
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}
