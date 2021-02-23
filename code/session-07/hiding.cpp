#include <iostream>
#include <cstring>

struct A
{
	int sum(int a, int b) const { return a + b; }
	int sum(int a, int b, int c) const { return a + b + c; }
};

struct B : A
{
	using A::sum; // this "unhiddes" the A::sum methods
	
	// this method hides the A::sum methods
	int sum(int a, int b, int c, int d) const { return a + b + c + d; }
};

struct Animal
{
	void talk() const { std::cout << "[]\n"; }
};

struct Dog : Animal
{
	void talk() const { std::cout << "Gau\n"; }
};

struct Cat : Animal
{
	void talk() const { std::cout << "Miau\n"; }
};



int main()
{
	/*A a;
	B b;
	
	std::cout << a.sum(10, 20) << "\n";
	std::cout << b.sum(10, 20, 30) << "\n";
	std::cout << b.sum(10, 20, 30, 40) << "\n";*/
	
	Cat c;
	c.talk();
	
	Dog d;
	d.talk();
	
	
	Animal* m = new Cat();
	m->talk();
	
	delete m;
}
