#include <vector>
#include <string>
#include <iostream>

template <typename Container>
void print(const Container& c)
{
	for (auto& e : c)
		std::cout << e << "\n";
}

class X
{
	int* x;
	
public:
	X(int x) : x{new int{x}} { }
	X(const X& src) : x{new int{*(src.x)}} { }
	
	X& operator=(const X& src) 
	{
		delete x;
		x = new int{*(src.x)};
		return *this;
	}
	
	
	~X() { delete x; }
	
	operator int() const { return *x; }
};

template <typename T>
class Wrapper
{
	T* ptr;
	
public:
	Wrapper(T* ptr) : ptr { ptr } { }
	Wrapper(const Wrapper<T>& src)
		: ptr{new T{*(src.ptr)}}
	{
		
	}
	
	~Wrapper() { delete ptr; }
	
	const T& get() const { return *ptr; }
};

int main()
{
	std::vector<int> ns { 10, 20, 30, 40, 50, 60, 70 };
	ns.push_back(71);
	ns.push_back(72);
	ns.push_back(73);
	
	ns[0]++;
	
	ns[1] = 25;
	
	print(ns);
	
	std::vector<X*> xs;
	xs.push_back(new X{10});
	xs.push_back(new X{20});
	xs.push_back(new X{30});
	xs.push_back(new X{40});
	
	for (auto& e : xs)	std::cout << (int) *e << "\n";
	
	for (auto& e : xs) delete e;
	
	std::vector<Wrapper<X>> ws;
	ws.push_back(Wrapper<X> { new X{99} });
	ws.push_back(new X{98});
	ws.push_back(new X{97});
	ws.push_back(new X{96});
	
	for (auto& e : ws)	std::cout << (int) e.get() << "\n";

	
}
