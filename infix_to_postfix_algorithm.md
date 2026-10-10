# Why Postfix Notation Matters for Computers

Infix expressions require the evaluator to understand operator precedence and associativity and to use parentheses to override them. This makes machine evaluation more complicated.

**Postfix (and prefix) notation removes ambiguity.** No parentheses or operator precedence rules are needed during evaluation because the position of each operator unambiguously determines which operands it applies to.

Compilers may transform infix expressions into postfix notation or other intermediate representations before evaluation or code generation.

---

## Operator Precedence and Associativity

| Operator | Meaning | Precedence (Higher = Binds Tighter) | Associativity |
|:---:|---|:---:|:---:|
| `^` | Exponentiation | 3 (Highest) | Right to Left |
| `*` | Multiplication | 2 | Left to Right |
| `/` | Division | 2 | Left to Right |
| `+` | Addition | 1 | Left to Right |
| `-` | Subtraction | 1 | Left to Right |
| `( )` | Parentheses | Override normal precedence | — |

### Important Notes

- **Precedence:** Determines which operator is evaluated first.
- **Associativity:** Determines the evaluation order when operators have equal precedence.
- **Parentheses:** Override normal operator precedence and force the enclosed expression to be evaluated first.
- **Postfix notation:** Operators appear after their operands, eliminating the need for parentheses and precedence rules during evaluation.

> **Note:** In C, `^` represents bitwise XOR, not exponentiation. The exponentiation precedence shown above applies to mathematical notation and languages that use `^` for exponentiation.

---

## Infix to Postfix Conversion

### Idea

Scan the infix expression from left to right.

- **Operands** go directly to the output.
- **Operators** are temporarily held on a stack so that higher-precedence operators can be emitted before lower-precedence ones.
- **Parentheses** determine which operators must be processed first.

A stack uses the **Last In, First Out (LIFO)** principle, making it suitable for managing operators during conversion.

---

## Algorithm: Infix to Postfix

### Pseudocode

```text
Algorithm InfixToPostfix(infix)

1. Initialize an empty stack and an empty output string "postfix".

2. Scan infix from left to right. For each character ch:

   a. If ch is an operand (letter or digit):
         Append ch to postfix.

   b. If ch is '(':
         Push ch onto the stack.

   c. If ch is ')':
         Pop from the stack and append each symbol to postfix
         until '(' is encountered.
         Discard '(' without adding it to postfix.

   d. If ch is an operator (+, -, *, /, ^):

         While the stack is not empty AND
               the top of the stack is not '(' AND
               (
                   precedence(top of stack) > precedence(ch)
                   OR
                   (
                       precedence(top of stack) == precedence(ch)
                       AND ch is left-associative
                   )
               ):

               Pop the top operator and append it to postfix.

         Push ch onto the stack.

3. After scanning the entire infix expression:
      Pop all remaining operators from the stack
      and append them to postfix.

4. Return postfix.
```

### Key Points to Remember

1. Operands are added directly to the postfix output.
2. Opening parentheses are pushed onto the stack.
3. Closing parentheses trigger popping until the matching opening parenthesis is found.
4. Operators are popped according to precedence and associativity.
5. After scanning the expression, all remaining operators are popped into the output.
6. Parentheses are never included in the final postfix expression.
