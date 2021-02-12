#include <iostream>
#include <cstring>

// POD: Plain old data
// - Primitive type
// - Array of PODs
// - Struct of PODs

struct Person // POD
{
	char first_name[32];
	char last_name[32];
	size_t birth_year;
};

struct PersonNoPod // NO-POD
{
	char* first_name;
	char* last_name;
	size_t birth_year;
};

int main()
{
	Person p { "Raul", "Perez", 1921};
	
	std::cout << p.first_name << "\n";
	
	Person* p2 = (Person*) malloc(sizeof(Person));
	strcpy((*p2).first_name, "Pedro");
	std::cout << p2->first_name << "\n";
	free(p2);
	
	
	//Person* p3 = new Person {"Raul", "Perez", 1921}; //Needs a constructor
	//std::cout << p3->first_name << "\n";
	
	Person* p3 = new Person{};
	strcpy(p3->first_name, "Susana");
	std::cout << p3->first_name << "\n";
	delete p3;
	
	Person students[3];
	strcpy(students[0].first_name, "Juana");
	std::cout << students[0].first_name << "\n";
	
	
	
	
}
