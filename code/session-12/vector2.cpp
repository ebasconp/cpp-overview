#include <vector>
#include <iostream>
#include <string>

struct Animal
{
	virtual ~Animal() = default;
	
	virtual std::string to_string() const = 0;
};

struct Perro : public Animal
{
	std::string to_string() const { return "Perro"; }
};

struct Vaca : public Animal
{
	std::string to_string() const { return "Vaca"; }
};

struct Gato : public Animal
{
	std::string to_string() const { return "Gato"; }
};

int main()
{
	std::vector<Animal*> as;
	as.push_back(new Perro { });
	as.push_back(new Gato { });
	as.push_back(new Perro { });
	as.push_back(new Vaca { });
	
	for (auto& a : as)
		std::cout << a->to_string() << "\n";
	
	for (auto& a : as) delete a;
}
