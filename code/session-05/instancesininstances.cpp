#include <iostream>
#include <cstring>

struct Product
{
	size_t id;
	char* description;
	char* brand;
	
	Product()
		: Product(0, "[Undefined]", "[Undefined]")
	{
		std::cout << "C++11 constructor\n";
	}	
	
	Product(size_t id, const char* description, const char* brand)
		: id{id},
		  description{strdup(description)},
		  brand{strdup(brand)}
    {
	    std::cout << "Product created\n";
    }
	
	~Product()
	{
		free(description);
		free(brand);
		std::cout << "Instance released\n";
	}
	
	void print() const
    {
     std::cout << "(" << id << ") " << description << ", " << this->brand << "\n";
    }
};

struct ProductPair
{
	Product a;
	Product b;
};

int main()
{
	//ProductPair p { Product{ 1, "TV", "Sony" }, Product{ 2, "XBox", "Microsoft" } };
	ProductPair p { { 1, "TV", "Sony" }, { 2, "XBox", "Microsoft" } };
		
	p.b.print();
}
