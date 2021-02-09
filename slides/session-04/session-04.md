---
title: C++ overview session 4
paginate: true
marp: true
theme: uncover
---

# C++ overview

#### Ernesto Bascón Pantoja

Session 04 - Multidimensional arrays, dynamic memory allocation, pointers to pointers

---

## Contents

- Multidimensional arrays
- Dynamic memory allocation
- Pointers to pointers

---

# Multidimensional arrays
---

## Multidimensional arrays

```
int p[2][2];
p[0][0] = 4;
p[0][1] = 2;
p[1][0] = 6;
p[1][1] = 10;

```
---

## Multidimensional arrays

```
int p[][2] = { { 4, 2 }, { 5, 10 } };

```

---

## Multidimensional array - Decay
```
int p[][2] = { { 4, 2 }, { 5, 10 } };
int* pp = (int*) p;

std::cout << *pp << "\n";
std::cout << pp[1] << "\n";
std::cout << pp[2] << "\n";
std::cout << pp[3] << "\n";

```

---
# Dynamic memory allocation
---
## Dynamic memory allocation

- Any serious program needs to work with an unknown quantity of data.
- The structures available for stack are not quite enough because their size is fixed.
- Need to ask for memory to the OS whenever we need it.
---

## Dynamic memory allocation

- C++ DOES NOT handle the memory automatically.
- C++11 specifies an interface to plug-in garbage collectors when needed.
- No compiler implemented this.
- C++ provides several tools to handle memory.

---
## Dynamic memory allocation - C ones

- `#include <cstdlib>`

- **`malloc()`** asks bytes to the OS
    - Returns a `void*` pointer to the memory allocated.
    - Returns `nullptr` if fail.
    
- **`free()`** returns bytes to the OS
- **`realloc()`** resizes a previously allocated memory space

---
## Dynamic memory allocation - C++

- Operator **`new`** creates an instance on heap.
    - Returns a pointer of given type when success.
    - throws an exception if fail.

- Operator **`new[]`** creates an array instance of heap.
- Operator **`delete`** releases memory on heap.
- Operator **`delete[]`** releases array memory on heap.

---
# Pointers to pointers
---

## Pointers to pointers

A pointer to a pointer points to an address, that contains a pointer. Example:

```
const char* msg = "Hello world";
const char** msg_p = &msg;
const char*& msg_ref = msg;
```
---

## Pointers to pointers

- They are useful to:
    - Have a pointer returned as function output argument.
    - Store, for example, dynamic arrays of dynamic strings (`char**`)
    - In C++, they can be replaced by references to pointers.

---

## Exercises

1. Create a function that concatenates two strings and returns a newly allocated string.
2. Create a function that creates an empty dynamic string array (nullptr terminated).
3. Create a function that receives the array on 2 and adds it a new string.
4. Create a function that prints the elements in the array on 2.
5. Create a function that releases the memory in the dynamic array.





