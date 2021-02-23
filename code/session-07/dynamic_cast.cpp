#include <iostream>
#include <cstring>

class Animal
{
public:
	virtual void talk() const = 0;
	virtual ~Animal() = default;
};

class Dog : public Animal
{
	private: char name[32];
	
	
public:
	Dog(const char* n) { strcpy(name, n); }

	void talk() const override { std::cout << "GAU\n"; }
	void bite() const { std::cout << name << " is biting\n"; }
};

class Cat : public Animal
{
public:
	void talk() const override { std::cout << "MIAU\n"; }
};

void process(const Animal* a)
{
	a->talk();
	
	const Dog* d = dynamic_cast<const Dog*>(a);
	if (d != nullptr)
		d->bite();
}

int main()
{
	//Dog d { "Rufus" };
	Cat d;
	process(&d);
}
