#include <iostream>

#include "ArrayList.h"
#include "Object.h"
#include "String.h"
#include "StringW.h"

//using elib::String;
using namespace elib; // use only in cpp files, not in h

void test_string()
{
	String s { "Hello" };
	String w = "hello";
	
		
	if (s == w)
		std::cout << "IGUALES\n";
	else
		std::cout << s.c_str() << ", " << w.c_str() << "\n";
}


void test_object()
{
	Object o;
	std::cout << o.to_string().c_str() << "\n";
}

void test_stringw()
{
	Comparable* c1 = new StringW( "Hello" );
	Comparable* c2 = new StringW( "Hello" );
	
	std::cout << c1->compare_to(*c2) << "\n";
	
	delete c1;
	delete c2;
}

void test_array_list()
{
	ArrayList x;
	x.add(new StringW("Hello"));
	x.add(new StringW("World"));
	x.add(new Object());
	
	x.print();
}

int main()
{
	//test_string();
	//test_object();
	//test_stringw();
	test_array_list();
	
}

