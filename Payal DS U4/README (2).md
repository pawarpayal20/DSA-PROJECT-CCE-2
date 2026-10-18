# City Skyline Visualization Application using Binary Tree

## Problem Statement
To design and implement a C++ based City Skyline Visualization Application using a Binary Search Tree (BST) to store building heights and visualize the city skyline by displaying the left-side and right-side views of buildings.

## Objective
To implement a Binary Search Tree for storing building heights and provide operations to add buildings, display the skyline, show individual building heights, and display the left-side and right-side views.

## Data Structures Used
- Binary Search Tree (BST)
- Vector

## Operations
- Enter Buildings
- Add More Buildings
- Display Skyline
- Display Building Heights
- Display Left and Right Views
- Exit

## Concepts Used
- C++
- Binary Search Tree (BST)
- Vectors
- Pointers
- Dynamic Memory Allocation
- Recursion
- Tree Insertion
- Memory Management

## Algorithm
1. Start the program.
2. Create an empty vector to store building heights and an empty Binary Search Tree.
3. Display the menu of available operations.
4. Accept the user's choice.
5. Insert valid positive building heights into the vector and BST.
6. Display the skyline using the stored building heights.
7. Display the heights of all buildings.
8. Calculate and display the left-side and right-side views of the buildings.
9. Repeat the operations until the user selects Exit.
10. Release the dynamically allocated memory and stop the program.

## Advantages
- Represents building heights using a Binary Search Tree.
- Provides a visual representation of the city skyline.
- Displays the left-side and right-side views of buildings.
- Allows users to add buildings dynamically.
- Uses vectors for storing and displaying building heights.
- Helps understand BST insertion, pointers, recursion, and dynamic memory management.

## Conclusion
The City Skyline Visualization Application demonstrates the use of a Binary Search Tree and vectors in C++. It allows users to add building heights, visualize the skyline, display all building heights, and view the buildings from the left and right sides. The project provides practical knowledge of tree insertion, pointers, dynamic memory allocation, recursion, and memory management.

## How to Compile and Run
Using a C++ compiler such as g++:

```bash
g++ skyline.cpp -o skyline
./skyline
```

On Windows, run the compiled executable:

```bash
skyline.exe
```

## Note
The Binary Search Tree stores the building heights, while the skyline and left/right side views are calculated from the vector of building heights.
