#include <unordered_set>
#include <iostream>
#include <string>
#include <tuple>

int main()
{
	std::unordered_set<std::string> ns;
	ns.insert("Fernando");
	ns.insert("Gabriel");
	ns.insert("Jorge");
	ns.insert("Mirko");
	ns.insert("Marco");
	ns.insert("Esther");
	ns.insert("Sergio");
	ns.insert("Rafael");
	ns.insert("Gramsci");
	
	for (auto& e : ns)
		std::cout << e << "\n";
	

		
	//std::unordered_set<std::string>::iterator it = ns.find("Marcos"); // O (log2 1)
	auto it = ns.find("Marco"); // O (log2 1)
	if (it == ns.end())
		std::cerr << "Not found\n";
	else
		std::cout << *it << "\n";
	
}
