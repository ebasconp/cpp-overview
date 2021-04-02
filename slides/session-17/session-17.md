---
title: C++ overview session 17
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 17
## Pimpl idiom / DLLs

###### *Ernesto Bascón Pantoja*

---
## Contents

* DLLs
* Pimpl idiom
* Dynamic binding DLLs

---
# DLLs
---
## DLL

- **DLL** stands for Dynamic Loading Library
- It is a way of creating a binary containing functions or classes.
- Aimed to be reused by several projects.
- Encourages code reuse
---
## DLL

- DLLs export functions and classes.
- Classes can be consumed by static-binding
- C functions can be consumed by static or dynamic-binding.
---
## DLL

- Class- and function-templates cannot be exported.
- Be careful to export classes or C++ functions: C++ ABI is not standard.
---
## DLL

- `__declspec(dllimport)`
- `__declspec(dllexport)`
- `#define` on DLL project.
---
## DLL

```
#ifdef MYDLLEXPORTS
#define MYDLLEXPORT __declspec(dllexport)
#else
#define MYDLLEXPORT __declspec(dllimport)
#endif
```
---
## DLL

```
extern "C"
{
    MYDLLEXPORT int sum(int, int);
}
```
---
## DLL - What distribute?

To be consumed you need to distribute:

- The DLLs in DEBUG and RELEASE version
- The header files
- The .lib file
- Probably some documentation stating compiler, version, OS, etc.

---
# Pimpl idiom
---
## Pimpl idiom

- Pimpl: Pointer to Implementation
- Also called "OPAQUE POINTER"
- Mechanism to truly **hide implementation** details in header files
---
## Pimpl idiom

PROS:
- Hide implementation details.
- `sizeof(MyClass)` will be always the same no matter how many attributes the type has.
- Everything will be accessed only by methods.
---
## Pimpl idiom

CONS:
- No attributes in header file.
- No private methods in header file (probably something positive)
- Slightly slower because implementation must be allocated in heap.
---
## Pimpl idiom

How it works:

- You need to create an opaque pointer to the implementation in the header file.
- The actual implementation will be in other file being included in the CPP file only.

---
## Pimpl idiom

Product.h

```
class Product
{
    std::unique_ptr<ProductImpl> impl;

public:
    Product(const std::string& description, const std::string& id);
    ~Product();

    std::string to_string() const;
};
```
---
## Pimpl idiom

Product.cpp

```
#include "ProductImpl.h"

Product::Product(const std::string& description, const std::string& id)
    : impl{new ProductImpl { description, id }}
{
}

Product::~Product() = default; // in .cpp file

std::string Product::to_string() const
{
    return std::string("(") + impl->id + ") " + impl->description;
}
```
