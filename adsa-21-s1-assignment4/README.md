# Assignment 4 — Minimum Cost Spanning Tree (Build & Destroy)

## Description

Given an undirected graph along with a **build cost** and a **destroy cost** for each edge, transform the graph into a **spanning tree** (fully connected, acyclic) at minimum total cost.

- If the graph contains cycles, remove edges (cheapest first) until no cycle remains
- If the graph is disconnected, add edges (cheapest first) until all nodes are connected

## Algorithm

1. **Find connected components** (`dfsLook`): DFS over the adjacency matrix to identify all connected subgraphs
2. **Remove cycles** (`goDestroy`): for each component containing a cycle, greedily remove the lowest-cost redundant edge while preserving connectivity
3. **Connect components** (`goBuild`): greedily pick the lowest-cost edge between disconnected components until the graph is fully connected

## Input Format

A single line with three matrices separated by spaces:

```
<adjacency matrix> <build cost matrix> <destroy cost matrix>
```

- Rows within each matrix are separated by `,`, elements are adjacent characters
- Adjacency matrix: `0` (no edge) or `1` (edge exists)
- Cost matrices: uppercase `A–Z` (cost 0–25) or lowercase `a–z` (cost 26–51)

## Examples

```
Input:  011,101,110 ABC,BAC,CAB ABC,BAC,CAB
        (complete graph K3 — remove the cheapest edge)
Output: 1

Input:  010,101,010 AAA,AAA,AAA AAA,AAA,AAA
        (already a spanning tree — no operations needed)
Output: 0
```

## Build & Run

```bash
g++ -o a4 main.cpp
echo "011,101,110 ABC,BAC,CAB ABC,BAC,CAB" | ./a4
```

## Known Issues

- `goBuild` contains a `break` that exits after one pass, causing incorrect results when there are more than two disconnected components
- `goBuild` only checks one edge direction (`aBuild[row][col]`), potentially missing a lower-cost edge in the reverse direction
- `dfsLook` uses fragile conditions based on specific multiples of `size` to decide which components to record, which may produce incorrect component lists
