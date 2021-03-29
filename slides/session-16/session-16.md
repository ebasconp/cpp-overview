---
title: C++ overview session 16
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 16
## Smart Pointers

###### *Ernesto Bascón Pantoja*

---
## Contents

* Smart Pointers
* `std::unique_ptr<T>`
* `std::shared_ptr<T>`
* `std::weak_ptr<T>`
---
# Smart Pointers
---
## Smart Pointers

- Stack-based objects that behaves as a pointer.
- Generally implemented as class templates.
- Generally implement some memory management policy.
- The standard library implements two types of smart pointers.
---
## Smart Pointers

- You can implement your own smart pointer.
- Need to overload:
    - `operator->()`
    - `operator*()`
    - `operator==()`
---
# `std::unique_ptr<T>`
---
## `std::unique_ptr<T>`

- Stores an object dynamically allocated.
- It binds the pointee lifetime to this smart pointer lifetime.
- Only one unique pointer can point to one object.
---
## `std::unique_ptr<T>`

```
#include <memory>

struct A
{
  void hi() { std::cout << "Hello\n"; }
};

int main()
{
    std::unique_ptr<A> ptr { new A() };
    ptr->hi();
}
```
---
## `std::unique_ptr<T>`

```
#include <memory>

struct A
{
  void hi() { std::cout << "Hello\n"; }
};

int main()
{
    auto ptr = std::make_unique<A>(); //C++14
    ptr->hi();
}
```
---
# `std::shared_ptr<T>`
---
## `std::shared_ptr<T>`

- Stores a pointer to an object dynamically allocated.
- The pointer can be shared among `shared_ptr<T>` instances.
- When no shared pointer points to an object, the object is released automatically.
- It does not work with circular references.
---
## `std::shared_ptr<T>`

```
#include <memory>

int main()
{
    std::shared_ptr<A> ptr { new A() };
    std::shared_ptr<A> ptr2 = ptr;
    ptr->hi();
    ptr = nullptr;
    ptr2 = nullptr;
}
```
---
## `std::shared_ptr<T>`

```
#include <memory>

int main()
{
    auto ptr = std::make_shared<A>();
    auto ptr2 = ptr;
    ptr->hi();
    ptr = nullptr;
    ptr2 = nullptr;
}
```
---
# `std::weak_ptr<T>`
---
## `std::weak_ptr<T>`

- It is more a wrapper around the `std::shared_ptr<T>` more than a smart pointer.
- It is notified when the pointee is released.
- It lets you use it on circular references.
---
## `std::weak_ptr<T>`

```
int main()
{
    auto ptr = std::make_shared<A>();
    std::weak_ptr<A> weak = ptr;

    weak.lock()->hi();
}
```



