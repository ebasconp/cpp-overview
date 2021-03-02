---
title: C++ overview session 1
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 01

##### Ernesto Bascón Pantoja



---

> There are only two kinds of languages:
> 
> the ones people complain about and 
> the ones nobody uses.

#### - Bjarne Stroustrup

---

## Course contents (1/3)

1. Introduction to C++
2. Stack and heap / Passing parameters by value / Pointers and references / Arrays
3. C strings / More on pointers / more on arrays
4. Pointers to pointers / dynamic memory allocation
5. Classes / structs / Methods / constructors / destructors / access modifiers

---

## Course contents (2/3)

6. Copy constructors / Assignments / Operator overloading / Casting operators
7. Inheritance / Polymorphism
8. OOP example
9. RTTI / Multiple inheritance / Exceptions
10. Introduction to templates
11 `std::string` / iterators / `std::vector`
12. `std::map` / `std::unordered_map`

---

## Course contents (3/3)

13. Function pointers / functors / lambda expressions
14. `std::tuple` / `std::optional` / `std::any` / `std::variant`
15. Smart pointers
16. Pimpl idiom. Microsoft specifics: Libraries & DLLs
17. Windows specifics: `BSTR`, MFC strings & C++ CLI

---

## Scoring

- Homeworks (40/100)
- Project (60/100)

---

## Tools

- Any C++ compiler (g++10 or later, clang 11 or later, Microsoft Visual Studio 2019)
- Any text editor or IDE
- For last week, only Visual Studio

---

# Introduction to C++

---

## Contents

1. Timeline
2. Features
3. `"Hello world"`
4. Compilation process
5. Data types
6. Literals
7. Operators / `sizeof`

---

# Timeline

---

## Timeline

| Year   | &nbsp;
|--------|:------
|    1979|**Bjarne Stroustrup** created *C with classes*, that was basically C... with classes. It included classes, constructors and destructors,  derived classes, public / private access modifiers, type checking
|    1981|Added inline functions, default arguments, assignment operator overloading

---

## Timeline

| Year   | &nbsp;
|--------|:------
|    1982|Virtual functions, function and operator overloading, references, `const`
|    1983|** cfront **, first commercial C++ compiler, was released.
|    1985|**“The C++ programming language”** reference book 1st edition was published
|    1989|C++ 2.0: Multiple inheritance, abstract classes, static member functions, const member functions, protected members

---

# Features

---

## Features

- Highly compatible with C.
- Zero-cost abstractions (you don't pay for what you don't use).
- Devoted to performance.
- Extremely backwards compatible.
- High/mid/low level programming language.
- C++ compiler produces native binaries.
- Highly optimized compilers.

---

## Features

- A lot of control is left to the programmer (for performance’s sake) [boundaries checking, memory handling, etc.].
- *"Undefined behavior"*
- Thin standard library.

---

# `"Hello world"`

---

## `"Hello world"`

```
#include <iostream>

int main()
{
    std::cout << "Hello world\n";
    return 0;
}
```

---

# Compilation process

---

## Compilation process

![](compilation-process.jpg)

---

# Datatypes

---

## Datatypes

- Null pointer type:
    - **`nullptr_t`**
    
- Boolean values:
    - **`bool`**
    
- Character types:
    - **`char`** -> 8-bit always.
    - **`wchar_t`** -> width depends on CPU architecture, compiler, platform, OS, etc.

---

## Datatypes

- Integer types:
    - **`[signed] short`**, **`unsigned short`** (generally: 16-bit)
    - **`int`**, **`unsigned int`** (generally: 32-bit)
    - **`long`**, **`unsigned long`** (Windows: 32-bit, 64-bits UNIXes: 64-bit)
    - **`long long`** (64-bit)

---

## Datatypes

- Floating-point types:
    - **`float`** (generally: 32 bit)
    - **`double`** (generally: 64 bit)
    - **`long double`** (generally: 80 bit)

---

## Datatypes

- Size type:
    - **`size_t`**
    
- Fixed size integers types:
    - **`int8_t`** / **`uint8_t`** (8 bit)
    - **`int16_t`** / **`uint16_t`** (16 bit)
    - **`int32_t`** / **`uint32_t`** (32 bit)
    - **`int64_t`** / **`uint64_t`** (64 bit)


---

# Literals

---

## Boolean literals

- **`true`**
- **`false`**

---

## Character (`char`) literals:
- `‘a’`
- `‘\0’`

---

## International character literals


- Wide character (wchar_t) literals:
    - **`L’a’`**
    - **`L’\0’`**

- UTF-8, UTF-16, UTF-32 literals (since C++17):
    - **`u8‘a’`** //UTF-8
    - **`u‘ਫ਼’`** //UTF-16
    - **`U’扂’`** //UTF-32

---

## Int literals

- **`12385`**
- **`-234245`**
- **`12’634`** (since C++11)
- **`0x1F2A32BC`** (hexadecimal)
- **`012532`** (octal)
- **`0b0111010111`** (since C++14) (base-2)

---

## Unsigned int literals

- **`12385U`**
- **`-234245U`**
- **`12’634U`** (since C++11)

---

## Long literals

- **`123851234123L`**
- **`-23424585622L`**
- **`92’634’524’723’184L`** (since C++11)
- **`0x1F2A32BC0A00B0L`**
- **`012532231234L`**
- **`0b011101011101011001L`** (since C++14)


---

## Unsigned long literals

- **`123851234123UL`**
- **`-23424585622UL`**
- **`92’634’524’723’184UL`** (since C++11)
- **`0x1F2A32BC0A00B0UL`**
- **`012532231234UL`**


---

## Float literals

- **`32423.2f`**
- **`2E10f`** (2*10^2)
- **`2.32E-5f`**

---

## Double literals
- **`32423.23423`**
- **`2E10`**
- **`2.323222E-5`**

---

## "String" Literals

- “String” literals (const char*)
    - **`“Hello world”`**
- “Wide-string” literals (const wchar_t*)
    -**`L”Hello world”`**

- UTF-8, UTF-16, UTF-32 “string” literals:
    - **`u8”Hello world”`**
    - **`u”Hello world”`**
    - **`U”Hello world”`**

---

## String Literals

- std::string literals:
    - **`“Hello world”s`**

## Null pointer literal

- **`nullptr`** replaces **`NULL`** macro.

---

# Operators

---

## Operators

- C++ has the same operators, with the same semantics than C, Java, C#, etc.
- C++ provides a set of new operators:
    - **`new`** / **`delete`**
    - **`static_cast`** / **`const_cast`** / **`reinterpret_cast`** /  **`dynamic_cast`**
    - **`::`**
    - **`sizeof...`**
    - **`typeid`**
    - **`noexcept`**

---

## Operators

- Almost all C++ operators can be overloaded for custom datatypes

---

## Arithmetic operators

- **`+`**, **`+=`**
- **`-`**, **`-=`**
- **`*`**, **`*=`**
- **`/`**, **`/=`**
- **`%`**, **`%=`**
- **`++`**
- **`--`**

---

## Relational operators

- **`==`**
- **`!=`**
- **`>`**
- **`<`**
- **`>=`**
- **`<=`**
- **`<=>`** (C++20, not included in C)

---

## Logical operators

- **`&&`**
- **`||`**
- **`!`**

---

## Bitwise operators

- **`&`**, **`&=`**
- **`|`**, **`|=`**
- **`~`**
- **`^`**
- **`<<`**, **`<<=`**
- **`>>`**, **`>>=`**


---

## Other operators

- **`::`**
- **`sizeof`**
- **`sizeof...`**
- **`alignof`**
- **`typeid`**
- **`new`**, **`new[]`**
- **`delete, **`delete[]`**
- **`noexcept`**
- **`static_cast`** / **`const_cast`** / **`reinterpret_cast`** / **`dynamic_cast`**


