#include <iostream>

void test_mdarrays()
{
	int p[2][3];
	p[0][2] = 25;
	p[0][1] = 50;
	p[0][0] = 100;
	
	p[1][0] = 200;
	p[1][1] = 300;
	p[1][2] = 400;
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << p[i][j] << " ";
		}
		
		std::cout << "\n";
	}
}

void test_mdarrays_decay()
{
	int p[2][3];
	p[0][2] = 25;
	p[0][1] = 50;
	p[0][0] = 100;
	
	p[1][0] = 200;
	p[1][1] = 300;
	p[1][2] = 400;
	
	int* pp = (int*) p;
	std::cout << pp[0] << "\n";
	std::cout << *(pp + 1) << "\n";
	std::cout << *(pp + 2) << "\n";
	std::cout << *(pp + 3) << "\n";
	std::cout << pp[4] << "\n";
	std::cout << pp[5] << "\n";
	
}

int main()
{
	//test_mdarrays();
	
	test_mdarrays_decay();
}
