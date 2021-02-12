---
title: C++ overview session 5
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 05 
## Structs

###### *Ernesto Bascón Pantoja*

---

## Contents

- Structs
- Constructors and destructors
- RAII
- Methods
- Access modifiers
- Class

---
# Structs
---

## Structs

- Collection of fields / attributes (C and C++) and methods (only C++)
- Fields are accessed through their names
- Each instance of a struct/class contains values for all their attributes

---

## Structs - Declaration

```
struct Person
{
  char first_name[32];
  char last_name[32];
  size_t birth_year;
};

```
---

## Structs - Old school declaration

```
typedef struct
{
  char first_name[32];
  char last_name[32];
  size_t birth_year;
} Person2;

```
---
## Structs - Stack

```
Person a;
strcpy(a.first_name, "Marcelo");
strcpy(a.last_name, "Rollano");
a.birth_year = 1977;

Person b { "Juan Jose", "Mendivil", 1964 };
// Only valid if Person does not have explicit constructor
// and the fields are public

```

---
## Structs - Heap

```
Person* c = (Person*) malloc(sizeof(Person));
strcpy((*c).first_name, "Alfredo");
strcpy(c->last_name, "Vedia");
c->birth_year = 1976;

Person* d = new Person{};

```
---
## Structs - Arrays
```
Person students[10];
strcpy(students[0].first_name, "Juan");
...

Person* more_students = (Person*) malloc(1000 * sizeof(Person));
strcpy(more_students[2].first_name, "Raul");
...
Person* extra_students = new Person[10000];
// no way to invoke consistent initialization
strcpy(extra_students[1000].last_name = "Castro");
```

---
# Constructors and destructors
---

## Structs - Constructors

- Code block that initializes the fields of a struct instance.
- It is automatically invoked when a new instance is created (heap or stack).
- It is declared inside a struct
- It has the same name than the struct.
- It does not have return type.

---
## Structs - Constructors
```
struct Product
{
  size_t id;
  char* description;
  char* brand;

  Product(size_t aId, const char* aDescription, const char* aBrand)
  {
    id = aId;
    description = strdup(aDescription);
    brand = strdup(aBrand);
  }
};
```

---
## Structs - Constructors

```
Product p1; // illegal since we have an explicit constructor
Product p2 { 3323423, "Switch", "Nintendo" };

std::cout << p2.description << "\n";

```
---
## Structs - Constructors - V2
```
struct Product
{
  size_t id;
  char* description;
  char* brand;

  Product(size_t id, const char* description, const char* brand)
  {
    id = id;
    description = strdup(description);
    brand = strdup(brand);
  }
};
```
Completely wrong!

---
## Structs - Constructors - V2
```
struct Product
{
  size_t id;
  char* description;
  char* brand;

  Product(size_t id, const char* description, const char* brand)
  {
    this->id = id;
    this->description = strdup(description);
    this->brand = strdup(brand);
  }
};
```
---
## Structs - this

- Pointer to the instance that invokes a method / constructor
- If not mentioned and no ambiguity, it implicitly gives us access to the instance fields and methods
- Does not support pointer arithmetic
- Cannot be changed
- It behaves as a reference.
* It is not a reference because was invented before references. :(

---
## Structs - Constructors - V3
```
struct Product
{
  size_t id;
  char* description;
  char* brand;

  Product(size_t id, const char* description, const char* brand)
    : id{id}, description{strdup(description)}, brand{strdup(brand)}
  {
  }
};
```
* Initialization list

---
## Structs - Constructor overloading
```
struct Product
{
  size_t id;
  char* description;
  char* brand;

  Product(size_t id, const char* description, const char* brand)
    : id{id}, description{strdup(description)}, brand{strdup(brand)}
  {
  }

  Product()
    : Product{0, "Undefined", "Undefined"} // since C++11
  {
  }
};
```
---
## Structs - Destructors
```
struct Product
{
  size_t id;
  char* description;
  char* brand;

  Product(size_t id, const char* description, const char* brand)
    : id{id}, description{strdup(description)}, brand{strdup(brand)}
  {
  }
};
```
* What is wrong here?
* `strdup` allocates memory and no one is releasing it!!!

---
## Structs - Destructors

**Solution 1**: Release the fields explicitly:

```
int main()
{
    Product p { 2524523, "XBox X Series", "Microsoft" };
    free(p.description);
    free(p.brand);
}
```

* Error prone
* Breaks encapsulation A LOT!

---
## Structs - Destructors

**Solution 2**: Expose a function that releases the object:

```
void release(Product& p) {
    free(p.description);
    free(p.brand);
}

int main() {
    Product p { 2524523, "XBox X Series", "Microsoft" };
    release(p);
}
```
* Far better!
* BUT needs to be invoked explicitly ==> Error prone

---
## Structs - Destructors

**THE solution**: Implement a destructor

```
struct Product {
  size_t id;
  char* description;
  char* brand;

  Product(size_t id, const char* description, const char* brand)
    : id{id}, description{strdup(description)}, brand{strdup(brand)} {
  }

  ~Product() {
      free(description);
      free(brand);
  }
};
```
---
## Struct - Destructors

- Code block that releases all resources acquired explicitly by our instance.
- Automatically when an instance goes out of scope (stack) or is deleted.
- It is declared inside a struct.
- It has the same name than the struct but with the character `~` before.
- It does not have return type.
- A struct can have only one destructor.
- The destructor has no arguments.

---
## RAII

- Resource Acquisition Is Initialization
- RAII ties resources with instance lifetime.
- So, resources are automatically released (invoking the destructor) when instance goes out of scope.
- It is one of the most brilliant ideas invented for C++.
- Concept used in D, Vala, ADA and Rust.
- RAII will always invoke the instance destructor, if any.
---

## RAII

```
int main()
{
    Product p { 21342678, "PS 5", "Sony" };

    // here the Product destructor will be invoked automatically
}

```
---

## Instances inside instances
---
```
struct ProductPair
{
    Product p1;
    Product p2;
};

int main()
{
  ProductPair { 
    Product{ 1, "TV", "Sony" },
    Product{ 2, "Radio", "CASIO" }
  };
  // No need of destructor
}
```
---
# Methods
---
## Methods

- Functions declared inside a struct
- They implicitly receive a pointer to the instance that called the method (`this`).
- Methods need an instance to be invoked (except static methods).
---
## Methods

```
struct Product
{
   ...
   void print()
   {
     std::cout 
        << "(" << id << ") " 
        << description << ", " 
        << this->brand << "\n2;
   }
};
```
---
## Const methods

- If a method is not going to modify the logical state of an instance, it should be marked as const.
- A const method can only invoke const methods of the same class.
- If a type is const, it only can invoke const methods.
- The type of `*this` changes from `Product*` to `const Product*`

---
## Const methods

```
struct Product
{
   ...
   void print() const
   {
     std::cout 
        << "(" << id << ") " 
        << description << ", " 
        << this->brand << "\n2;
   }
};
```
---
# Access modifiers
---
## Access modifiers

- **`public:`** indicates all identifiers declared from now will be accessible to anyone.
- **`private:`** indicates all identifiers declared from now will be accessible only from this struct.
- **`protected:`** used in inheritance. More on this in next sessions.
- Structs default access modifier is public.
---
```
struct Product {
private:
  size_t id;
  char* description;
  char* brand;

public:
  Product(size_t id, const char* description, const char* brand) 
 : id{id}, description{strdup(description)}, brand{strdup(brand)} {
  }

  ~Product() {
      free(description);
      free(brand);
  }

  void print() const {
     std::cout << "(" << id << ") " 
        << description << ", " << this->brand << "\n2;
   }
};
```
---
# Class
---
## Class

- In C++, a **`class`** is a struct with all members private by default.
- That is the only difference.
- In OOP, a class is a recipe to create class instances, a.k.a. objects.
---
```
class Product {
  size_t id;
  char* description;
  char* brand;

public:
  Product(size_t id, const char* description, const char* brand)
    : id{id}, description{strdup(description)}, brand{strdup(brand)} {
  }

  ~Product() {
      free(description);
      free(brand);
  }

  void print() const {
     std::cout 
        << "(" << id << ") " 
        << description << ", " 
        << this->brand << "\n2;
   }
};
```
---
## Exercises

- Create a class StringList with these methods:
    - add(const char*) to add strings
    - length() to get string length
    - print()
    - get(size_t index)
    - index_of(const char* str)
    - remove(size_t index)










