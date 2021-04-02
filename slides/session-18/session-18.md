---
title: C++ overview session 18
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 18
## DLLs / BSTR / CString / C++/CLI

###### *Ernesto Bascón Pantoja*

---
## Contents

* Dynamic binding DLLs
* BSTR
* CString
* C++/CLI

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
- The DLLs must be compiled in the same architecture (x86, x65, ARM, etc).
- Function prototypes must be documented.

---
# BSTR
---
## BSTR

- Microsoft string representation.
- It is a zero-terminated string, compatible with `const char*`.
- It contains the string byte-length 4 bytes before the string.
- Useful because `strlen` is very slow.
---
## BSTR

```
BSTR str = SysAllocString(L"Hello world");
std::wcout << str << "\n";

SysFreeString(str);

```
---
# CString
---
## CString

- `CString` is a class from the MFC.
- Provides memory handling similar to `std::string`
- MFC is the Microsoft Foundation Classes framework.
- A "thin" layer on top of Win32 API.

---
## CString

```
#include <atlstr.h>

int main()
{
    CString h = L"Hello world";
    std::wcout << h.GetString() << "\n";
}
```
---
# C++/CLI
---
## C++/CLI

- .NET Managed extensions for C++.
- It combines standard C++ with .NET features.
- Not so interchangeable.
---
## C++/CLI

```
using namespace System;

int main()
{
    String^ s = gcnew String("Hello world");
    Console::WriteLine(s);
    return 0;
}


```

