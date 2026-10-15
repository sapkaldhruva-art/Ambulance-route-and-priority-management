#  Ambulance Management System in C++

##  About the Project

The Ambulance Management System is a simple C++ project that uses a **Singly Linked List** to manage ambulances according to their emergency priority.

The ambulance with the highest priority is placed first and dispatched first.

This project demonstrates the practical use of Data Structures and Algorithms (DSA).

##  Features

*  Add a new ambulance
*  Display all ambulances according to priority
*  Dispatch the highest-priority ambulance
*  Count the total number of ambulances
*  Menu-driven program
*  Priority-based insertion using a Singly Linked List

##  Technologies Used

* **Language:** C++
* **Concept:** Singly Linked List
* **Topic:** Data Structures and Algorithms (DSA)

##  How to Run

### 1. Clone the Repository

```bash
git clone YOUR_REPOSITORY_URL
```

### 2. Open the Project Folder

```bash
cd YOUR_REPOSITORY_NAME
```

### 3. Compile the Code

Using GCC:

```bash
 main.cpp -o ambulance
```

### 4. Run the Program

**Windows:**

```bash
ambulance.exe
```

**Linux / 
:**

```bash
./ambulance
```

##  How It Works

Each node contains three parts:

* `id` — Ambulance identification number
* `priority` — Emergency priority from 1 to 5
* `next` — Pointer to the next node

**Priority Rules:**

* Priority 1 = Highest priority
* Priority 5 = Lowest priority

Ambulances are automatically arranged in ascending order of priority.

### Example

| Ambulance ID | Priority |
| ------------ | -------: |
| 101          |        3 |
| 102          |        1 |
| 103          |        2 |

The resulting list will be:

```text
Ambulance 102 → Ambulance 103 → Ambulance 101 → NULL
```

When the dispatch operation is selected, Ambulance 102 is removed first because it has the highest priority.

##  Learning Outcomes

* Understanding Singly Linked Lists
* Implementing priority-based insertion
* Learning node creation and pointer operations
* Understanding insertion and deletion in linked lists
