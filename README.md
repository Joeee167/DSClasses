## Doubly Linked List (DLL) Implementation

# Overview
   - This project implements a Doubly Linked List (DLL) in C++ using templates. The clsDblLinkedList class provides various methods for inserting, traversing, and managing nodes efficiently.

# Features
  - Supports generic data types using templates.
  - Insert elements at the beginning or end of the list.
  - Print the list contents.
  - Get the size of the list.
  - Insert elements after a given node.


# Installation
  To use this project, follow these steps:

  1. Clone the repository:
  ```
   git clone <repo-url>
   cd DLLClass
  ```

  2. Compile the code:
  ```
    g++ -o dll_example DLLClass.cpp
  ```

  3. Run the program:
  ```
    ./dll_example
  ```

# Methods Explained

```
   InsertAtBeginning(T x)
```

-> Inserts an element at the start of the list.

```
   InsertAtEnd(T x)
```
-> Adds an element to the end of the list.

```
   PrintList()
```

-> Displays the list contents.

```
   Size()
```

-> Returns the number of elements in the list.

```
   Clear()
```

-> Clear all the nodes in the list.

```
   Reverse()
```

-> Reverse the list nodes
