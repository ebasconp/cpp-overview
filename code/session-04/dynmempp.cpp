#include <iostream>

#include <cstring>

int main()
{
	// operator new
	int* p = new int{64321};
	//int* p = new int(64321);
	std::cout << *p << "\n";
	
	delete p;
	
	// operator new[]
	int len = 1000000;
	char* text = new char[len]; // no se pueden inicializar los elementos
	
	strcpy(text, "Jalasoft");
	
	std::cout << text << "\n";
	
	
	delete [] text;
	
	
}
