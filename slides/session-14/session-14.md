---
title: C++ overview session 14
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 14
## Maps, move semantics

###### *Ernesto Bascón Pantoja*

---
## Contents

* `std::map<K, V>`
* `std::unordered_map<K, V>`
* rvalue references
* Move semantics
* Rule of 5
* `std::move()`
* `std::forward<T>()`
---
# `std::map<K, V>`
---
## `std::map<K, V>`

- Maps are containers where elements are stored as pairs Key/Value
- Elements are looked up through the key
- `std::map<K, V>` is implemented using a binary search tree.
- Thus, elements are sorted BY KEY.
---
## `std::map<K, V>`

```
#include <map>

int main()
{
    std::map<std::string, int> numbers;
    numbers.insert(std::make_pair("One", 1"));
    numbers.insert(std::pair<std::string, int> { "Two", 2 });
    numbers.insert(std::pair { "Three", 3 }); // C++17
    number["Four"] = 4;
}
```
---
## `std::map<K, V>`

- If you want to provide your custom keys, your type K:
    - Must implement `operator<`
    - You must provide a policy returning true if A < B through a functor.

---
# `std::unordered_map<K, V>`
---
## `std::unordered_map<K, V>`

- Available since C++11
- A map implemented using a hash table.
- Elements are not sorted.
---
## `std::unordered_map<K, V>`

- If you want to provide your own key type, you must:
    - Implement `operator==` or provide a policy implementing its semantics.
    - Implement a policy able to generate a hash from your key elements.

---
## `std::unordered_map<K, V>`
```
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, int> numbers;
    numbers.insert(std::make_pair("One", 1"));
    numbers.insert(std::pair<std::string, int> { "Two", 2 });
    numbers.insert(std::pair { "Three", 3 }); // C++17
    number["Four"] = 4;
}
```
---
# rvalue references
---
## rvalue references

- Are references to rvalues (the values at the right in an expression)
- They can be modified by the caller.
- They refer to temporary values.

---
## rvalue references

```
int a = 2;
int& b = 5;
int&& c = b; //rvalue reference
```
---
# Move semantics
---
## Move semantics

- PROBLEM: Returning complex objects from functions was expensive because of copy.
- SOLUTION:
    - If the complex objects will be destroyed when returning to the caller function,
    - Why not "grab" their content instead of copying it and destroying the original?
    - That is called **MOVE SEMANTICS**.

---
## Move semantics

```
BigObject getBigObject()
{
  BigObject bo;
  bo.populate();
  return bo;
}

int main()
{
   BigObject b;
   b = getBigObject(); // copy / delete
}

```
---
## Move semantics

- We need to create one extra MOVE contructor
- We need to create one extra MOVE operator=
---
## Move semantics

Given a class `BigObject`:

#### Move constructor ####

```
BigObject(BigObject&& oo) { .... }
```
---
## Move semantics

Given a class `BigObject`:

#### operator= ####

```
BigObject& operator=(BigObject&& oo) { .... }
``` 
---

## Rule of five

If we need to allocate memory explicitly, we need to implement:

- A copy constructor
- An operator=
- A destructor
- A move constructor (starting C++11)
- A move operator= (starting C++11)
---

# `std::move()`
---
## `std::move()` 

- Function that forces a move.
- Useful when the programmer knows the original object can be moved to the target.
---

# `std::forward<T>()`
---
## `std::forward<T>()`

- Function template that:
    - Preserves the argument's value "type" (lvalue/rvalue)
    - Preservers const modifiers.
- Useful to invoke copies/moves automatically.

---
## Exercise

- Create a trie<T> where key is a string and value is of type T.
- A trie is a data structure where each node contains the value of type T.
- The children specify implicitly the path to the next character.
- Support move semantics

---
## Exercise

```
int main()
{
    jala::trie<int> s;
    s.add("uva", ");
    s.add("manzana", 25);
    s.add("pera", 10);

    auto q = std::move(s);
    q.add("mora", 30);
    q.add("platano", 5);

    q.iterate_by_prefix("p", [](auto& p) 
    { std::cout << q.first << " " << q.second << "\n"; });

    std::cout << q["platano"] << "\n"; // must print 5

    std::cout << q["perro"] << "\n"; 
    // must throw a jala::key_not_found_exception
}
```

