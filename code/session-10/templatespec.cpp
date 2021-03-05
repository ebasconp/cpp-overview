#include <iostream>

struct Complex
{
	double real;
	double im;
};

template <typename T>
void show(const T& e)
{
	std::cout << e << "\n";
}

template <>
void show<Complex>(const Complex& e)
{
	std::cout << "Complex: (" << e.real << "; " << e.im << ")\n";
}

template <>
void show<int>(const int& e)
{
	std::cout << "Integer: " << e << "\n";
}

template <typename T>
class Hello
{
	T n;
	T m;
	
public:
	Hello(const T& n) : n{n}, m{n} { }
	
	const T& get_n() const noexcept { return n; }
	const T& get_m() const noexcept { return m; }
};

template <>
class Hello<double>
{
	double p;
	
public:
	Hello(double p) : p{p} { }
	
	void show() const noexcept { std::cout << "DOUBLE: " << p << "\n"; }
};

template <typename A, typename B>
struct Container
{
	A a;
	B b;
};

template <typename A>
struct Container<A, int>
{
	A a;
	int n;
	
	void repeat() const
	{
		for (auto i = 0U; i < n; i++)
			std::cout << a << "\n";
	}	
		
};

int main()
{
	show(Complex { 10, 2 });
	show(10);
	show(10.2);
	
	Hello<int> x { 4 };
	std::cout << x.get_n() << "\n";
	
	Hello<double> y { 4.5 };
	y.show();
	
	Container<int, double> a { 10, 20 };
	std::cout << a.b << "\n";
	
	Container<double, int> b { 10, 5 };
	b.repeat();
}
