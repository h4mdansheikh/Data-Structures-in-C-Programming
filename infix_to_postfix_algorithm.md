Why postfix matters for computers: infix expressions require the evaluator to know operator precedence and
associativity and to use parentheses to override them, which makes machine evaluation awkward. Postfix (and
prefix) notation removes ambiguity entirely — no parentheses and no precedence rules are needed to evaluate
them, because the position of each operator unambiguously fixes which operands it applies to. This is why
compilers translate infix expressions typed by the programmer into postfix (or a similar form) internally before
evaluating or generating code.

