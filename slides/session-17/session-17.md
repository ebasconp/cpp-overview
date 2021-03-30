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
---
# DLL Dynamic-binding
---
## DLL dynamic-binding

- Mechanism that allows the program to load dynamically DLLs in runtime.
- Useful to create plugins or extensions
- All error handling depends on the programmer
---
## DLL dynamic-binding

- No header or .lib files needed, only the DLLs, BUT...
- The programmmer needs to know the functions signature.
- The Win32 API provides functions to load these libraries.
---

## DLL dynamic-binding

```
#include <windows.h>

using dynamic_function_ptr = const char*(*)(int);

int main()
{
    HMODULE module = ::LoadLibrary("mylibrary.dll");

    auto my_ptr = static_cast<dynamic_function_ptr>
        (::GetProcAddress(module, "is_even_or_odd");

    std::cout << my_ptr(25) << "\n";
}

```
---
## DLL dynamic-binding

CONS:

- Only works with `extern "C"` things, no classes.
- The DLLs must be compiled with a compatible compiler.
- Function prototypes must be documented.







