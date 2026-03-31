# Algorithm & Data Structure Analysis

Course assignments from **ADSA 2021 Semester 1**, implementing classic algorithms and data structures in C++.

## Assignments

### Assignment 1 — Karatsuba Large Number Multiplication
**Topic:** Arbitrary-precision integer arithmetic using divide-and-conquer.

- Represents numbers as strings in an arbitrary base
- Implements addition and subtraction with carry/borrow propagation
- **Karatsuba algorithm**: splits each n-digit number into high/low halves and recursively computes three sub-products, achieving **O(n^1.585)** vs naive O(n²)

**Input:** Two numbers and a base → **Output:** `<sum> <product>`

---

### Assignment 2 — AVL Self-Balancing Binary Search Tree
**Topic:** Full AVL tree implementation with insert, delete, and traversal.

- Node struct with `data`, `left`, `right`, and `parent` pointers
- Height calculation and balance factor computed recursively
- Four rotation types: Left, Right, Left-Right, Right-Left
- Rebalancing walks up from the affected node after every insert/delete
- Deletion handles all three cases: leaf, one child, two children (in-order predecessor)
- Traversals: pre-order, in-order, post-order

**Input:** Space-separated `A<num>` (insert) / `D<num>` (delete) operations + traversal type (`PRE`/`IN`/`POST`)

---

### Assignment 3 — Hash Table with Open Addressing
**Topic:** Fixed-size hash table using linear probing and tombstone deletion.

- 26-slot array (indexed by last character of key, `a`=0 … `z`=25)
- Collision resolution via **linear probing** with wraparound
- Deletion uses **tombstone marking** to preserve probe sequences
- Search stops at `"never used"` slots, skips tombstones

**Input:** Space-separated `A<word>` / `D<word>` operations → **Output:** all occupied keys in slot order

---

### Assignment 4 — Minimum Cost Spanning Tree
**Topic:** Transform a graph into a minimum spanning tree by greedily destroying cycle edges and building missing edges.

- Graph stored as adjacency, build-cost, and destroy-cost matrices
- Edge costs encoded as characters (`A–Z` → 0–25, `a–z` → 26–51)
- **DFS** for connected component detection
- `goDestroy`: for each component with a cycle, greedily removes the cheapest redundant edge while maintaining connectivity
- `goBuild`: greedily picks the cheapest cross-component edge to merge disconnected components

**Input:** Three space-separated matrices → **Output:** total integer cost (build + destroy)

---

## Language

All assignments are implemented in **C++**.

## Structure

```
.
├── adsa-21-s1-assignment1/   # Karatsuba multiplication
│   ├── main.cpp
│   └── README.md
├── adsa-21-s1-assignment2/   # AVL tree
│   ├── main.cpp
│   └── README.md
├── adsa-21-s1-assignment3/   # Hash table (linear probing)
│   ├── main.cpp
│   └── README.md
└── adsa-21-s1-assignment4/   # Minimum cost spanning tree
    ├── main.cpp
    └── README.md
```
