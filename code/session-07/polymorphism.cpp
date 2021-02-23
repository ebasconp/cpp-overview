#include <iostream>

struct Animal
{
	virtual void talk() const
	{
		std::cout << "[Nothing to talk]\n";
	}
};

struct Dog : public Animal
{
	void talk() const override
	{
		std::cout << "Gau\n";
	}
};

struct Cat : public Animal
{
	void talk() const override
	{
		std::cout << "Miau\n";
	}
};


void do_something(Animal& a)
{
	a.talk();
}


int main()
{
	Cat c;
	Dog d;
	do_something(c);
	do_something(d);
}
