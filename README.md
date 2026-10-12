# Data Structures in C Programming

A hands-on collection of **data structure implementations, algorithms, and interactive learning resources written in C**. This repository brings together source code, step-by-step explanations, algorithm walkthroughs, and visual demonstrations to help students understand how data structures work internally.

The goal is simple: **learn the concept, trace the algorithm, run the code, and understand the logic behind it.**

## 📚 Contents

- [Overview](#-whats-inside)
- [Repository Structure](#-repository-structure)
- [Getting Started](#-getting-started)
- [Interactive Visualizer](#-interactive-infix-to-postfix-visualizer)
- [Suggested Learning Path](#-suggested-learning-path)
- [Time Complexity](#-time-complexity-at-a-glance)
- [Limitations](#-current-scope-and-limitations)
- [Contributing](#-contributions)

## 🚀 What's Inside

### 1. Stack Implementation

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. The last element inserted is the first one removed.

| File | Description |
|---|---|
| [`Stacks.c`](./Stacks.c) | Basic stack implementation using a fixed-size array |
| [`stack_dynamicarrays.c`](./stack_dynamicarrays.c) | Stack using dynamically allocated memory with automatic resizing |

Operations covered:

- **Push:** Insert an element at the top.
- **Pop:** Remove the top element.
- **Peek:** Access the top element without removing it.
- **isEmpty:** Check whether the stack is empty.
- **Display:** Print the elements in the stack.

The dynamic-array implementation also demonstrates memory management using `malloc()`, `realloc()`, and `free()`.

### 2. Queue Implementation

A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. The first element inserted is the first one removed.

| File | Description |
|---|---|
| [`queues_staticarray.c`](./queues_staticarray.c) | Queue implementation using a fixed-size array |

Concepts covered include:

- **Enqueue:** Insert an element at the rear.
- **Dequeue:** Remove an element from the front.
- **Peek:** Inspect the front element.
- **Display:** View the elements in the queue.

### 3. Infix-to-Postfix Conversion

Infix notation places operators between operands, while postfix notation places operators after their operands.

For example:

```text
Infix:   A + B * C
Postfix: A B C * +
```

Postfix notation eliminates the need to apply operator precedence rules during evaluation. A stack helps convert infix expressions by managing operators, precedence, associativity, and parentheses.

| File | Description |
|---|---|
| [`infix_to_postfix.c`](./infix_to_postfix.c) | C implementation of infix-to-postfix conversion |
| [`infix_to_postfix_algorithm.md`](./infix_to_postfix_algorithm.md) | Algorithm, pseudocode, precedence, and associativity |
| [`infix_to_postfix_implementation_details.md`](./infix_to_postfix_implementation_details.md) | Detailed explanation of the C implementation and stack operations |
| [`infix_to_postfix_visualiser.html`](./infix_to_postfix_visualiser.html) | Interactive browser-based algorithm visualizer |

The current converter supports single-character operands, the operators `+`, `-`, `*`, `/`, and `^`, and parentheses.

### 4. Postfix Expression Evaluation

Postfix expressions can be evaluated using a stack of operand values. The expression is scanned from left to right, and intermediate results are pushed back onto the stack.

For example:

```text
Postfix:  62+
Operation: 6 + 2
Result:   8
```

| File | Description |
|---|---|
| [`evaluate_postfix.c`](./evaluate_postfix.c) | C implementation of postfix expression evaluation |
| [`evaluate_postfix_algorithm.md`](./evaluate_postfix_algorithm.md) | Algorithm, worked examples, stack diagrams, and complexity analysis |

The current evaluator is designed for single-digit operands and supports `+`, `-`, `*`, `/`, and `^`.

## 🗂️ Repository Structure

```text
Data-Structures-in-C-Programming/
│
├── README.md
│
├── Stacks.c
├── stack_dynamicarrays.c
├── queues_staticarray.c
│
├── infix_to_postfix.c
├── infix_to_postfix_algorithm.md
├── infix_to_postfix_implementation_details.md
├── infix_to_postfix_visualiser.html
│
├── evaluate_postfix.c
├── evaluate_postfix_algorithm.md
│
└── visualiser_readme.md
```

## 💻 Getting Started

### Prerequisites

- A C compiler such as GCC or Clang.
- A terminal or command prompt.
- A modern web browser for the interactive visualizer.

### Clone the Repository

```bash
git clone https://github.com/h4mdansheikh/Data-Structures-in-C-Programming.git

cd Data-Structures-in-C-Programming
```

### Compile and Run the Programs

Compile each C file separately because each program contains its own `main()` function.

**Stack implementation**

```bash
gcc Stacks.c -o stack
./stack
```

**Dynamic-array stack**

```bash
gcc stack_dynamicarrays.c -o dynamic_stack
./dynamic_stack
```

**Queue implementation**

```bash
gcc queues_staticarray.c -o queue
./queue
```

**Infix-to-postfix conversion**

```bash
gcc infix_to_postfix.c -o infix_to_postfix
./infix_to_postfix
```

**Postfix expression evaluation**

```bash
gcc evaluate_postfix.c -o evaluate_postfix -lm
./evaluate_postfix
```

The `-lm` flag links the math library required by `pow()` on many GCC-based systems.

On Windows, run the generated `.exe` file instead, for example:

```bash
stack.exe
```

> **Note:** These commands assume GCC is installed and available in your system's PATH. Compile-time success does not guarantee correct behaviour for every input; review and test the implementations before relying on them.

## 🌐 Interactive Infix-to-Postfix Visualizer

The repository includes a standalone HTML visualizer for exploring the infix-to-postfix conversion algorithm.

**Open [`infix_to_postfix_visualiser.html`](./infix_to_postfix_visualiser.html) to begin.**

The visualizer helps you observe how the algorithm processes an expression, stores operators on a stack, and builds the postfix output.

Features include:

- Step-by-step execution.
- Previous and next controls.
- Automatic playback.
- Stack state visualization.
- Postfix output displayed as indexed array cells.
- Execution trace showing the action performed at each step.
- Example expressions for practising precedence and associativity.

The visualizer is built with HTML, CSS, and vanilla JavaScript. It does not require package installation or external dependencies.

### Publish the Visualizer Using GitHub Pages

To make the visualizer accessible through a public URL:

1. Open the repository on GitHub.
2. Navigate to **Settings → Pages**.
3. Under the build and deployment section, select **Deploy from a branch**.
4. Choose the `main` branch and the root folder (`/`).
5. Save the settings and open the published URL once deployment completes.

The actual published URL depends on the repository's GitHub Pages configuration.

## 🧠 Suggested Learning Path

For students learning data structures from the fundamentals, the following order is recommended:

1. **Stacks:** Understand LIFO and practise push, pop, and peek.
2. **Dynamic memory:** Learn how arrays can be allocated and resized dynamically.
3. **Queues:** Understand FIFO and compare it with stack behaviour.
4. **Expression notation:** Learn operator precedence and associativity.
5. **Infix-to-postfix conversion:** Study the algorithm and follow its execution using the visualizer.
6. **Postfix evaluation:** Practise operand order, intermediate calculations, and stack manipulation.

Working through the implementations alongside their explanations can make the underlying logic easier to understand than studying source code alone.

## ⏱️ Time Complexity at a Glance

| Operation or Algorithm | Typical Time Complexity |
|---|---|
| Stack push | O(1) amortized for a dynamic array |
| Stack pop | O(1) |
| Stack peek | O(1) |
| Queue enqueue | O(1) in a suitable array-based queue |
| Queue dequeue | O(1) in a suitable array-based queue |
| Infix-to-postfix conversion | O(n) |
| Postfix evaluation | O(n) |

Here, `n` represents the number of input symbols or tokens, as applicable. These are typical algorithmic complexities, assuming valid input and correctly implemented operations. They are not guarantees that every operation in the current source files handles all edge cases correctly.

## ⚠️ Current Scope and Limitations

This repository is a learning project, and the current implementations have a deliberately limited scope.

- The infix-to-postfix converter works with single-character operands rather than multi-digit numbers or multi-character identifiers.
- The postfix evaluator supports single-digit operands and does not parse whitespace-separated, multi-digit values.
- The queue uses a basic fixed-size array rather than a circular queue.
- Input validation, underflow and overflow handling, and edge cases can be improved in some implementations.
- Each C file is a separate demonstration program rather than part of a combined library.

These limitations also provide opportunities to practise debugging, testing, and improving data structures.

## 🎯 Project Goals

- Develop a practical understanding of data structures implemented in C.
- Connect theoretical concepts with working code.
- Explain algorithms through readable documentation and worked examples.
- Make stack-based expression processing easier to understand through visualization.
- Build a foundation for studying more advanced data structures and algorithms.

## 🤝 Contributions

Contributions that improve code correctness, documentation, readability, testing, or learning resources are welcome.

To contribute:

1. Fork the repository.
2. Create a branch for your changes.
3. Implement and test your improvement.
4. Submit a pull request describing the changes.

## 📄 License

No license is documented in this README. Check the repository for a license file before reusing or redistributing its code.

---

**Explore the code. Trace the algorithms. Understand the fundamentals.**

Repository: [Data Structures in C Programming](https://github.com/h4mdansheikh/Data-Structures-in-C-Programming)
