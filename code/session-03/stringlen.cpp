#include <iostream>


size_t string_len(const char* s)
{
	
	//size_t n = 0;
	
	/*for (size_t i = 0; s[i] != '\0'; i++)
	{
		n++;
	}
	*/
	
	/*while (*s != '\0')
	{
		s++; n++;
	}
	
	return n;*/
	
	const char* aux = s;
	
	while (*s != 0) s++;
	
	return s - aux;
}


int main()
{
	const char* a = "Training branchs: C++ overview";
	char b[] = "C++ reference manual";
	auto c = "hola";
	
	std::cout << string_len(a) << "\n";
	std::cout << string_len(b) << "\n";
	std::cout << string_len(c) << "\n";
	
	// Const-ness
	/*
	 * char* q;       // es un puntero que se puede modificar y sus elementos pueden escribirse
	 * const char* q; // el puntero se puede modificar PERO los elementos apuntados son constantes
	 * char* const q; // el puntero ES constante pero los elementos no son constantes
	 * const char* const q; // el puntero ES contantes Y los elementos también
	 */
}
