#include <iostream>


int main()
{
	int a = 4;
	a = 8;
	a++;
	
	double pi = 3.1415;
	
	std::cout << a << "\n";
	std::cout << pi << "\n";
	
	// From C++11:
	auto r = 25;
	auto s = 3.1415;
	auto p = 3.1516f;
	
	std::cout << r << "\n";
	std::cout << s << "\n";
	
	const int z = 25;
	std::cout << z << "\n";
	
	int no = 0;
	std::cout << "NO: " << no << "\n";
	
	int i = 0;
	while (i != 10)
	{
		int j = i + 1;
		std::cout << j << "\n";
		i++;
	}
}
