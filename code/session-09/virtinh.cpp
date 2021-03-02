#include <iostream>
#include <cstring>

class Object
{
public:
	virtual ~Object() = default;
	virtual void show() const = 0;
};

class PersonInfo : public virtual Object
{
	char fullname[64];
	
public:
	PersonInfo(const char* fn) { strcpy(fullname, fn); }
	
	void show() const override { std::cout << "Person: " << fullname << "\n"; }
	
	const char* get_full_name() const { return fullname; }
};

//Abstract Base Class
class Equallable : public virtual Object
{
public:
	virtual bool equals(const Object& e) const = 0;
};

class Person : public PersonInfo, public Equallable
{
public:
	//Person(const char* fn) : PersonInfo(fn) { }
	using PersonInfo::PersonInfo;
	
	bool equals(const Object& e) const override
	{ 
		auto* p = dynamic_cast<const PersonInfo*>(&e);
		if (p == nullptr)
			return false;
			
		return strcmp(p->get_full_name(), get_full_name()) == 0;
	}
};


int main()
{
	Object* o1 = new Person { "Juan Lopez" };
	Equallable* o2 = new Person { "Juan Lopez" };
	
	o1->show();
	o2->show();
	
	std::cout << o2->equals(*o1) << "\n";
	
	delete o1;
	delete o2;
}
