#include <memory>
#include <iostream>
#include <cstdlib>
#include <cstring>

class Point
{
	int x;
	int y;
	
public:
	Point(int x, int y) : x{x}, y{y} { }
	
	void print() const
	{
		std::cout << "(" << x << "; " << y << ")\n";
	}
	
	~Point()
	{
		std::cout << "Bye\n";
	}
};

struct Motor
{
	~Motor() { std::cout << "Borrando motor\n"; }
};

struct Volante
{
	~Volante() { std::cout << "Borrando volante\n"; }
};

class Carro
{
	//Motor* motor;
	//Volante* volante;
	
	std::unique_ptr<Motor> motor;
	std::unique_ptr<Volante> volante;
	
public:
	Carro() : motor{new  Motor()}, volante{new Volante()}
	{
		throw 1;
	}
	
	~Carro()
	{
	}
};



void test0()
{
	std::unique_ptr<Point> ptrA { new Point{10, 20} };
	auto ptrB = std::make_unique<Point>(20, 30);
	
	ptrA->print();
	ptrB->print();
	
	Point* p = ptrB.get();
	std::cout << p << "\n";
	
	auto ptrC = std::move(ptrB);
	std::cout << ptrC.get() << "\n";
	std::cout << ptrB.get() << "\n";
}



void test1()
{
	std::unique_ptr<char, void(*)(void*)> s1 { static_cast<char*>(malloc(100)), free };
	std::unique_ptr<char, void(*)(void*)> s2 { static_cast<char*>(malloc(100)), free };
	std::unique_ptr<char, void(*)(void*)> s3 { static_cast<char*>(malloc(100)), free };
	
	strcpy(s1.get(), "Hello");
	strcpy(s2.get(), "world");
	strcpy(s3.get(), "of programmers");
	
	std::cout << s1.get() << "\n";
	std::cout << s2.get() << "\n";
	std::cout << s3.get() << "\n";
}

void test2()
{
	try
	{
		Carro c;
	}
	catch (...)
	{
		std::cerr << "Destructor\n";
	}
	
}

int main()
{
	//test0();
	//test1();
	test2();
}
