#include <set>
#include <iostream>
#include <string>
#include <tuple>

struct Tripleta
{
	int x, y, z;
	
	void print() const
	{
		std::cout << "(" << x << ", " << y << ", " << z << ")\n";
	}
};

struct TripletaLess
{
	bool operator()(const Tripleta& a, const Tripleta& b) const
	{
		return std::tie(a.z, a.y, a.x) < std::tie(b.z, b.y, b.x);
	};
};

int main()
{
	std::set<std::string> ns;
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
	
	std::set<Tripleta, TripletaLess> a;
	a.insert({ 10, 20, 30 });
	a.insert({ 5, 2, 10 });
	a.insert({ 10, 20, 25 });
	a.insert({ 15, 40, 2 });
	
	for (auto& e : a)
		e.print();
		
	std::set<std::string>::iterator it = ns.find("Marcos"); // O (log2 N)
	if (it == ns.end())
		std::cerr << "Not found\n";
	else
		std::cout << *it << "\n";
	
}
