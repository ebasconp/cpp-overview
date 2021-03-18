#include <iostream>

typedef void (*PSALUDAR)();

struct Saludar
{
	PSALUDAR saludar;
};

void hi()
{
	std::cout << "HELLO\n";
}

void hola()
{
	std::cout << "HOLA\n";
}

void create_saludar_es(Saludar& s)
{
	s.saludar = hola;
}

void create_saludar_en(Saludar& s)
{
	s.saludar = hi;
}


int main()
{
	Saludar es;
	create_saludar_es(es);
	
	Saludar en;
	create_saludar_en(en);
	
	es.saludar();
	en.saludar();
}

