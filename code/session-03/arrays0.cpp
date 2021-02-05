#include <iostream>

//#define n 6.2

int main()
{
	constexpr int n = 6;

	int f = 20;	
	int arr[n] = { 1, 56, 8, 14, 24, 3 };

	
	//for (int i = 0; i < n + 100000; i++) // segmentation fault
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\n";
	}
	
	// Starting C++11
	for (auto& e : arr) // must be a static array
	{
		std::cout << e << "\n";
	}
}
