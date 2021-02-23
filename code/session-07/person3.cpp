#include <iostream>
#include <cstring>

class Person
{
private:
	char first_name[32];
	char last_name[32];
	
public:
	Person() : Person("", "") { }
	
	Person(const char* first_name, const char* last_name)
	{
		strcpy(this->first_name, first_name);
		strcpy(this->last_name, last_name);
	}
	
	Person(const Person& p)
	{
		strcpy(this->first_name,p.first_name);
		strcpy(this->last_name, p.last_name);
		std::cout << "copying base\n";
	}
	
	~Person()
	{
		std::cout << "Destroying Person\n";
	}
	
	void print() const
	{
		std::cout << last_name << ", " << first_name << "\n";
	}
	
	const char* get_first_name() const { return first_name; }
	const char* get_last_name() const { return last_name; }
	
	void say_hi() const { std::cout << "HI\n"; }
};

class Student : public Person
{
	char course_name[32];
	
public:
	Student(const char* first_name, const char* last_name, const char* course_name)
		: Person { first_name, last_name }
	{
		strcpy(this->course_name, course_name);
	}
	
	// This method hides Person::print()
	void print() const
	{
		std::cout << get_last_name() << ", " << get_first_name() << " (" << course_name << ")\n";
	}
	
	void saludar() const
	{
		Person::say_hi();
	}
	
	~Student()
	{
		std::cout << "Destroying Student\n";
	}
};


int main()
{
	Person people[3];
	people[0] = { "Juan", "Sanchez" };
	people[1] = Student { "Gustavo", "Canedo", "MAT-102" }; // object slicing
	people[2] = { "Ana", "Rojas" };
	
	for (Person& p : people)
	{
		p.print();
	}
	
	Person* people2[3];
	people2[0] = new Person { "Juan", "Sanchez" };
	people2[1] = new Student { "Gustavo", "Canedo", "MAT-102" }; // no slicing
	people2[2] = new Person { "Ana", "Rojas" };
	
	for (Person* p : people2)
	{
		p->print();
	}
	
	
	for (Person* p : people2)
	{
		delete p;
	}
	
}
