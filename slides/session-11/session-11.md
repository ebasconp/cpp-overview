---
title: C++ overview session 11
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 11
## Variadic templates

###### *Ernesto Bascón Pantoja*

---
## Contents

* Variadic templates
* Tuple
* std::string
* std::string_view
---

# Variadic templates
---
## Variadic templates

Templates that have a variable number of parameterized types.

---
## Variadic templates

Instead of:

```
template <typename A, typename B>
auto sum(const A& a, const B& b)
{
    return a + b;
}

template <typename A, typename B, typename C>
auto sum(const A& a, const B& b, const C& c)
{
    return a + b + c;
}
```
---
## Variadic templates

```
template <typename A, typename B>
auto sum(const A& a, const B& b)
{
    return a + b;
}


template <typename T, typename... Args>
auto sum(const T& a, const Args& ... args)
{
    return a + sum(args...);
}

```
---
## Variadic templates

Using fold expressions (C++17):

```
template <typename ... Args>
auto sum(const Args&... args)
{
    return (0 + ... + args);
}

```
---
## Variadic templates:

Invoking one method with each parameter:

```
template <typename T>
void println(const T& a)
{
    std::cout << a << "\n";
}

template <typename... Args>
void print(const Args&... args)
{
   //(std::cout << ... << args);
   (println(args), ...);
}
```
---
## Variadic templates:

**`sizeof...`**

Returns the number of parameters in a parameter pack.

---

# Tuple

---

## Tuple

A variadic template class that can store any number of parameters of different types.

---

## Tuple

```
#include <tuple>

int main()
{
    std::tuple<int, Person, long> data;
    std::tuple<String, String, long, long> person;
}
```
---
## Tuple

Getting elements:

```
std::get<0>(person); // will return the name
```
---
## Tuple functions

- **`make_tuple`** returns a new tuple-
- **`tuple_size`** returns the size of the tuple.
- **`tuple_element`** returns the type of a given element
- **`tie`** returns a tuple of references.
- Comparison operators.

---

# std::basic_string

---
## std::basic_string

- Class template that implements string functionality.
- Most useful definitions: `std::string`, `std::wstring`.

---
## std::string

- `std::basic_string` instantiation using `char` as unit type.
- `operator[]` and `at`
- `length`
- `c_str` and `data`
- `empty` and comparators.
- Iterators
- String literals
- Number to string functions

---
# std::string_view
---
## std::string_view

- Is a non-owning constant string
- Wraps a `std::string` or a `const char*`

---

## Exercises

1. Add an iterator to your `LinkedList<T>`.
2. Add a variadic `add()` to your `LinkedList<T>`.
3. Verify that your `LinkedList<T>` works with `std::string`, `std::string_view` and `std::tuple<>`.
4. Implement variadic `join`:

```
std::string s = join("; ", "Hello", 2, 125, true);

//Returns
Hello; 2; 125; true
```





