#include <variant>
#include <iostream>
#include <vector>


struct Perro { void talk() const { std::cout << "gau\n"; } };
struct Gato { void talk() const { std::cout << "miau\n"; } };
struct Vaca { void talk() const { std::cout << "muuu\n"; } };
struct Persona { void talk() const { std::cout << "las oscuras golondrinas\n"; } };

using animal = std::variant<Perro, Gato, Vaca, Persona>;


int main()
{
	std::vector<animal> animals;
	
	animals.push_back(Perro{ });
	animals.push_back(Gato{ });
	animals.push_back(Persona{ });
	animals.push_back(Vaca{ });
	animals.push_back(Perro{ });
	
	for (auto& a : animals)
	{
		std::visit([](auto& e) { e.talk(); }, a); //ad-hoc polymorphism
	}
}


