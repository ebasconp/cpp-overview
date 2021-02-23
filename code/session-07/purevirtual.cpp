#include <iostream>

class Shape
{
public:
	virtual double get_area() const = 0;
	virtual ~Shape() = default;
};

class Circle : public Shape
{
	double r;
	
public:
	Circle(double r) : r {r} { }
	
	double get_area() const final
	{
		return 3.141592654 * r * r;
	}
};




int main()
{
	Circle s { 5 };
	
	Shape& a = s;
	std::cout << a.get_area() << "\n";
}
