---
title: C++ overview session 10
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 10
## Templates

###### *Ernesto Bascón Pantoja*

---
## Contents

* Templates
* Template specialization
* Inheritance
---

# Templates
---
## Templates

- Functions or types where one or more types are parameterized.
- The compiler creates actual types when type instances are created.
- Compiler NEEDS to access to the actual implementation, so, all code must be implemented in header files.
- On function templates, the compiler CAN deduce the template parameters.

---
# Templates

With no templates:

```
int sum(int a, int b) { return a + b; }

double sum(double a, double b) { return a + b; }

Limonada sum(const Limon& a, const Agua& b) { return a + b; }
```
---
# Templates

With templates:

```
template <typename T, typename U>
auto sum(const T& a, const U& b)
{
    return a + b;
}

int main()
{
    std::cout << sum(12.3, 16.5) << "\n";
}

```
---
# Templates

A template argument can be also an integer number.

```
template <size_t N>
size_t factorial()
{
	size_t r = 1;
	for (size_t i = 1; i <= N;  i++)
	{
		r *= i;
	}
	
	return r;
}

int main()
{
    std::cout << factorial<7>() << "\n";
}

```
---
# Class templates

- Types where one or more inner types are passed as parameters.
- Parameterized types are not deduced by the compiler.

---
# Class templates

```
template <class T>
class ArrayList
{
    T* elems;
    size_t n;
    size_t cap;
 
    ...
    ...
};

int main()
{
    ArrayList<String> strings;
}
```
---
## Default template parameters

```
template <typename A, typename B = double>
class MyClass
{
};

int main()
{
    MyClass<int, int> i1;
    MyClass<double, double> i2;
    MyClass<Dog> i3;
    // identical to MyClass<Dog, double>
}
```
---

# Template specialization
---
## Template specialization

- Provides specific implementation for specific types.
- Total specialization
    - All parameterized types are specialized
- Parcial specialization
    - Not all parameterized types are specialized.
- Function templates only provide total specialization.

---
## Template specialization

```
template <typename T>
void show(const T& arg)
{
    std::cout << arg << "\n";
}

template <>
void show<int>(const int& arg)
{
    std::cout << "INTEGER: " << arg << "\n";
}
```
---
## Template specialization

```
template <class T>
class Example
{
public:
    void a() { }
};

template <>
class Example<double>
{
public:
    void b() { }
};

```
---
## Template specialization for pointers

```
template <typename T>
class MyClass { ... };

template <typename T>
class MyClass<T*> { ... };
```
---
# Inheritance
---
## Inheritance

- Programmer can derive from a class template.
- It can be a new class template.
- It can be a concrete class.
- Inherited methods cannot be accessed directly. Full class name or **`this`** must be used.

---
## Inheritance

```
template <class T> Base { ... };

template <class T> Derived : public Base<T>
{
    ...
};

class ConcreteDerived : public Base<double>
{
   ...
};
```
---
## Exercise

Implement a LinkedList<T>:

```
template <
    typename T,
    typename Equal = my_equal<T>,
    typename Printer = cout_printer<T>>
class LinkedList
{
public:
  void push_back(const T& e);
  void push_front(const T& e);

  bool contains(const T& e) const;
  bool is_empty() const;
  
  void print_all() const;
};
```
---
*About the exercise:*

`cout_printer<T>` will use `std::cout` to print one element and `my_equal<T>` will be useful to compare two objects using `operator=`.

Both will be pluggable to provide more flexibility on how to find an element and how to print it.



