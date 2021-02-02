#include <iostream>
#include <iomanip>

int main()
{
	int once = 11;
	int* p_once = &once;
	
	std::cout << p_once << "\n";
	std::cout << *p_once << "\n";
	
	*p_once = *p_once + 15;
	std::cout << *p_once << "\n";
	
	std::cout << once << "\n";
	
	void* v_once = p_once;
	std::cout << v_once << "\n";
	//std::cout << *v_once << "\n"; //*v_once does not make sense
	
	int valor = *((int*)v_once);
	std::cout << valor << "\n";
}
