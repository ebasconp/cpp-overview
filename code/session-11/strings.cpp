#include <iostream>
#include <string>  
#include <cstring>

void test1()
{
	std::string s;
	
	std::cout << "[" << s << "]\n";
	
	s += "hola";
	s += " ";
	s += "mundo";
	
	std::cout << "[" << s << "]\n";	
	auto len = s.length(); // O(1)
	for (auto i = 0U; i < len; i++)
	{
		std::cout << s.at(i) << "\n";
	}
	
	std::cout << s.at(200) << "\n"; //std::out_of_range if out of range
}

void test2()
{
	std::string s;
	
	std::cout << "[" << s << "]\n";
	
	s += "hola";
	s += " ";
	s += "mundo";
	
	std::cout << "[" << s << "]\n";	
	auto len = s.length(); // O(1)
	for (auto i = 0U; i < len; i++)
	{
		std::cout << s[i] << "\n";
	}
	
	std::cout << s[200] << "\n"; //does not throw
}

void test3()  // using iterators before C++11
{
	std::string s;
	
	std::cout << "[" << s << "]\n";
	
	s += "hola";
	s += " ";
	s += "mundo C++98";
	
	for (std::string::const_iterator it = s.begin();
		 it != s.end();
		 ++it)
	{
		std::cout << *it << "\n";
	}
}

void test4()  // using range-based-for-loop after C++11
{
	std::string s;
	
	std::cout << "[" << s << "]\n";
	
	s += "hola";
	s += " ";
	s += "mundo C++11";
	
	for (char k : s)
	{
		std::cout << k << "\n";
	}
}

void test5()
{
	std::string h = "Hello";
	std::string w = "world";
	
	char aux[60];
	strcpy(aux, h.c_str()); // returns the const char*
	strcat(aux, " ");
	strcat(aux, w.data());  // returns the const char*
	
	std::cout << aux << "\n";
}

void test6()
{
	std::string a { "abeja" };
	std::string b { "bolivia" };
	
	std::cout << a.compare(b) << "\n";
}

void test7()
{
	using namespace std::string_literals;
	
	auto a = "Hello world"; // const char*
	auto b = "Hello world"s; // std::string
	
	
	std::cout << b << " : " << b.length() <<"\n";
}

void test8()
{
	int p = 45;
	
	std::string s = "Su edad es de " + std::to_string(p) + " años";
	
	std::cout << s << "\n";
	
	
	std::string h = "3141234123421";
	long long r = std::stoll(h) * 2;
	std::cout << "R: " << r << "\n";
}

void test9()
{
	std::string s = "Jav";
	
	s.push_back('a');
	
	std::cout << s << "\n";
}

int main()
{
	try
	{
		test9();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << "\n";
	}
	
}
