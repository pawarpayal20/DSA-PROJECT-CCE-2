# Warehouse Location Explorer using DFS

**Dev-C++ compatibility:** This version uses C++98 features and avoids `unordered_map`, `auto`, lambdas, and range-based loops.

## Problem
Represent warehouse locations as graph vertices and aisles as edges. Apply Depth-First Search (DFS) to explore locations reachable from a selected location.

## Run in Dev-C++
1. Extract the ZIP.
2. Open `main.cpp` in Dev-C++.
3. Select **Execute > Compile & Run**.

## Sample input
```text
6
Receiving
Storage
Packing
Quality
Dispatch
Loading
6
Receiving Storage
Storage Packing
Packing Quality
Quality Dispatch
Dispatch Loading
Storage Quality
Receiving
```

## Expected result
DFS starts at `Receiving` and reaches all six connected locations. The exact order depends on the aisle entry order.

## Complexity
Time: `O(V + E)`. Auxiliary space: `O(V)`.
