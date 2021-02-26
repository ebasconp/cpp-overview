#include "ArrayList.h"

#include <cstdlib>
#include <iostream>


elib::ArrayList::ArrayList(size_t initial_capacity)
	: cap{initial_capacity}, len{0}, items{static_cast<Object**>(malloc(cap * sizeof(Object*)))}
{
}

elib::ArrayList::~ArrayList()
{
	for (size_t i = 0; i < len; i++)
		delete items[i];
		
	free(items);
}
		
void elib::ArrayList::add(Object* obj)
{
	if (len == cap)
		resize();

	items[len++] = obj;
}

void elib::ArrayList::resize()
{
	size_t newcap = cap * 2;
	items = static_cast<Object**>(realloc(items, newcap * sizeof(Object*)));
}

size_t elib::ArrayList::size() const
{
	return len;
}
		
void elib::ArrayList::print() const
{
	for (size_t i = 0; i < len; i++)
		std::cout << items[i]->to_string().c_str() << "\n";
}
