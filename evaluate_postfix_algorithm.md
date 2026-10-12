# Evaluation of Postfix Expression

## 1. Concept

A postfix expression can be evaluated using a **single left-to-right scan and one stack of operand values**.

Unlike infix expressions, postfix expressions do not require parentheses or operator precedence rules during evaluation. The position of each operator determines which operands it applies to.

### Basic Idea

1. Scan the postfix expression from left to right.
2. If the token is an operand, push its numeric value onto the stack.
3. If the token is an operator, pop the two most recently pushed operands.
4. Apply the operator to these operands.
5. Push the result back onto the stack.
6. After scanning the entire expression, the stack contains exactly one value: the final result.

---

## 2. Algorithm — Evaluate Postfix

```text
Algorithm EvaluatePostfix(postfix)

1. Initialize an empty stack.

2. Scan postfix from left to right.
   For each token:

   a. If the token is an operand:
      Push its numeric value onto the stack.

   b. If the token is an operator (+, -, *, /, ^):
      op2 = pop()
      op1 = pop()

      result = op1 operator op2

      push(result)

3. After the scan is complete:
   Return pop() as the final result.
```

### Important Rule: Operand Order

**The order of popping operands is critical.**

When an operator is encountered:

- The **first value popped** is `op2`, the right-hand operand.
- The **second value popped** is `op1`, the left-hand operand.

This happens because a stack follows the **LIFO (Last In, First Out)** principle.

For example, consider the postfix expression:

```text
62-
```

The stack contains `6` at the bottom and `2` at the top.

When `-` is encountered:

```text
op2 = pop() = 2
op1 = pop() = 6

result = op1 - op2
       = 6 - 2
       = 4
```

Reversing the operands would incorrectly produce `2 - 6 = -4`.

> **VTU Exam Tip:** Operand order does not affect addition and multiplication, but it matters for subtraction and division. Reversing the operands is a common error in postfix evaluation questions.

---

## 3. Worked Example 1 — Simple Expression

Evaluate the postfix expression:

```text
62+31-*
```

The equivalent infix expression is:

\[
(6+2)\times(3-1)
\]

### Step-by-Step Evaluation

| Token Scanned | Action Performed | Stack (Bottom → Top) |
|:---:|---|:---|
| `6` | Push `6` | `6` |
| `2` | Push `2` | `6, 2` |
| `+` | Pop `2`, pop `6`; compute `6 + 2 = 8`; push `8` | `8` |
| `3` | Push `3` | `8, 3` |
| `1` | Push `1` | `8, 3, 1` |
| `-` | Pop `1`, pop `3`; compute `3 - 1 = 2`; push `2` | `8, 2` |
| `*` | Pop `2`, pop `8`; compute `8 × 2 = 16`; push `16` | `16` |

### Stack Visualization

The following diagrams show the stack after each operation.

**Step 1: Read `6`**

```text
  ┌───┐
  │ 6 │ ← TOP
  └───┘
```

**Step 2: Read `2`**

```text
  ┌───┐
  │ 2 │ ← TOP
  ├───┤
  │ 6 │
  └───┘
```

**Step 3: Read `+`**

Pop `2` and `6`, calculate `6 + 2 = 8`, and push the result.

```text
  ┌───┐
  │ 8 │ ← TOP
  └───┘
```

**Step 4: Read `3`, then `1`**

```text
  ┌───┐
  │ 1 │ ← TOP
  ├───┤
  │ 3 │
  ├───┤
  │ 8 │
  └───┘
```

**Step 5: Read `-`**

Pop `1` and `3`, calculate `3 - 1 = 2`, and push the result.

```text
  ┌───┐
  │ 2 │ ← TOP
  ├───┤
  │ 8 │
  └───┘
```

**Step 6: Read `*`**

Pop `2` and `8`, calculate `8 × 2 = 16`, and push the result.

```text
  ┌────┐
  │ 16 │ ← TOP
  └────┘
```

### Final Result

\[
(6+2)\times(3-1)=8\times2=\boxed{16}
\]

Therefore, the value of the postfix expression `62+31-*` is **16**.

---

## 4. Worked Example 2 — Larger Expression

Evaluate the postfix expression:

```text
53+62-*35+*
```

The equivalent infix expression is:

\[
((5+3)\times(6-2))\times(3+5)
\]

### Step-by-Step Evaluation

| Token | Action Performed | Stack (Bottom → Top) |
|:---:|---|:---|
| `5` | Push `5` | `5` |
| `3` | Push `3` | `5, 3` |
| `+` | Pop `3`, pop `5`; compute `5 + 3 = 8`; push `8` | `8` |
| `6` | Push `6` | `8, 6` |
| `2` | Push `2` | `8, 6, 2` |
| `-` | Pop `2`, pop `6`; compute `6 - 2 = 4`; push `4` | `8, 4` |
| `*` | Pop `4`, pop `8`; compute `8 × 4 = 32`; push `32` | `32` |
| `3` | Push `3` | `32, 3` |
| `5` | Push `5` | `32, 3, 5` |
| `+` | Pop `5`, pop `3`; compute `3 + 5 = 8`; push `8` | `32, 8` |
| `*` | Pop `8`, pop `32`; compute `32 × 8 = 256`; push `256` | `256` |

### Final Result

\[
((5+3)\times(6-2))\times(3+5)
\]

\[
=(8\times4)\times8
\]

\[
=32\times8=\boxed{256}
\]

Therefore, the value of the postfix expression `53+62-*35+*` is **256**.

---

## 5. Key Points to Remember

- **Operands:** Push their numeric values onto the stack.
- **Operators:** Pop two operands, perform the operation, and push the result.
- **Operand order:** The first popped value is the right operand (`op2`); the second is the left operand (`op1`).
- **Final result:** A valid postfix expression leaves exactly one value on the stack.
- **Time complexity:** \(O(n)\), where \(n\) is the number of tokens.
- **Space complexity:** \(O(n)\) in the worst case, where \(n\) is the number of tokens.

### Common Mistakes

| Mistake | Correct Approach |
|---|---|
| Pushing operators onto the operand stack | Push only operands and intermediate results. |
| Reversing operands during subtraction | Calculate `op1 - op2`. |
| Reversing operands during division | Calculate `op1 / op2`. |
| Forgetting to push the intermediate result | Push every computed result back onto the stack. |
| Ending with multiple stack values | Verify that the postfix expression is valid and exactly one value remains. |

---

## 6. Summary

Postfix evaluation uses a stack to process an expression from left to right. Operands are pushed onto the stack, while operators consume the top two operands and replace them with their computed result.

The essential rule is:

```text
op2 = pop()
op1 = pop()

result = op1 operator op2

push(result)
```

Once the entire expression has been processed, the remaining stack value is the final answer.
