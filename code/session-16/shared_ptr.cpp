#include <memory>
#include <string>
#include <iostream>

class Saludar
{
	std::string name;
	
public:
	Saludar(const std::string& name) : name{name} {}
	
	void saludar() const { std::cout << "Hola " << name << "\n"; }
	
	~Saludar()
	{
		std::cout << "Adios " << name << "\n";
	}
};

void p(const Saludar& s)
{
	s.saludar();
}

int main()
{
	auto s1 = std::make_shared<Saludar>("René");
	auto s2 = std::make_shared<Saludar>("Mónica");
	auto s3 = std::make_shared<Saludar>("Mario");
	
	auto s4 = s1;
	auto s5 = s2;
	auto s6 = s2;
	
	p(*s1);
	
	s1 = nullptr;
	std::cout << "----\n";
	s4 = s6;
	std::cout << "----\n";
}
