#include <iostream>
#include <iomanip>

int main()
{
	int* p = (int*) 0xDEADBEEF;     // Dangling pointer
	std::cout << std::hex << p << "\n";
	
	//std::cout << *p << "\n";

	int* q = nullptr; //NULL
	if (q == nullptr)
	{
		std::cout << "PUNTERO NULO\n";
	}
	
}
