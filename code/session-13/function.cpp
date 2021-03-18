#include <iostream>
#include <vector>
#include <string>
#include <functional>


void print(const std::string& s)
{
	std::cout << s << "\n";
}

void contar(const std::string& s)
{
	std::cout  << s.length() << "\n";
}


int main()
{
	std::string m = "enero";
	
	std::vector<std::function<void (const std::string&)>> funcs;
	funcs.push_back(print);
	funcs.push_back(contar);
	
	int index = 3;
	funcs.push_back([index](auto& s) { std::cout << s[index] << "\n"; });
	
	for (auto& f : funcs)
	{
		f(m);
	}
	
	
}
