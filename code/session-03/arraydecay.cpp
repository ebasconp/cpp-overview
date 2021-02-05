#include <iostream>

void iterate(int* a, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		//std::cout << i[a] << "\n";
		std::cout << *(i + a) << "\n";
	}
}


int main()
{
	int arr[] = { 1, 8, 3, 12, 1, 4, 10 };
	
	iterate(arr, 7);
	
}
