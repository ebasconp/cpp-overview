---
title: C++ overview session 13
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 13
## Function pointers, functors and lambda expressions

###### *Ernesto Bascón Pantoja*

---
## Contents

* Function pointers
* Functors
* Lambda expressions
---

# Function pointers
---
## Function pointers

- Pointers that point to functions instead of actual data.
- Having the pointer, we can invoke the function pointed by the function pointer.
- Signature must be respected.

---
## Function pointers

```
size_t count_string(const char* s)
{
    return strlen(s);
}

int main()
{
    size_t (*strcounter)(const char*);
    strcounter = count_string;
    std::cout << strcounter("Hello") << "\n";
}
```
---
## Function pointers

Can be used for:

* Inject behavior in a generic function.
* Simulate polymorphism.
* Pass a callback
* Choose dynamically the function to call.
---
## Function pointers

We can "typedef" a function pointer:

```
using strcounter_ptr = size_t (*)(const char*);
typedef size_t (*strcounter_ptr)(const char*);

```
---
# Functors
---
## Functors

- Also called **function objects**
- Objects that behave as functions.
- PROS:
    - They have state.
    - Can be heterogeneous.
- CONS:
    - No actual function pointers.
    - Only syntactically compatible.

---
## Functors

```
int main()
{
    Printer p;
    p("Hello world");
}
```
---
## Functors

```
struct Printer
{
  void operator()(const char* s)
  {
     std::cout << s << "\n";
  }
};
```

---
## Functors

or better:

```
struct Printer
{
  template <typename T>
  void operator()(const T& s)
  {
     std::cout << s << "\n";
  }
};
```
---
# Lambda expressions
---
## Lambda expressions

- Also called **anonymous functions**.
- Functions declared inline.
- Shorter declaration.
- Return type generally deduced automatically.
- Argument types deduced automatically starting C++14.
- Only syntactical sugar. Compiler decides to use functors or function pointers in the generated code.
---
## Lambda expressions

```
template <typename T, typename S>
void do_something(const T& a, S s)
{
    s(a);
}

void show(int n)
{
    std::cout << n << "\n";
}

int main()
{
    do_something(5, show);
}
```
---
## Lambda expressions

```
template <typename T, typename S>
void do_something(const T& a, S s)
{
    s(a);
}

int main()
{
    do_something(5, [](int n) { 
        std::cout << n << "\n"; }
    );
}
```
---
## Lambda expressions

Examples:

```
do_something(10, 2, [](auto& a, auto& b) {
   return a + b;
});

```
---
## Lambda expressions

Examples:

```
std::vector<int> results;
do_something(10, 2, [&results](auto& a, auto& b) {
   results.push_back(a + b);
   return a + b;
});

```
---
# std::function<T>
---
## std::function<T>

- Class that wraps a function or functor.
- Useful when storing "functions" with heterogeneous origin.

---
## std::function<T>

```
#include <functional>

int main()
{
    std::function<size_t (const char*)> f;
    f = strlen;
    std::cout << f("hello") << "\n";
}
```




