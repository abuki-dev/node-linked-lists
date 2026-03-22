# Node-Based Linked Lists Implementation

A comprehensive C++ collection demonstrating the implementation and manipulation of the three fundamental types of Linked Lists. This repository serves as a practical guide for mastering pointer management, dynamic memory allocation, and linear data structures.

## 🚀 Features

- **Singly Linked List:** Standard one-way traversal with insertion and deletion at any position.
- **Doubly Linked List:** Efficient two-way traversal using `prev` and `next` pointers, featuring both Forward and Backward display modes.
- **Circular Linked List:** A closed-loop system where the last node points back to the head, ideal for buffer-style logic.
- **Robust CLI:** Interactive menu system with input validation to prevent crashes from non-integer entries.
- **UX Visuals:** Includes a simulated `loading()` bar to provide clear feedback during pointer re-linking.

## 🛠️ Technical Overview

### Core Logic

- **Memory Management:** Strictly uses `new` for allocation and `delete` for deallocation to ensure zero memory leaks during node removal.
- **Node Architecture:** Objects contain `int data` and directional pointers (`*next`, `*prev`).
- **Traversal Algorithms:** Linear search implementations for `InsertLeft`, `InsertRight`, and `DeleteByPosition`.

### Complexity Reference

| Operation        | Singly | Doubly | Circular |
| :--------------- | :----- | :----- | :------- |
| **Insert Front** | O(1)   | O(1)   | O(n)\*   |
| **Insert End**   | O(n)   | O(1)   | O(n)     |
| **Search**       | O(n)   | O(n)   | O(n)     |
| **Delete Pos**   | O(n)   | O(n)   | O(n)     |

_\*O(n) in this implementation due to head-to-tail traversal requirement._

## 🖥️ Getting Started

### Clone the Repository

```bash
git clone git@github.com:abuki-dev/node-linked-lists.git
cd node-linked-lists
```
