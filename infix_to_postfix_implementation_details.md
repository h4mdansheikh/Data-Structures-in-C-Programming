Infix to Postfix Conversion in C --- Complete Explanation
This guide explains the program from the basics, including the logic,
why each step is necessary, how memory changes, and how the stack
evolves during execution. It is formatted for GitHub Markdown.
1. Understanding the problem
Consider the infix expression:
``` text
A+B*C
```
It is called infix because each operator appears between its
operands. Multiplication has higher precedence than addition, so the
expression means:
[ A + (B `\times `{=tex}C) ]
Its postfix form is:
``` text
ABC*+
```
In postfix notation, operators appear after their operands. Postfix
expressions can be evaluated using a stack without repeatedly checking
operator precedence or parentheses.
This program converts an expression; it does not calculate its
numerical result.
2. The two main arrays
The program uses two character arrays for different purposes:
`stack[MAX]` temporarily stores operators and opening
parentheses while the algorithm decides when to output them.
`postfix[MAX]` stores the converted expression in the correct
order.
Think of the stack as a waiting room for operators and the postfix array
as the answer being built.
Important index variables
Variable   Purpose
---
`i`        Index of the current character in the infix input
`k`        Index of the next free position in the postfix output
`top`      Index of the topmost occupied position in the stack
For example, if the stack contains `+` and `*`, its logical layout is:
``` text
Stack array

Index       0       1       2       3
          +-------+-------+-------+-------+
Value     |   +   |   *   | unused| unused|
          +-------+-------+-------+-------+
                          ^
                         top = 1
```
The stack's top element is `*`. A `pop()` removes it first, following
LIFO: Last In, First Out.
Remember: `top` is an index, not the number of elements. When
`top = 1`, the stack contains two elements.
3. Global variables and constants
``` c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
```
---
Code                                Purpose
---
`stdio.h`                           Provides `printf()` and `scanf()`
`ctype.h`                           Provides `isalnum()`, used to
identify letters and digits
`string.h`                          Provides string functions; this
program does not currently use any
from this header
`#define MAX 100`                   Defines the array capacity as 100
characters
`char stack[MAX]`                   Creates 100 character slots for the
stack
`int top = -1`                      Marks the stack as initially empty
Why does `top` start at `-1`?
C arrays begin at index `0`, but an empty stack has no valid occupied
index. Therefore, `top = -1` means no stack element exists yet.
``` text
Initially:

Index       0       1       2       3       4
          +-------+-------+-------+-------+-------+
Value     |unused |unused |unused |unused |unused |
          +-------+-------+-------+-------+-------+

top = -1  -> stack is logically empty
```
The first `push()` increments `top` to `0` and stores the first
character at `stack[0]`.
The unused array slots are not necessarily filled with zero; they are
simply not part of the logical stack.
4. How the stack functions work
A. `push()` --- insert an element
``` c
void push(char x) {
    stack[++top] = x;
}
```
The expression `++top` is pre-increment. The computer:
Increments `top`.
Uses the new value as the array index.
Stores `x` at that index.
For example, `push('+')` when `top = -1`:
``` c
stack[++top] = '+';
```
The result is:
``` text
Before: top = -1

Step 1: ++top makes top = 0
Step 2: stack[0] = '+'

After:

Index       0       1       2       3
          +-------+-------+-------+-------+
Value     |   +   |unused |unused |unused |
          +-------+-------+-------+-------+
              ^
             top = 0
```
An equivalent, more verbose version is:
``` c
top = top + 1;
stack[top] = x;
```
B. `pop()` --- remove the top element
``` c
char pop() {
    return stack[top--];
}
```
The expression `top--` is post-decrement. The computer:
Reads and returns `stack[top]`.
Decreases `top` by one.
Suppose the stack contains `+` and `*`, with `top = 1`.
``` text
Before pop():

Index       0       1       2
          +-------+-------+-------+
Value     |   +   |   *   |unused |
          +-------+-------+-------+
                  ^
                 top = 1
```
Calling `pop()` returns `*`, then changes `top` to `0`.
``` text
After pop():

Index       0       1       2
          +-------+-------+-------+
Value     |   +   |   *   |unused |
          +-------+-------+-------+
              ^
             top = 0
```
The old `*` may remain physically in memory, but it is no longer part of
the logical stack because `top` moved down.
C. `peekTop()` --- inspect without removing
``` c
char peekTop() {
    return stack[top];
}
```
This returns the top element without changing `top`.
For example, if the stack contains `+` and `*`, `peekTop()` returns `*`,
and the stack remains unchanged.
Why is this needed? Before pushing a new operator, the algorithm
inspects the current top operator to decide whether it should be output
first.
`pop()` and `peekTop()` assume the stack is not empty. The main
conversion loops check `top != -1` before calling them.
5. Operator precedence
``` c
int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}
```
A larger number means higher precedence.
Operator             Precedence Meaning
---
`^`                           3 Exponentiation
`*`, `/`                      2 Multiplication and division
`+`, `-`                      1 Addition and subtraction
Other characters             -1 Not a recognized operator
Example: `*` encountered while `+` is on the stack
``` text
Stack top: +
Current operator: *

precedence('+') = 1
precedence('*') = 2
```
Because `1 < 2`, `+` must wait. The program pushes `*`.
``` text
Bottom
  +
  *
Top
```
Example: `+` encountered while `*` is on the stack
``` text
Stack top: *
Current operator: +

precedence('*') = 2
precedence('+') = 1
```
Because `2 > 1`, the program pops `*` into postfix before pushing `+`.
This comparison is the central rule of infix-to-postfix conversion.
6. Associativity --- why `^` is treated differently
``` c
int isRightAssociative(char ch) {
    return ch == '^';
}
```
This returns `1` (true) for `^` and `0` (false) for other characters.
Exponentiation is conventionally right-associative:
``` text
A^B^C
```
means:
[ A^{(B^C)} ]
Its postfix form is:
``` text
ABC^^
```
If the first `^` were popped when the second `^` arrived, the expression
would instead be grouped as `(A^B)^C`.
The conversion code checks:
``` c
precedence(peekTop()) == precedence(c) &&
!isRightAssociative(c)
```
In plain English:
> If the operator on the stack has equal precedence to the current
> operator, pop it only when the current operator is not
> right-associative.
Examples:
Infix     Postfix   Reason
---
`A-B-C`   `AB-C-`   Subtraction is left-associative
`A/B*C`   `AB/C*`   Division and multiplication are left-associative
`A^B^C`   `ABC^^`   Exponentiation is right-associative
Precedence alone is not enough; associativity also matters.
7. The `main()` function
``` c
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (no spaces): ");
    scanf("%99s", infix);

    infixtoPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
```
Execution proceeds in this order:
Create the arrays. `infix` stores the input and `postfix` stores
the result. Each has room for 100 characters.
Read the expression. `scanf("%99s", infix)` reads up to 99
non-whitespace characters, leaving room for the terminating `'\0'`.
Convert. `infixtoPostfix(infix, postfix)` performs the
conversion.
Print. `printf()` displays the resulting postfix string.
The real conversion work happens inside `infixtoPostfix()`.
8. Understanding `infixtoPostfix()` line by line
Function setup
``` c
void infixtoPostfix(char infix[], char postfix[]) {
    int i, k = 0;
```
The function receives the two arrays.
`i` tracks the character currently being read from `infix`.
`k = 0` means the output starts at `postfix[0]`.
Read the expression from left to right
``` c
for (i = 0; infix[i] != '\0'; i++) {
    char c = infix[i];
```
The loop processes one character at a time. It stops at the null
character `'\0'`, which marks the end of a C string.
For input `A+B*C`, the values of `c` are:
``` text
A -> + -> B -> * -> C -> end of string
```
`char c = infix[i];` copies the current character into a local variable
named `c`.
Case 1: The character is an operand
``` c
if (isalnum((unsigned char)c)) {
    postfix[k++] = c;
}
```
`isalnum()` checks whether the character is a letter or digit.
`A` --- operand
`x` --- operand
`7` --- operand
`+` --- not an operand
`(` --- not an operand
Operands are written directly to postfix because they do not need
precedence decisions.
`postfix[k++] = c;` stores `c` at the current output index and then
increments `k`.
If `k = 0` and `c = 'A'`, the result is:
``` text
postfix[0] = 'A'
k = 1
```
Case 2: The character is `(`
``` c
else if (c == '(') {
    push(c);
}
```
The opening parenthesis is pushed onto the stack.
Operators inside parentheses must be handled before operators outside
them, regardless of normal precedence. The `(` acts as a boundary marker
that prevents operators outside the parentheses from being popped while
processing the enclosed expression.
Case 3: The character is `)`
``` c
else if (c == ')') {
    while (top != -1 && peekTop() != '(') {
        postfix[k++] = pop();
    }

    if (top != -1) {
        pop(); // Remove '('
    }
}
```
This has two parts.
Part A: Pop until the opening parenthesis is reached.
``` c
while (top != -1 && peekTop() != '(') {
    postfix[k++] = pop();
}
```
Every operator above `(` is popped into postfix.
Part B: Discard the opening parenthesis.
``` c
if (top != -1) {
    pop();
}
```
The `(` is removed from the stack but is not written to postfix.
Parentheses are not required in a valid postfix expression.
This code does not fully validate mismatched parentheses.
Case 4: The character is an operator
``` c
else {
    while (top != -1 &&
           peekTop() != '(' &&
           (precedence(peekTop()) > precedence(c) ||
           (precedence(peekTop()) == precedence(c) &&
            !isRightAssociative(c)))) {
        postfix[k++] = pop();
    }

    push(c);
}
```
Before pushing a new operator, the program checks three things:
`top != -1`: the stack is not empty.
`peekTop() != '('`: the top is not an opening-parenthesis boundary.
The top operator should be output before the current operator.
The third check has two possibilities:
``` c
precedence(peekTop()) > precedence(c)
```
The stack's top operator has higher precedence, so pop it.
Or:
``` c
precedence(peekTop()) == precedence(c) &&
!isRightAssociative(c)
```
The operators have equal precedence, and the current operator is
left-associative, so pop the existing operator first.
When the `while` loop ends, the program executes:
``` c
push(c);
```
The current operator is placed on the stack.
Finish the conversion
``` c
while (top != -1) {
    postfix[k++] = pop();
}

postfix[k] = '\0';
```
When all input characters have been processed, any remaining operators
are popped into postfix.
Then `postfix[k] = '\0';` marks the end of the output string. Without
this null terminator, printing the array with `%s` would not be
guaranteed to stop at the intended endpoint.
9. Full visual execution: `A+B*C`
Let's trace the entire program.
Initial memory state
Input:
``` text
infix:

Index       0       1       2       3       4       5
          +-------+-------+-------+-------+-------+-------+
Value     |   A   |   +   |   B   |   *   |   C   |  '\0' |
          +-------+-------+-------+-------+-------+-------+
```
Initially:
``` text
Stack: empty
top = -1

Postfix: empty
k = 0
```
Step 1 --- Read `A`
`i = 0`, so `c = 'A'`.
`isalnum('A')` is true, so the program executes:
``` c
postfix[k++] = c;
```
It stores `A` at `postfix[0]` and increments `k`.
``` text
Stack:
(empty)
top = -1

Postfix:
Index       0
          +-------+
Value     |   A   |
          +-------+

k = 1
```
Why? Operands go directly into postfix.
Step 2 --- Read `+`
`i = 1`, so `c = '+'`.
It is not an operand or parenthesis, so the operator-handling branch
runs. The stack is empty, so the `while` condition is false. The program
pushes `+`.
``` text
Stack:

Index       0
          +-------+
Value     |   +   |
          +-------+
              ^
             top = 0

Postfix: A
k = 1
```
Why? The operator waits until the algorithm knows it can safely be
output.
Step 3 --- Read `B`
`i = 2`, so `c = 'B'`.
The program appends `B` to postfix.
``` text
Stack:
  +
top = 0

Postfix:
Index       0       1
          +-------+-------+
Value     |   A   |   B   |
          +-------+-------+

k = 2
```
Why? Operands are output immediately, but `+` remains on the stack.
Step 4 --- Read `*`
`i = 3`, so `c = '*'`.
The top of the stack is `+`.
``` text
precedence('+') = 1
precedence('*') = 2

Is 1 > 2? No.
Is 1 == 2? No.
```
The `while` condition is false, so nothing is popped. The program pushes
`*`.
``` text
Stack (bottom -> top):

          +-------+
          |   *   | <- top = 1
          +-------+
          |   +   |
          +-------+

Postfix: AB
k = 2
```
Why? Multiplication has higher precedence than addition, so `*` must
be processed first.
Step 5 --- Read `C`
`i = 4`, so `c = 'C'`.
It is an operand, so the program appends it to postfix.
``` text
Stack (bottom -> top):
  +
  *
top = 1

Postfix:
Index       0       1       2
          +-------+-------+-------+
Value     |   A   |   B   |   C   |
          +-------+-------+-------+

k = 3
```
The input loop now reaches the string's terminating `'\0'` and stops.
Step 6 --- Empty the remaining stack
The program runs:
``` c
while (top != -1) {
    postfix[k++] = pop();
}
```
First iteration:
`pop()` returns `*`.
`*` is stored at `postfix[3]`.
`k` becomes `4`.
`top` becomes `0`.
Second iteration:
`pop()` returns `+`.
`+` is stored at `postfix[4]`.
`k` becomes `5`.
`top` becomes `-1`.
The stack is now empty.
``` text
Final postfix array:

Index       0       1       2       3       4       5
          +-------+-------+-------+-------+-------+-------+
Value     |   A   |   B   |   C   |   *   |   +   |  '\0' |
          +-------+-------+-------+-------+-------+-------+

Postfix = ABC*+
k = 5
top = -1
```
The output is:
``` text
Postfix expression: ABC*+
```
10. Entire conversion at a glance
    Step  Character  Action                    Stack (bottom → top)   Postfix
---
       0     ---     Initialize                Empty                  Empty
       1     `A`     Output operand            Empty                  `A`
       2     `+`     Push operator             `+`                    `A`
       3     `B`     Output operand            `+`                    `AB`
       4     `*`     Push; higher precedence   `+ *`                  `AB`
       5     `C`     Output operand            `+ *`                  `ABC`
       6     End     Pop `*`                   `+`                    `ABC*`
       7     End     Pop `+`                   Empty                  `ABC*+`

The rules to remember
Operand: immediately append it to postfix.
Opening parenthesis: push it.
Closing parenthesis: pop until `(`, then discard `(`.
Operator: pop operators that should come first, then push the
current operator.
End of input: pop all remaining operators and terminate the
output string.
11. What happens with parentheses?
Consider:
``` text
(A+B)*C
```
The opening parenthesis is pushed. `A` and `B` are appended to postfix,
and `+` is pushed.
When `)` is encountered, the program pops `+` into postfix and discards
`(`. It then processes `*` and `C`.
``` text
Input:   ( A + B ) * C

When ')' arrives:
Stack:   ( +
Output:  AB

Pop '+':
Stack:   (
Output:  AB+

Discard '(':
Stack:   empty
Output:  AB+

Read '*':
Stack:   *

Read 'C':
Stack:   *
Output:  AB+C

End: pop '*'
Stack:   empty
Output:  AB+C*
```
Final postfix expression:
``` text
AB+C*
```
The parentheses force addition to be completed before multiplication.
12. Practice trace: `A^B^C`
This example tests associativity.
Because `^` is right-associative, the second `^` does not pop the first
one.
---
Character         Action               Stack (bottom →   Postfix
top)
---
`A`               Output operand       Empty             `A`
`^`               Push                 `^`               `A`
`B`               Output operand       `^`               `AB`
`^`               Equal precedence;    `^ ^`             `AB`
current `^` is  
right-associative,  
so do not pop
`C`               Output operand       `^ ^`             `ABC`
End               Pop both `^`         Empty             `ABC^^`
operators
Result:
``` text
ABC^^
```
13. Important limitations in the current code
The program demonstrates the standard conversion algorithm, but it has
limitations:
No stack overflow check. `push()` does not check whether `top`
has reached `MAX - 1`. A long or malformed expression can write
beyond the array.
No complete expression validation. Mismatched parentheses,
consecutive operators, and unsupported characters may produce
incorrect output rather than an error.
Single-character operands only. `isalnum()` treats each letter
or digit as a separate operand. For example, `12+34` is processed
character by character rather than as two multi-digit numbers.
No spaces in input. `scanf("%99s", infix)` stops at whitespace,
so `A + B` is not read as one complete expression.
Global stack state. `top` is global and is not reset at the
start of `infixtoPostfix()`. This is fine for a single conversion in
this program, but a reusable function should reset its stack state
before each conversion.
Unmatched opening parentheses. The final cleanup loop will pop a
remaining `(` into the output. A more robust version should detect
and report this error.
For a basic data structures exercise, the program illustrates the main
algorithm. These checks are important for a robust implementation.
14. Five key exam points
1. `top = -1` means empty
`push()` increments `top` and stores. `pop()` returns the top element
and decrements `top`.
2. Operands go directly to postfix
Letters and digits are appended immediately.
3. Operators use the stack
Compare precedence and associativity before pushing a new operator.
4. Parentheses create boundaries
When `)` is encountered, pop until `(`, then discard the `(`.
5. Finish by emptying the stack
Pop remaining operators and add `'\0'` so the output is a valid C
string.
Final mental model
The postfix array builds the answer, while the stack temporarily
stores operators until the algorithm knows the correct time to output
them.
Once that distinction makes sense, the rest of the code becomes much
easier to understand.
