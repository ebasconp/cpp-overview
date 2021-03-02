#include <iostream>

struct A
{
	int x = 5;
	
	void show() const { std::cout << "A: " << x << "\n"; }
};

struct B
{
	int x;
	
	void show() const { std::cout << "B: " << x << "\n"; }
};

struct C : A, B { };

int main()
{
	C c;
	c.A::show();
	
	c.B::x = 260;
	c.B::show();

}
