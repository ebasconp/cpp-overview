---
title: C++ overview session 7
paginate: true
marp: true
theme: uncover
---

# C++ overview

### Session 07
## Inheritance and polymorphism

###### *Ernesto Bascón Pantoja*

---

## Contents

- Inheritance
- Method hiding
- Object slicing
- Polymorphism
- Pure virtual methods
- dynamic_cast<T>

---
# Inheritance
---
## Inheritance

- Mechanism that lets developers creating new classes extending one or more classes.
- It encourages code reuse.
- It establishes an IS-A relationship between base and derived classes.
- In C++ there is no "universal base class" (as the Java `Object` class)
---
## Inheritance

```
struct Point
{
    int x;
    int y;
};

struct Point3d : public Point
{
    int z;
};
```

---
## Inheritance in C++

It can be:

* **public** when all public members of base class will be public in the derived class.
* **protected** when all public members of base class will be protected in the derived class.
* **private** when all public members of base class will be private in the derived class.

---
```
class Person
{
protected:
    char first_name[32];
    char last_name[32];

public:
    Person(const char* fn, const char* ln)
    {
        strcpy(first_name, fn);
        strcpy(last_name, ln);
    }

    void print()
    {
        std::cout << last_name << ", " << first_name << "\n";
    }
};
```
---
```
class Student : public Person
{
    char class_name[32];

public:
    Student(const char* fn, const char* ln, const char* cn)
        : Person(fn, ln)
    {
        strcpy(class_name, cn);
    }

    void print_student()
    {
        std::cout << last_name << ", " << first_name << " (" << class_name << ")\n";
    }
};
```
---
# Method hiding
---
## Method hiding

- When a method has the same name in derived class and in base class, the compiler **HIDES** the base class method.
- It lets the developer use the best implementation depending on the class being used.

---
## Method hiding

```
struct Greetings
{
   void greet() { std::cout << "Good morning\n"; }
};

struct Saludos : Greetings
{
  void greet() { std:: cout << "Buenos días"; }
};
```
---
## Method hiding

```
int main()
{
    Greeting g1;
    g1.greet();

    Saludos g2;
    g2.greet();
}
```
---
# Object slicing
---
## Object slicing

- When an object of a derived class is copied to a base class instance.
- Part of the values of the derived class instance are "sliced away".

---
## Object slicing

```
int main()
{
    Person p { "Juan", Perez" };
    Student q { "Ana", "Jimenez", "MAT-101" };
    
    Person r = q; // object slicing
}
```
---
## Object slicing
```
int main()
{
    Person people[3];
    people[0] = Person { "Juan", "Perez" };
    people[1] = Person { "Ana", "Jimenez" };
    people[2] = Student { "Jhery", "Loayza", "MAT-101" }; // slicing
}
```
---

# Polymorphism
---
## Polymorphism

- Two instances of different classes but both derived from the same base class.
- Both receive the same message (same method is called)
- Both return a different result.

---
## Polymorphism

```
int main()
{
    Dog d;
    Cat c;
    d.say_something(); // Returns "gau"
    c.say_something(); // Returns "meow"
}
```
---
## Polymorphism in C++

- C++ implements polymorphism through **virtual methods**.
- A **virtual method** is a method that is declared in a base class and can be *overridden* in derived classes.
- The actual method invoked will be the bottom most in the override hierarchy.
- To use polymorphism, *pointers* and *references* MUST BE used.

---
## Virtual methods

```
class Animal
{
public:
    virtual void say_something() const { std::cout << "[Nothing to say]\n"; }
};

class Dog : public Animal
{
public:
    void say_something() const override { std::cout << "Gau\n"; }
};

```
---
## Virtual methods
```
void say(const Animal& a)
{
    a.say_something();
}


int main()
{
    Dog d;
    Cat c;
    say(d);
    say(c);
}
```
---
## Virtual destructor

If your class has at least ONE virtual method, it should mark its destructor as **virtual**:

```
class Animal
{
public:
    virtual void say_something() const { std::cout << "[Nothing to say]\n"; }

    virtual ~Animal() = default; // default since C++11
};

```
--- 
# Pure virtual methods
---
## Pure virtual methods

- Sometimes the developer wants to declare a virtual method but wants the implementation to be in the derived classes.
- When this occurs, the developer can mark the base method as **virtual pure**.
- Classes with pure virtual methods cannot be instantiated (*abstract classes*).
- There is no explicit way of marking a class as **abstract**.
---
```
class Shape
{
public:
    virtual double get_area() const = 0;
};

class Circle : public Shape
{
    double r;
public:
    Circle(double r) : r{r} { }
    double get_area() const override { return r * r * 3.141592654; }
};

```
---
# dynamic_cast&lt;T&gt;
---
## dynamic_cast&lt;T&gt;

* Used when a programmer needs to verify the actual type of a given object.
* It casts to the given type if the parameter IS an INSTANCE OF such class.
* Otherwise it returns **`nullptr`** or a **`std::bad_cast`** exception.
* To be supported, the hierarchy must have at least a virtual method.
---
```
class Animal
{
public:
    virtual ~Animal() = default;
    virtual void say_something() const = 0;
};

class Dog : public Animal
{
public:
    void say_something() const override { std::cout << "gau\n"; }
    void bite() const { std::cout << "biting\n"; }
};
```

---
```
void process(const Animal* a)
{
    a->say_something();
    Dog* dog = dynamic_cast<Dog*>(a);
    if (dog != nullptr)
        dog->bite();
    else
        std::cout << "NOT A DOG\n";
}

int main()
{
    Dog d;
    process(&d);
}

```
---

## Exercises

1. Create a class "ChessBoard".
2. Being able to set a ChessPiece in a location inside the ChessBoard
3. Validate the maximum number of chess pieces by type is not reached, if so, return "false" when adding a new piece.
4. Implement a "move" method on each piece, asking for a new position and if the new position is valid for the given piece, perform the "move".
