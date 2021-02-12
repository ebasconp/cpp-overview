#include <iostream>
#include <cstring>

struct Product
{
	size_t id;
	char* description;
	char* brand;
	
	/*Product(size_t id, const char* description, const char* brand)
	{
		this->id = id;
		this->description = strdup(description);
		this->brand = strdup(brand);
		std::cout << "Product created\n";
	}*/
	
	// Overloaded constructor since C++11
	Product()
		: Product(0, "[Undefined]", "[Undefined]")
	{
		std::cout << "C++11 constructor\n";
	}	
	
	// Preferred constructor, using initializer lists
	Product(size_t id, const char* description, const char* brand)
		: id{id},
		  description{strdup(description)},
		  brand{strdup(brand)}
    {
	    std::cout << "Product created\n";
    }
    
    // Overloaded constructor before C++11
    /*Product()
		: id{0},
		  description{strdup("Undefined")}, 
		  brand{strdup("Undefined")}
    {
		std::cout << "Alternative constructor\n";
	}*/
	
	~Product()
	{
		free(description);
		free(brand);
		std::cout << "Instance released\n";
	}
};


int main()
{
	// Instance created in stack
	Product p { 425112345, "TV", "Samsung" };

	std::cout << p.brand << "\n";
	
	// Instance created in heap
	Product* p2 = new Product { 5234523, "TV", "Sony" };
	std::cout << p2->brand << "\n";
	delete p2;
	
	// Cannot use malloc because it does not invoke the constructor

	Product q;
	std::cout << q.id << "\n";
	std::cout << q.description << "\n";
}
