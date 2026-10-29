Warehouse Location Explorer using DFS

Problem Statement

To represent warehouse locations and connecting aisles as a graph, and apply Depth First Search (DFS) to explore all locations reachable from a selected location.

Objective

To implement DFS in C++ to traverse a warehouse graph and find all locations reachable from a given starting location.

Data Structure Used

- Graph
- Adjacency List
- Vector
- Stack

Operations

- Enter warehouse locations.
- Add connecting aisles between locations.
- Display the warehouse graph.
- Select a starting location.
- Perform Depth First Search (DFS).
- Display the traversal order.
- Display the total number of reachable locations.

Concepts Used

- C++
- Graph
- Depth First Search (DFS)
- Adjacency List
- Vectors
- Classes and Objects
- Pointers
- Stack
- Graph Traversal

Algorithm

1. Start the program.
2. Enter the number of warehouse locations and their names.
3. Enter the number of connecting aisles.
4. Add the aisles between the specified locations to create the graph.
5. Display the warehouse graph with its connected locations.
6. Enter the starting location for DFS.
7. Create a stack and mark all locations as unvisited.
8. Push the starting location onto the stack.
9. Pop a location, mark it as visited, and display its name.
10. Push its unvisited adjacent locations onto the stack.
11. Repeat until the stack becomes empty.
12. Display the traversal order and total number of reachable locations.
13. Stop the program.

Advantages

- Explores all locations reachable from a selected location.
- Helps understand the connectivity of a warehouse.
- Uses a stack to perform graph traversal.
- Avoids visiting the same location repeatedly.
- Can be used to study warehouse aisle connectivity.

Conclusion

The Warehouse Location Explorer demonstrates the implementation of Depth First Search using a graph and an adjacency list in C++. It explores all locations reachable from a selected starting point and displays the traversal order and total number of reachable locations. This project helps in understanding graph traversal, stacks, vectors, and classes.
