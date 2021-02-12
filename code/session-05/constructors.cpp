#include <iostream>
#include <cstring>

// Before constructors, in C

struct Product
{
	size_t id;
	char* description;
	char* brand;
};

void init_product(Product* p, size_t aId, const char* aDescription, const char* aBrand)
{
	p->id = aId;
	p->description = strdup(aDescription);
	p->brand = strdup(aBrand);
}

int main()
{
	Product p;
	init_product(&p, 1231, "Switch", "Nintendo");
	std::cout << p.brand << "\n";
}
