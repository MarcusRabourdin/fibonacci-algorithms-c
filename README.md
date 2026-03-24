# Fibonacci Algorithms in C

This project implements several methods to compute the Fibonacci sequence in C, illustrating different algorithmic approaches and their trade-offs.

## Implemented Methods

### Recursive
A direct implementation based on the mathematical definition. It is simple but highly inefficient due to repeated computations, resulting in exponential time complexity.

### Iterative
Computes Fibonacci numbers using a loop and keeps track of the two previous values. This method runs in linear time and is efficient for most practical uses.

### Matrix Exponentiation
Uses fast exponentiation of a 2x2 matrix to compute the nth Fibonacci number. This method runs in logarithmic time and is one of the most efficient exact approaches.

### Constant Time (Binet's Formula)
Uses a closed-form mathematical formula involving powers of irrational numbers. While theoretically constant time, it relies on floating-point arithmetic and may introduce precision errors for larger values.

## Compilation

To compile the project:

```sh
make
