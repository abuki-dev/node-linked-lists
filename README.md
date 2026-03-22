# University Data Structure System: Linked Lists

A comprehensive C++ CLI application demonstrating the implementation and manipulation of three types of Linked Lists. This project was developed as part of the Software Engineering curriculum to master pointer management and dynamic memory allocation.

## 🚀 Features

- **Singly Linked List:** Standard one-way traversal with insertion and deletion at any position.
- **Doubly Linked List:** Two-way traversal (`prev` and `next` pointers) with forward and backward display modes.
- **Circular Linked List:** A closed-loop system where the tail connects back to the head.
- **Robust Input Validation:** Prevents program crashes from non-integer inputs.
- **Interactive UI:** Includes a simulated processing animation for better user feedback.

## 🛠️ Technical Implementation

### Data Structures

- **Nodes:** Objects containing `int data`, and pointers for `*next` and `*prev`.
- **Memory Management:** Manual allocation using `new` and deallocation using `delete` to prevent memory leaks.

### Algorithms

- **Search-based Insertion:** `InsertLeft` and `InsertRight` use linear search to find target values before linking new nodes.
- **Position-based Deletion:** Traverses to a specific index to re-link surrounding nodes.

## 🖥️ How to Run

1. **Prerequisites:** Ensure you have a C++ compiler (like `g++`) installed.
2. **Compilation:**
   ```bash
   g++ main.cpp -o LinkedListSystem
   ```
