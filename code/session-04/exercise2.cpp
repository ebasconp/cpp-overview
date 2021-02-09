#include <iostream>


char** create_string_array()
{
	char** array = new char*[1];
	array[0] = nullptr;
	
	return array;
}


int main()
{
	char** s = create_string_array();
}
