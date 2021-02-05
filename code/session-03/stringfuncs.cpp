#include <iostream>
#include <cstring>

void test_strlen()
{
	auto hw = "Hello world again";
	size_t len = strlen(hw);
	std::cout << len << "\n";
	
	const wchar_t* widehw = L"Hello wide-world";
	size_t wlen = wcslen(widehw);
	std::cout << wlen << "\n";
}

void test_strcpy()
{
	const char* n = "Arturo";
	const char* a = "Lopez";
	
	char nombre_completo[100];
	strncpy(nombre_completo, n, 100);
	strncat(nombre_completo, " ", 100);
	std::cout << strncat(nombre_completo, a, 100) << "\n";
	
}

void test_strstr()
{
	auto c = "Todos los caminos conducen a Roma y a Francia";
	
	auto r = strstr(c, "Madrid");
	
	if (r == nullptr)
	{
		std::cout << "NOT FOUND\n";
	}
	else
	{	
		std::cout << r << "\n";
	}
}


int main()
{
	test_strlen();
	test_strcpy();
	test_strstr();
}
