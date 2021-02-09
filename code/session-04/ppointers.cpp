#include <iostream>
#include <cstring>

int get_mes_actual(const char** m)
{
	*m = "febrero";
	return 2;
}

void test_1()
{
	const char* mes = "[desconocido]";
	int d = get_mes_actual(&mes);
	
	std::cout << d << "; " << mes << "\n";
}

void test_2()
{
	char** string_list = new char*[5];
	
	string_list[0] = new char[11];
	string_list[1] = new char[5];
	string_list[2] = new char[8];
	string_list[3] = new char[5];
	string_list[4] = new char[7];
	
	strcpy(string_list[0], "javascript");
	strcpy(string_list[1], "java");	
	strcpy(string_list[2], "python");	
	strcpy(string_list[3], "ruby");	
	strcpy(string_list[4], "pascal");	

	for (int i = 0; i < 5; i++)
	{
		std::cout << string_list[i] << "\n";
	}
	
	for (int i = 0; i < 5; i++)
	{
		delete [] string_list[i];
	}
	
	delete [] string_list;
	
}

int main()
{
	//test_1();
	test_2();
}
