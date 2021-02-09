#include <iostream>

#include <cstring>
#include <cstdlib>

char* concatenate(const char* x, const char* y)
{
	size_t lenx = strlen(x);
	size_t leny = strlen(y);
	
	char* buffer = (char*) malloc(lenx + leny + 1);
	
	//strcpy(buffer, x);
	//strcat(buffer, y);
	
	memcpy(buffer, x, lenx);
	memcpy(buffer + lenx, y, leny + 1);
	
	
	return buffer;
}

void release_string(char* p)
{
	free(p);
}

int main()
{
	const char* a = "Tesla buys $1.5 billion in bitcoin, sending its price soaring. ";
	const char* b = "The price of bitcoin rose to a new record above $43,000 on Monday";
	
	char* r = concatenate(a, b);
	std::cout << r << "\n";
	
	release_string(r);
}
