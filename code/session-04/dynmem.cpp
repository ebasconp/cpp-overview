#include <iostream>

#include <cstdlib>

int main()
{
	int len = 10;
	//int* p = (int*) malloc(len * sizeof(int));
	int* p = (int*) calloc(len, sizeof(int)); //calloc initializes everything to zero
	p[0] = 100;
	p[4] = 1000;
	p[9] = 800;
	
	
	std::cout << p << "\n";

	//Resize
	p = (int*)realloc(p, 12 * sizeof(int));
	p[10] = 66;
	p[11] = 99;
	
	std::cout << p << "\n";
	for (int i = 0; i < 12; i++)
	{
		std::cout << p[i] << "\n";
	}




	free(p);
}
