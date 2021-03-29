#include <iostream>
#include <memory>

struct Child;

struct Parent
{
	std::shared_ptr<Child> child;
	
	~Parent() { std::cout << "Bye parent\n"; }
	
	void say_something() const
	{
		std::cout << "I'm a parent\n";
	}
};

struct Child
{
	std::weak_ptr<Parent> parent;
	
	~Child() { std::cout << "Bye child\n"; }
	

};


void test0()
{
	auto parent = std::make_shared<Parent>();
	auto child = std::make_shared<Child>();
	
	parent->child = child;
	child->parent = parent;
	
	child->parent.lock()->say_something();
}

void test1()
{
	std::weak_ptr<Parent> wp;
	
	
	{
		auto p = std::make_shared<Parent>();
		wp = p;
		wp.lock()->say_something();
		std::cout << wp.expired() << "\n";
	}
	
	std::cout << "AFUERA\n";
	std::cout << wp.expired() << "\n";
	
	if (auto sp = wp.lock())
	{
		sp->say_something();
	}
	else
	{
		std::cout << "Already deleted\n";
	}
	
	
	
}


int main()
{
	//test0();
	test1();
}
