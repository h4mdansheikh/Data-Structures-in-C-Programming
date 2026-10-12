Algorithm — Evaluate Postfix:
Algorithm EvaluatePostfix(postfix)
1. Initialize an empty stack.
2. Scan postfix from left to right, for each token:
 a. If token is an operand:
 push its numeric value onto the stack.
 b. If token is an operator (+, -, *, /, ^):
 op2 = pop() (the second/right operand — popped first)
 op1 = pop() (the first/left operand)
 result = op1 <operator> op2
 push(result)
3. When the scan is complete, pop the stack; that value is the result.

