#include <iostream>

struct X
{
	int n;
	
	X(int n) : n{n} { }

	~X() { std::cout << "Destroying\n"; }
};

template <typename T>
class Wrapper
{
	T elem;
	
public:
	Wrapper(const T& elem) : elem{elem} { }
	
	const T& get() const noexcept { return elem; }
};

template <typename T>
class Wrapper<T*>
{
	T* elem;
	
public:
	Wrapper(T* elem) : elem{elem} { }
	~Wrapper() { delete elem; }
	
	const T& get() const noexcept { return *elem; }
};

int main()
{
	Wrapper<int> p{10};
	std::cout << p.get() << "\n";
	
	Wrapper<X*> q{new X{15}};
	std::cout << q.get().n << "\n";
}
