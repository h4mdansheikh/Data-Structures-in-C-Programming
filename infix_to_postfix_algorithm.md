## Why Postfix Notation Matters for Computers

Infix expressions require the evaluator to understand operator precedence and associativity and to use parentheses to override them. This makes machine evaluation more complicated.

Postfix (and prefix) notation removes ambiguity. No parentheses or operator precedence rules are needed during evaluation because the position of each operator unambiguously determines which operands it applies to.

Compilers may transform infix expressions into postfix notation or other intermediate representations before evaluation or code generation.

## Operator Precedence and Associativity

| Operator | Meaning                  | Precedence (Higher = Binds Tighter) | Associativity |
|----------|--------------------------|:-----------------------------------:|---------------|
| `^`      | Exponentiation           | 3 (Highest)                         | Right to Left |
| `*`      | Multiplication           | 2                                   | Left to Right |
| `/`      | Division                 | 2                                   | Left to Right |
| `+`      | Addition                 | 1                                   | Left to Right |
| `-`      | Subtraction              | 1                                   | Left to Right |
| `( )`    | Parentheses              | Override normal precedence          | —             |

### Important Notes

- **Precedence:** Determines which operator is evaluated first.
- **Associativity:** Determines the evaluation order when operators have equal precedence.
- **Parentheses:** Override normal operator precedence and force the enclosed expression to be evaluated first.
- **Postfix notation:** Operators appear after their operands, eliminating the need for parentheses and precedence rules during evaluation.

> **Note:** In C, `^` represents bitwise XOR, not exponentiation. The exponentiation precedence shown above applies to mathematical notation and languages that use `^` for exponentiation.


##**Infix to Postfix Conversion**

Idea. Scan the infix expression left to right. Operands go straight to the output. Operators are temporarily held
on a stack so that higher-precedence operators can be emitted before lower-precedence ones, which is exactly
what a stack (LIFO) is good at.

**##Algorithm Infix to Postfix**

Algorithm InfixtoPostfix(infix)
1.Initialise an empty stack and an empty output string "postfix".
2.scan infix from left to right, for each character ch:
    a.If ch is an operanf(letter/digit):
        append ch to postfix
    b.If ch is "(":
        push ch on to the stack
    c.If ch is ")":
        pop from stack and append to postfix
        until the popped symbol is '(';
        discard the '(' (do not output it)
    d.IF ch is an operator (+,-,*,/,^):
        while the stack is not empty AND the top of the stack is not '(' AND
                (precedence(top of stack)>precedence(ch) OR precedencen(top of stack)==precedence(ch) AND ch is left-associative):
                pop from stack and append to postfix
                push ch onto the stack
3. After the scan pop all remaining operators from the stack and append them to postfix
4.Return Postfix

