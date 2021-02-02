#include <iostream>
#include <iomanip>

int main()
{
	int num = 0xDEADBEEF;
	
	unsigned char* p = (unsigned char*) &num;
	
	std::cout << std::hex << (int) *p << "\n";
	
	p++;
	std::cout << std::hex << (int) *p << "\n";
	
	p++;
	std::cout << std::hex << (int) *p << "\n";
	
	p++;
	std::cout << std::hex << (int) *p << "\n";
	
	p++;
	std::cout << std::hex << (int) *p << "\n";
	
}
