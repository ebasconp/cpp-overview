#include <iostream>
#include <cstring>

#include <stdexcept>

class MyException : public std::exception
{
	char msg[64];
	
public:
	MyException(const char* msg) { strcpy(this->msg, msg); }
	
	~MyException() { std::cout << "Deleting exception\n"; }
	
	MyException(const MyException& src)
	{
		strcpy(msg, src.msg);
		std::cout << "Copying exception!!!\n";
	}
	
	const char* what() const noexcept override { return msg; }
};


class IntArray
{
	int* s;
	
public:
	IntArray(size_t size) : s { new int[size] } { }
	~IntArray()
	{ 
		std::cout << "Destroying\n";
		delete [] s;
	}
};

void a()
{
	std::cout << "Welcome to a\n";
	
	//int* s = new int[100'000'000]; // exception unsafe
	
	IntArray x { 100'000'000 };
	
	throw MyException("Algo extraño ha pasado");
	
	std::cout << "Bye from a\n";
}

int main()
{
	try
	{
		a();
	}
	catch (const std::exception& e)
	{
		std::cerr << "EXCEPTION: " << e.what() << "\n";
	}
}
