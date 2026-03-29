# Assignment 3 — Hash Table (Open Addressing)

## Description

Implement a fixed-size hash table using **linear probing** for collision resolution, supporting insert, delete, and lookup operations.

## Design

- **Size**: fixed at 26 slots (corresponding to letters a–z)
- **Hash function**: index of the **last character** of the key string (`'a'=0, 'z'=25`)
- **Collision resolution**: linear probing — scan forward from the hash position
- **Deletion strategy**: tombstone marking; deleted slots are marked `"tombstone"` rather than cleared

## Slot States

| State | Meaning |
|-------|---------|
| `"never used"` | Slot has never been written; search stops here |
| `"occupied"` | Slot currently holds a key |
| `"tombstone"` | Key was deleted; search skips over, insert may reclaim |

## Input Format

A single line of space-separated operations:

```
A<word> D<word> ...
```

- `A<word>`: insert the string
- `D<word>`: delete the string (no-op if not present)

## Output Format

All `occupied` slots printed in slot order, space-separated.

## Examples

```
Input:  Aabc Axyz
Output: abc xyz

Input:  Aabc Axyz Dabc
Output: xyz
```

## Build & Run

```bash
g++ -o a3 main.cpp
echo "Aabc Axyz Dabc" | ./a3
```

## Known Issues

- `add` only checks for duplicates at the exact hash slot; if the key was stored at a probed position, re-inserting it may create **duplicate entries**
