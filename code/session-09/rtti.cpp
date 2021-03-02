#include <iostream>

#include <typeinfo>

class Car
{
public:
	virtual ~Car() = default;
};

class CarVan : public Car
{
};

class House
{
};

class Department : public  House { };

int main()
{
	Car c;
	House* h = new House();
	
	Car* d = new CarVan();
	
	const std::type_info& t_c = typeid(c);
	const std::type_info& t_h = typeid(h);
	
	if (t_c == t_h)
		std::cout << "Son del mismo tipo\n";
	else
		std::cout << "NO son del mismo tipo\n";
	
	std::cout << "Tipo de c: " << t_c.name() << "\n";
	std::cout << "Tipo de h: " << t_h.name() << "\n";
	
	std::cout << typeid(*d).name() << "\n";
	
	CarVan* pd = dynamic_cast<CarVan*>(d);
	if (pd != nullptr)
	{
		std::cout << "CARVAN\n";
	}
	
	// This does not work because House is not polymorphic
	// House* house = new Department();
	// Department* dept = dynamic_cast<Department*>(house);
	// if (dept != nullptr)
	//  	std::cout << "DEPARTMENT\n";
	
	delete h;
	return 0;
}
