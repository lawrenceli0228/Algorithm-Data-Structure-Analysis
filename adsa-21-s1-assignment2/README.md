# Assignment 2 — AVL Self-Balancing Binary Search Tree

## Description

Implement a fully functional **AVL tree** supporting insertion, deletion, and traversal, with automatic rebalancing after every modification.

## Data Structures

- `Node`: tree node holding `data`, `left`, `right`, and `parent` pointers
- `AvlTrees`: AVL tree class maintaining a `root` pointer

## Supported Operations

| Operation | Description |
|-----------|-------------|
| `insert(value)` | Insert a value; duplicates are ignored; rebalances after insertion |
| `deLete(value)` | Delete a value; no-op if not found; rebalances after deletion |
| `printAvl(order)` | Print tree nodes in the specified traversal order |

## Rotation Types

- **Left rotation** (`leftRotation`): fixes left-left imbalance
- **Right rotation** (`rightRotation`): fixes right-right imbalance
- **Left-Right rotation** (`LefRitRotation`): fixes left-right imbalance
- **Right-Left rotation** (`RitLefRotation`): fixes right-left imbalance

## Input Format

A single line of space-separated operations, ending with a traversal command:

```
A<num> D<num> ... <PRE|IN|POST>
```

- `A<num>`: insert a number
- `D<num>`: delete a number
- `PRE` / `IN` / `POST`: pre-order / in-order / post-order traversal

## Examples

```
Input:  A5 A3 A7 A1 A4 IN
Output: 1 3 4 5 7

Input:  A5 A3 A7 D3 PRE
Output: 5 7

Input:  A5 D5 IN
Output: EMPTY
```

## Build & Run

```bash
g++ -o a2 main.cpp
echo "A5 A3 A7 IN" | ./a2
```
