#include <iostream>
#include <map>
#include <string>

#include <optional>
#include <functional>

struct Person
{
	std::string fn;
	std::string ln;
	size_t id;
};

template <typename T>
using optional_ref = std::optional<std::reference_wrapper<const T>>;

optional_ref<const Person> find_by_id(const std::map<size_t, Person>& ps, size_t id)
{
	auto it = ps.find(id);
	if (it == ps.end())
	{
		return { };
	}
	
	return { std::ref(it->second) };
}

int main()
{
	std::map<size_t, Person> m;
	m[12341234] = Person { "Maria", "Chavez", 12341234 };
	m[67452342] = Person { "Edson", "Rivera", 67452342 };
	m[56745134] = Person { "Julian", "Oros", 56745134 };
	
	optional_ref<Person> p = find_by_id(m, 12341234);
	if (p.has_value())
		std::cout << p.value().get().ln << ", " << p.value().get().fn << "\n";
	else
		std::cerr << "Person not found\n";
		
	try
	{
		std::optional<std::string> s { };
		
		std::cout << s.value_or("NO VALUE") << "\n";
		
		std::cout << s.value() << "\n";
	}
	catch (const std::bad_optional_access& ex)
	{
		std::cerr << "EXCEPTION: " << ex.what() << "\n";
	}
	
	

		
}
