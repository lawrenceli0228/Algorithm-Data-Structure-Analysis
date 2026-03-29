# Assignment 1 — Karatsuba Large Number Multiplication

## Description

Implement **addition** and **multiplication** (via Karatsuba algorithm) for arbitrarily large integers in any given base.

## Algorithms

- **`add`**: Digit-by-digit addition with carry; handles negative operands by delegating to subtraction
- **`sub`**: Digit-by-digit subtraction with borrow; automatically determines sign of result
- **`KaratsubaMult`**: Divide-and-conquer Karatsuba algorithm
  - Splits each n-digit number into high part `a1` and low part `a0`
  - Recursively computes p0=a0×b0, p2=a1×b1, p1=(a1+a0)×(b1+b0)
  - Result = p2×B^(2k) + (p1−p2−p0)×B^k + p0
  - Time complexity: O(n^1.585), faster than naive O(n^2)

## Input Format

```
<number1> <number2> <base b>
```

## Output Format

```
<addition result> <multiplication result>
```

## Examples

```
Input:  123 456 10
Output: 579 56088

Input:  1010 1101 2
Output: 10111 10000010
```

## Build & Run

```bash
g++ -o a1 main.cpp
echo "123 456 10" | ./a1
```

## Known Issues

- When either operand is `0`, multiplication returns an empty string instead of `0`
  - Cause: the base case `while(decimalR > 0)` never executes when the product is zero
