#include <iostream>

#include <cstring>


void test_strcmp()
{
	int x = strcmp("hola", "hola");
	std::cout << x << "\n";
	
	const char* a = "hormiga";
	const char* b = "avispa";
	
	std::cout << strcmp(a, b) << "\n";
	std::cout << strcmp(b, a) << "\n";
	
	int y = strncmp("hola", "holas", 4);
	std::cout << y << "\n";
}

void test_strtok()
{
	const char* texto_orig = "Bolivianos el hado propicio";
	char texto[128];
	strcpy(texto, texto_orig);
	
	char* word = strtok(texto, " ");
	
	while (word  != nullptr)
	{
		std::cout << word << "\n";
		word = strtok(nullptr, " ");
	}
	
	std::cout << "Texto: " << texto;
}

// IBM ICU realiza comparaciones de cadenas internacionales

int main()
{
	//test_strcmp();
	test_strtok();
}
