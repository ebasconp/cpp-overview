#include <iostream>
#include <cstring>

class Car
{
	char brand[32];
	
public:
	Car(const char* b)
	{
		strcpy(brand, b);
	}
	
	Car(const Car&) = delete; // Since C++11
	
	Car& operator=(const Car&) = delete; // Since C++11
	
	void print() const
	{
		std::cout << brand << "\n";
	}
};


int main()
{
	Car b { "Ford" };
	b.print();
	
	Car c { "Fiat" };
	c.print();

	
}
