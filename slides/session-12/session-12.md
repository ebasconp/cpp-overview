---
title: C++ overview session 11
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 11
## Vectors, sets and maps

###### *Ernesto Bascón Pantoja*

---
## Contents

* `std::string_view`
* `std::vector` & `std::list`
* `std::set` & `std::unordered_set`
---

# std::string_view
---
## std::string_view

- Introduced in C++17
- Is a non-owning constant string
- Stores a pointer to the first character in the array and the number of elements.
- Wraps a `std::string` or a `const char*`
- It is not "zero-terminated string"

---
## std::string_view

```
#include <string_view>

void print_text(const char* s)
{
    std::cout << s << "\n";
}

int main()
{
    print_text("Hello world");
}
```
**PROS:** No performance overhead

**CONS:** Only works with char*

---

## std::string_view

```
void print_text(const std::string& s)
{
    std::cout << s << "\n";
}

int main()
{
    print_text("Hello world");
    print_text("Hello string world"s);
}
```
**PROS:** Works with char* and std::string

**CONS:** With char* needs to create a temporary string

---
## Introducing std::string_view

```
void print_text(const std::string_view& s)
{
    std::cout << s << "\n";
}

int main()
{
    print_text("Hello world");
    print_text("Hello string world"s);
}
```
**PROS:** Works with char* and std::string
**CONS:** No cons!!

---
## std::string_view

- `operator[]`, `at`, `length`, `empty`
- `find`, `substr`, `compare`, `operator<=>`
- `starts_with, ends_with`
- `remove_prefix`, `remove_suffix`
- `operator ""sv`
- `constexpr` friendly

---
# std::array<T, N>
---
## std::array<T, N>

- Introduced in C++11
- Standard library wrapper around stack-based arrays.
- Number of elements specified at compile-time.
- operator[], at, empty, size
- Iterators
- fill, swap

---
## std::array<T, N>

```
#include <array>

int main()
{
    std::array<int, 4> a { 1, 2, 3, 4 };
    for (auto& e : a)
        std::cout << e << "\n";
}


```
---
# std::list<T>
---
## std::list<T>

- Doubly-linked list
- Efficient adding elements at the head and at the tail.
- Inefficient to retrieve an element in the middle.
- Not too useful in real world

---
## std::list<T>

```
#include <list>

int main()
{
    list<int> p;
    p.push_back(10);
    p.push_front(20);

    for (auto& e : p)
        std::cout << e << "\n";
}
```
---
# std::vector<T>
---
## std::vector<T>

- Dynamically allocated array of elements of type T.
- Elements accessible efficiently through index
- One of the most used element containers in C++.

---
## std::vector<T>

```
#include <vector>

int main()
{
    std::vector<std::string> s;
    s.push_back("Hello");
    s.push_back("world");

    for (auto& e : s)
        std::cout << e << "\n";
}
```
---
# std::set<T>
---
## std::set<T>

- Container of elements of type T
- It lets the user:
    - Add and remove elements to/from the set
    - Check if an element is in the set
    - Iterate the elements in the set
- Elements cannot be duplicated.
- Elements are stored in a binary search tree.
---
## std::set<T>

```
#include <set>

int main()
{
    std::set<std::string> names;
    names.insert("Maria");
    names.insert("Ana");
    names.insert("Josefina");

    for (auto& e : names)
        std::cout << e << "\n";
}

```
---
# std::unordered_set<T>
---
## std::unordered_set<T>

- Introduced in C++11
- Container of elements of type T
- It lets the user:
    - Add and remove elements to/from the set
    - Check if an element is in the set
    - Iterate the elements in the set
- Elements cannot be duplicated.
- Elements are stored in a hash table.
---
## std::unordered_set<T>

```
#include <unordered_set>

int main()
{
    std::unordered_set<std::string> names;
    names.insert("Maria");
    names.insert("Ana");
    names.insert("Josefina");

    for (auto& e : names)
        std::cout << e << "\n";
}

```
