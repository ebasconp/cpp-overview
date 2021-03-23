---
title: C++ overview session 15
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 15
## optional, variant, any

###### *Ernesto Bascón Pantoja*

---
## Contents

* `std::optional<T>`
* `std::variant<T...>
* `std::any`
---
# `std::optional<T>`
---
## `std::optional<T>`

- Represents the possible absence of value.
- Useful for parameter passing and return values.
---
## `std::optional<T>`

Before C++17, the programmers used to model optionalness in several ways:

- Through special values (`Person` with ID = -1, for example)
- Through iterators pointing to `end()`
- Through null pointers.
- Through exceptions.

---
## `std::optional<T>`
```
person* find_person_by_id(int id)
{
    ...
}

int main()
{
    person* p = find_person_by_id(1414314);
    if (p == nullptr)
        std::cerr << "Person not found\n";
    else
        std::cout << *p << "\n";
}
```
---
## `std::optional<T>`

Starting C++17, `std::optional<T>` lets the programmer model optionalness through it:

```
#include <optional>

std::optional<person> find_person_by_id(int id)
{
  ...
}

int main()
{
    std::optional<person> p = find_person_by_id(1414314);
    if (!p.has_value())
        std::cerr << "Person not found\n";
    else
        std::cout << p.value() << "\n";
}
```

---
## `std::optional<T>`

```
std::optional<person> find_person_by_id(int id)
{
    if (id == 1231231)
        return std::optional<person> { person { "Juan", "Perez", 1231231 } };

    return std::null_opt;
}
```
---
## `std::optional<T>`

- If an instance of `std::optional<T>` has no value and the programmer invokes `value()`,
a **`std::bad_optional_access exception`** is thrown.

---
# `std::variant<T...>`
---
## `std::variant<T...>`

- Starting  C++17
- Class that can contain only one element of a given type.
- No restriction about types.

---
## `std::variant<T...>`

```
#include <variant>
#include <string>

int main()
{
    std::variant<std::string, int, char> s { "Hello" };

    std::cout << std::get<std::string>(s);

    s = 2;
    std::cout << std::get<std::int>(s);
}

```
---
## `std::variant<T...>`

```
int main()
{
    std::variant<int, std::vector<int>, int*> ints;
    ints = std::vector<int> { };

    if (std::holds_alternative<std::vector<int>>(ints))
        std::cout << "variant contains a vector\n";
}
```
---
## `std::variant<T...>`

- `std::visit()` lets the programmer invoke a method inside a variant.
- It is a nice static way of doing ad hoc polymorphism.

---
# `std::any`
---
## `std::any`

- Starting C++17
- Instances of `std::any` can contain ANY type of element.
- If they are larger than a pointer, they are stored dynamically in heap.
- Its type is dynamically tested.

---
## `std::any`

```
#include <any>

int main()
{
    std::any a;  // no value
    a = 2;
    std::cout << std::any_cast<int>(a) << "\n";

    a = "Hello world"s;
    std::cout << std::any_cast<const char*>(a) << "\n"; 
    // throws std::bad_any_cast
}
```


