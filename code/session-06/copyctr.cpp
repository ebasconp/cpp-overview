#include <iostream>
#include <cstring>

class Car
{
private:
	char* brand;
	char* model;
	size_t year;
	
public:
	Car(const char* brand, const char* model, size_t year)
		: brand{strdup(brand)},
		  model{strdup(model)},
		  year{year}
	{
		std::cout << "Ctor\n";
	}
	
	Car(const Car& c)
		: brand{strdup(c.brand)},
		  model{strdup(c.model)},
		  year{c.year}
	{
		std::cout << "Copy ctor\n";
	}
	
	Car& operator=(const Car& c)
	{
		if (this == &c)
			return *this;
		
		this->~Car();
		
		brand = strdup(c.brand);
		model = strdup(c.model);
		
		year = c.year;
		
		return *this;
	}
	
	void print() const
	{
		std::cout << brand << " " << model << " [" << year << "]\n";
	}
	
	~Car()
	{
		free(brand);
		free(model);
	}
};


int main()
{
	Car c  { "VW", "Peta", 1975 };
	Car c2 { "Mercedes", "C5", 2022 };
	
	Car c3 = c; // copy
	c3.print();
	
	c3 = c2; // assignment
	c3.print();
	
	c3 = c3;
	c3.print();
}
