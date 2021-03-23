#include <iostream>
#include <map>
#include <string>

#include <optional>

struct Person
{
	std::string fn;
	std::string ln;
	size_t id;
};


std::optional<Person> find_by_id(const std::map<size_t, Person>& ps, size_t id)
{
	auto it = ps.find(id);
	if (it == ps.end())
	{
		//return std::nullopt;
		return { };
	}
	
	return it->second;
}

int main()
{
	std::map<size_t, Person> m;
	m[12341234] = Person { "Maria", "Chavez", 12341234 };
	m[67452342] = Person { "Edson", "Rivera", 67452342 };
	m[56745134] = Person { "Julian", "Oros", 56745134 };
	
	std::optional<Person> p = find_by_id(m, 12341234);
	if (p.has_value())
		std::cout << p.value().ln << ", " << p.value().fn << "\n";
	else
		std::cerr << "Person not found\n";
		
}
