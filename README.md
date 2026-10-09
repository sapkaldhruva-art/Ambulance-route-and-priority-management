# Ambulance Route and Priority Management

A simple C++ project that uses a **singly linked list** to arrange ambulances by priority.

## Features
- Add an ambulance with an ID and priority.
- Keep the list sorted by priority.
- Display ambulances in priority order.

## Priority Rules
- `1` = Highest priority
- `2` = Medium priority
- `3` = Lowest priority

## Example Output
```text
Ambulance Priority List
Ambulance 102 | Priority 1
Ambulance 103 | Priority 2
Ambulance 101 | Priority 3
```

## How to Run
Compile and run `main.cpp` using a C++ compiler:

```bash
g++ main.cpp -o ambulance
./ambulance
```

On Windows, run the generated `ambulance.exe`.

## Data Structure
**Singly Linked List** — each node stores an ambulance ID, its priority, and a pointer to the next node.
