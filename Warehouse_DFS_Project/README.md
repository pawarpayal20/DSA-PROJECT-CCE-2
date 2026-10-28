# Warehouse Location Management Using Graph and DFS

**DSA Unit V (CO5) Project | Dev-C++ Compatible**

## Problem Statement
Represent warehouse locations and connecting aisles as a graph, and apply DFS to explore all locations reachable from a selected location.

## Overview
This menu-driven C++ console application represents warehouse locations as **vertices** and bidirectional aisles as **edges**. It stores the graph in an **adjacency matrix** and uses recursive **Depth First Search (DFS)** to explore all reachable locations.

## Features
1. Add warehouse locations (up to 50).
2. Connect two locations with an aisle.
3. Display all locations and their IDs.
4. Display the adjacency matrix.
5. Show direct connections of a selected location.
6. Perform DFS from a user-selected location and count reachable/unreachable locations.
7. Exit.

## Requirements
- Dev-C++ or any C++ compiler supporting C++11 or earlier standard features.
- No external dependencies.

## How to Run in Dev-C++
1. Open Dev-C++.
2. Open `warehouse_dfs.cpp`.
3. Select **Execute > Compile & Run** (often F11).
4. Use the menu to add locations and aisles, then run DFS.

## Example Input
Add locations using menu option 1, one at a time:

| ID | Location |
|---|---|
| 0 | Main Storage |
| 1 | Loading Area |
| 2 | Packing Section |
| 3 | Dispatch Area |
| 4 | Cold Storage |

Use menu option 2 to add aisles:
- `0 1`
- `0 2`
- `1 3`
- `2 4`

Then choose option 6 and enter starting ID `0`.

## Sample Output
```text
DFS Traversal:
Main Storage -> Loading Area -> Dispatch Area -> Packing Section -> Cold Storage -> END
Reachable locations (including start): 5
Unreachable locations: 0
```

## Graph Representation
The adjacency matrix stores `1` when an aisle exists and `0` otherwise. Since aisles are bidirectional, `graph[a][b]` and `graph[b][a]` are both set to 1.

## DFS Algorithm
1. Mark the current location visited.
2. Print its name.
3. Recursively visit each connected, unvisited location.
4. Count the visited locations after traversal.

## Complexity
- DFS with adjacency matrix: **O(V²)** time in the worst case.
- Adjacency matrix: **O(V²)** space.
- DFS visited array and recursion: **O(V)** additional space.

## Notes
- The application stores data in memory only; locations reset when the program closes.
- DFS explores reachable locations; it does **not** guarantee the shortest route.
- Input location IDs as integers shown in the location list.

## Course Outcome
**CO5: Build, represent, and traverse graphs.**
