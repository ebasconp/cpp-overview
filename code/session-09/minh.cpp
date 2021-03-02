#include <iostream>

class Movedor
{
	int x = 0; // starting C++11
	int y = 0;
	
public:
	void mover(int deltax, int deltay)
	{
		this->x += deltax;
		this->y += deltay;
	}
	
	void mostrar_posicion() const
	{
		std::cout << "Posición: (" << x << "; " << y << ")\n";
	}
};

class Volador
{
	int h;
	
public:
	void volar(int h)
	{
		this->h = h;
	}
	
	void mostrar_altura() const
	{
		std::cout << "Altura: " << h << " metros\n";
	}
};

class Animal
{
public:
	void comer() { std::cout << "Comiendo\n"; }
};

class Avion : public Volador, public Movedor { };

class Perro : public Animal, public Movedor { };

void mostrar_posicion(const Movedor& m)
{
	std::cout << &m << "\n";
	m.mostrar_posicion();
}

int main()
{
	Avion a;
	a.volar(1000);
	a.mover(1000, 1000);
	
	a.mostrar_altura();
	
	std::cout << &a << "\n";
	mostrar_posicion(a);
	
	Perro p;
	p.comer();
	p.mover(100, 0);
	
	std::cout << &p << "\n";
	mostrar_posicion(p);
	
}

