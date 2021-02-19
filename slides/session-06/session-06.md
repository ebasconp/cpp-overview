---
title: C++ overview session 6
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 06
## Copy constructor and operator overloading

###### *Ernesto Bascón Pantoja*

---

## Contents

- Copy constructor
- Operator overloading
- Rule of 3 / Rule of 5
- Casting operators

---
## Copy constructor

- It is a constructor that copies the values of fields from a given instance.
- It is invoked automatically.
- If the programmer does not implements one, the compiler generates it.

---
## Copy constructor

Example of copy constructor: 

```
class Product
{
public:
  Product(const Product& p) 
    : id{p.id}, description{strdup(p.description)}
  {
  }
};
```
---
## Copy constructor

Example of code that invokes a copy constructor:

```
   Product p { 1432131, "TV" };
   Product p2 = p;
   Product p3 { p2 };

```
---
## Operator overloading

- C++ lets the programmer to overload almost all operators in their own classes / structs.
- It can be implemented as free functions or as struct methods.

---
## Operator overloading

```
struct Complex
{
  double r;
  double im;
};
```
---

##  Operator overloading

As free function:

```
Complex operator+(Complex a, Complex b)
{
  Complex result;
  result.r = a.r + b.r;
  result.im = a.im + b.im;
}
```
* That is not the right way of passing params! We are copying!

---
##  Operator overloading

As free function (corrected):

```
Complex operator+(const Complex& a, const Complex& b)
{
  Complex result { a.r + b.r, a.im + b.im };
  return result;
}
```
* Always pass instances as references or const-references!!

---


## Operator overloading

As method:

```
struct Complex
{
  ...
  
  Complex operator+(const Complex& b) const
  {
      return { this->r + b.r, this->im + b.im };
  }

};

```
---
## Assignment operator

- It is an operator overloaded as method.
- It is invoked to assign all values from an object to an already existing object.

```
 Product a { 124312, "TV" };
 Product b { 452321, "Wii" };
 Product c = a; // copy
 c = b; //assignment
```
---

## Assignment operator

- It replaces the values of attributes to the ones on the source object.
- The programmer could be responsible of freeing those values first.
- Usually a reference to the same instance is returned.

---

## Assignment operator

```
class Product
{
public:
  Product& operator=(const Product& src)
  {
    this->id = src.id;
    free(this->description);
    this->description = strdup(src.description);
    return *this;
  }
};
```
---

## Assignment operator

```
Product& operator=(const Product& src)
{
    if (this == &src) return *this;

    this->id = src.id;
    free(this->description);
    this->description = strdup(src.description);
    return *this;
}
```
---
## Deleting copy constructor and operator=

- Sometimes the programmers do not want their instances to be copied/assigned.
- The programmer must mark their copy constructor and operator= as deleted.

---
## Deleting copy constructor and operator=

```
class Product
{
public:
  Product(const Product& ) = delete;
  Product& operator=(const Product& ) = delete;
};
```
---
# Rule of three
---

## Rule of three

If programmers need to implement a destructor, then they **MUST** implement:

- Copy constructor
- Assignment operator
- Destructor

This is called: "Rule of three".

---
## Rule of three

* When do programmers need to implement a destructor?
* When they need to handle resources explicitly (malloc, operator new, opening a file, etc.).

---
## Rule of five

- C++11 introduces a feature called **move semantics**
- Move semantics improves performance of copies.
- **Rule of five** extends the **rule of three** adding the two extra methods needed to support **move semantics**
- We will see this later.
---


# Casting operators
---

## Casting operators

In C we can cast from one type to other in this way:

```
int n = (int) 3.14;
const char* s = "Hello";
char* s2 = (char*) s;
int* r = (int*) s2;
```

---
## Casting operators

**Nice**, but the casting operator is used to do different things:

- Cast from one type to other.
- Remove the const specifier.
- Change the nature of pointers.

---
## Casting operators

C++ introduces four new casting operators:

- `static_cast<T>`
- `const_cast<T>`
- `reinterpret_cast<T>`
- `dynamic_cast<T>`

---
## Casting operators

- The runtime cost of casting is ZERO *except* for `dynamic_cast<T>`.
- Though "uglier", they are by far clearer than the C casts.
- Prefer use those instead of the C casts.

---

## static_cast<T>

Performs a casting from a type to other one:

```
   int p = static_cast<int>(3.14);
```
---
## const_cast<T>

Removes the "const" of a given thing.

```
   const Product& cp = get_product();
   Product& p = const_cast<Product&>(cp);
```

---
## reinterpret_cast<T>

Changes the nature of a pointer:

```
void* ptr = get_data();
Product* product_ptr = reinterpret_cast<Product*>(ptr);
```

---
## dynamic_cast<T>

We will take a look at this later. Related to inheritance and polymorphism.

---

## Exercises

1. Implement a class String. Use SSO.
2. Implement a copyable/assignable String linked list.

Take a look to file `string.cpp` in code folder.



