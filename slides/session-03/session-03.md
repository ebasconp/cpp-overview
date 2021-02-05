---
title: C++ overview session 3
paginate: true
marp: true
theme: uncover
---

# C++ overview

#### Ernesto Bascón Pantoja

Session 03 - Arrays, pointers and C strings

---

## Contents

- Arrays initialization
- Array decay
- C strings
- Functions to work with C strings
- Multidimensional arrays

---

# Arrays

---

## Arrays

- Sets of elements of same type.
- Stored contiguously.
- Accessibles through its position inside the array [index]
- Known size at compile time.
- Stored in stack or in auto storage.

---

## Arrays

- Size cannot be modified.
- The runtime does not know the array size, it must be handled by the programmer.
- The compiler does not do bound checking, it must be handled by the programmer.

---

## Arrays initialization

```
int main()
{
  int arr[5];
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;
}
```
---

## Arrays initialization

Static arrays are always stored in automatic storage location.

```
int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60 };
}
```

---
## Accessing to array elements

```
int main()
{
    int arr[] = { 125, 4523, 12, 10 };
    std::cout << arr[0] << "\n"; // will print 125
}
```
---
## Array length

- The runtime does not know the array length, so the programmer must store that info somewhere.
- Anyway, the compiler DOES know the array length... When still being arrays.

```
int main()
{
     int arr[] = { 1, 2, 3, 4, 5 };
     std::cout << sizeof(arr) << "\n"; // should print 20.
     std::cout << sizeof(arr) / sizeof(int) << "\n"; // prints 5
}
```
---
## Array iteration

- Using normal for, while, etc. constructs
- Using C++11 range-based for-loop.

---

# Array decay

---

## Array decay

An array can be automatically converted to a pointer to the first element of the array. Example:

```
int main()
{
    int arr[] = { 1912, 3423, 12 };
    int* p = arr;
}

```
---
## Array decay - Pros

- A pointer can point to a stack array or to a heap array.
- Pointer arithmetic can be applied to a pointer.
- Pointer can be moved across the array.

---
## Array decay - Cons

- Actual array length is lost.

---

## Pointer arithmetic on arrays

```
int q[] = { 10, 30, 40, 50, 2, 8 };
int* pq = q;
std::cout << *pq << "\n";       // prints 10
std::cout << *(pq + 2) << "\n"; // prints 40
std::cout << pq[2] << "\n";     // prints 40
```

---


# C strings

---

## C strings

- Strings in C are simply modelled as char-arrays.
- The language provides us string literals.
- Since arrays do not store their length, C strings have a '\0' as their last character.
- String literals add such char to the end of the array.
- Because of that C strings are also called "null-terminated strings".

---

## C strings - Definition

```
const char* hw = "Hello world"; // pointer to a const-string stored in read-only memory
auto hw2 = "Hello world again"; // same as above
char hw3[] = "Hello world again and again"; // string stored in stack
char aux[100];  //array of 100 chars to store a string

```

---

## C strings - Include file

```
#include <cstring>
#include <string.h>
```
---

## C strings - Functions


- **`strlen()`** Computes the string length
- **`strcpy()`** Copies a string to other
- **`strcat()`** Concatenates a string to other
- **`strstr()`** Finds a substring in a string
- **`strcmp()`** Compares two strings
- **`strtok()`** Tokenizes a string

---

## Exercises

- Write a function that inverts chars in a string
- Write a function that sums two matrices
- Write a function that finds the MAX and MIN in an array
- Write a function that trims out a string. `"    Pedro Perez    "` -> `"Pedro Perez"`


