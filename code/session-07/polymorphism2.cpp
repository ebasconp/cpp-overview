#include <iostream>
#include <cstring>

class Person
{
private:
	char first_name[32];
	char last_name[32];
	
public:
	Person(const char* first_name, const char* last_name)
	{
		strcpy(this->first_name, first_name);
		strcpy(this->last_name, last_name);
	}
	
	//virtual ~Person()
	//{
	//}
	
	virtual ~Person() = default;
	
	virtual void print() const
	{
		std::cout << last_name << ", " << first_name << "\n";
	}
	
	const char* get_first_name() const { return first_name; }
	const char* get_last_name() const { return last_name; }
};

class Worker: public Person
{
	char* company;
	
public:
	Worker(const char* first_name, const char* last_name, const char* company)
		: Person{first_name, last_name}, company{strdup(company)}
	{
	}
	
	~Worker()
	{
		free(company);
		std::cout << "Killing worker\n";
	}
	
	void print() const override
	{
		std::cout << get_last_name() << ", " << get_first_name() << " (" << company << ")\n";
	}
};



int main()
{
	Person* p[3];
	p[0] = new Person{"Juan", "Lopez"};
	p[1] = new Worker{"Julian", "Apaza", "Jalasoft"};
	p[2] = new Person{"Mafalda", "Gomez" };
	
	for (Person* e : p) e->print();
	
	for (Person* e : p) delete e;
}
