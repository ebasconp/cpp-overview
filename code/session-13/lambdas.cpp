#include <iostream>

template <typename T, typename S>
void do_something(const T& a, S s)
{
    s(a);
}

template <typename A, typename B, typename Proc>
void calculate(const A& a, const B& b, Proc p)
{
	auto r = p(a, b);
	std::cout << r << "\n";
}

struct Animal
{
	virtual ~Animal() = default;
	
	virtual void talk() const = 0;
};

struct Perro : Animal
{
	void talk() const override { std::cout << "GAU\n"; }
};

struct Gato : Animal
{
	void talk() const override { std::cout << "MIAU\n"; }
};

template <typename T, typename Proc>
auto process(const T& arg, Proc p)
{
	return p(arg);
}


auto main() -> int
{
    do_something(5, [](int n)
    {
		std::cout << n << "\n";
	});
	
	do_something("Hola", [](auto& s)
	{
		std::cout << "STRING: " << s << "\n";
	});

	calculate(10, 30, [](auto a, auto b) { return a + b; });
	
	auto r = process(2, [](int a) -> Animal*
	{
		if (a == 1) return new Perro();
		
		return new Gato();
	});
	
	r->talk();
	delete r;
}
