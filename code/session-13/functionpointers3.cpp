#include <iostream>


void print_progress(int percent)
{
	std::cout << percent << "%\n";
	
	if (percent  == 100)
		std::cout << "DONE!\n";
}

void f(int b, void(*callback)(int))
{
	for (int i = 0; i != b; i++)
	{
		if (i % (b / 100) == 0)
		{
			callback(i / (b / 100));
		}
	}
	callback(100);
}


int main()
{
	f(100'000'000, print_progress);
}
