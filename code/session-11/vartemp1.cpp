#include <iostream>


template <typename T, typename U>
auto sum(const T& a, const U& b)
{
	return a + b;
}


template <typename T, typename... Args>
auto sum(const T& a, const Args&... args)
{
	return a + sum(args...); 
}



template <typename T>
void println(const T& a)
{
	std::cout << a << "\n";
}

template <>
void println<bool>(const bool& x)
{
	std::cout << (x ? "true" : "false") << "\n";
}

template <>
void println<nullptr_t>(const nullptr_t&)
{
	std::cout << "null pointer\n";
}

void print() { }

template <typename T, typename... Args>
void print(const T& a, const Args&... args)
{
	println(a);
	print(args...);
}

template <typename... Args>
void print2(const Args&... args)
{
	(println(args), ...); // invoking println with each element on parameter pack
}

template <typename... Args>
auto sum2(const Args&... args)
{
	std::cout << "Parameter count: " << sizeof...(args) << "\n";
	return (args + ... + 0); // fold expression
}


int main()
{
	std::cout << sum(10, 20, 30, 40, 50, 60) << "\n";
	std::cout << sum2(10, 20, 30, 40, 50, 60) << "\n";
	
	print(10, 20, "hola", true, 14, nullptr, 25.5);
	print2(10, 20, "hola", true, 14, nullptr, 25.5);
	
	
}

