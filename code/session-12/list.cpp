#include <list>
#include <string>
#include <iostream>

#include <algorithm>

template <typename Container>
void print(const Container& c)
{
	for (auto& e : c)
	{
		std::cout << e << "\n";
	}
}

int main()
{
	std::list<std::string> ns;
	
	ns.push_back("Juan");
	ns.push_back("María");
	ns.push_front("José");
	ns.push_front("Ramón");
	
	//Ramon-> Jose -> Juan -> Maria
	
	for (auto& e : ns)
	{
		std::cout << e << "\n";
	}
	
	std::list<std::string>::iterator it = std::find(ns.begin(), ns.end(), "Monica"); // do sequencial look up
	if (it == ns.end())
		std::cerr << "Not found";
	else
		std::cout << *it << "\n";
		
		
	std::list<int> p = { 10, 15, 14, 25, 80, 2, 10, 100, 1, 30, 72, 73, 74, 75, 76 };
	
	for (auto it = p.begin(); it != p.end(); /* nothing */)
	{
		if (*it % 3 != 0)
			it = p.erase(it);
		else
			++it;
	}
	
	print(p);
	
}
