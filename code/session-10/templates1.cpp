#include <iostream>


template <typename Operando1, typename Operando2>
//auto sum(const Operando1& o1, const Operando2& o2) -> decltype(o1 + o2) //C++11
auto sum(const Operando1& o1, const Operando2& o2)  // C++14
{
	return o1 + o2;
}


void test0()
{
	std::cout << sum(16.5, 14.5) << "\n";
	std::cout << sum(5, 25.2) << "\n";
}


template <size_t N>
size_t factorial()
{
	size_t r = 1;
	for (size_t i = 1; i <= N;  i++)
	{
		r *= i;
	}
	
	return r;
}

void test1()
{
	std::cout << factorial<7>() << "\n";
}

auto main() -> int
{
	//test0();
	test1();
	return 0;
}
