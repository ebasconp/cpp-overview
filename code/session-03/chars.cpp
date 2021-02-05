#include <iostream>

void p()
{
	char hw[] = "Hello world of programmers";
	std::cout << hw << "\n";
}

void q()
{
	char aux[100];
	aux[0] = 'C';
	aux[1] = '+';
	aux[2] = '+';
	std::cout << aux << "\n";
}


int main()
{
	const char* hw = "Hello world";
	//hw[6] = 'W'; //produces a segmentation fault
	
	std::cout << hw << "\n";
	

	char hw2[] = "Hello world";
	hw2[6] = 'W';
	std::cout << hw2 << "\n";
	
	p();
	q();
	
	
	
}
