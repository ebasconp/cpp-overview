#include "String.h"

#include <cstring>

elib::String::String(const char* s)
	: len{strlen(s)}
{
	chars = new char[len + 1];
	memcpy(chars, s, len + 1);
}

elib::String::~String()
{
	delete [] chars;
}


elib::String::String(const String& s)
	: len{s.len}
{
	chars = new char[len + 1];
	memcpy(chars, s.chars, len + 1);
}

elib::String&
elib::String::operator=(const String& s)
{
	if (this == &s)	return *this;
	
	this->~String();

	len = s.len;
	chars = new char[len + 1];
	memcpy(chars, s.chars, len + 1);
	
	return *this;
}


bool 
elib::String::operator==(const String& s) const
{
	if (this == &s) return true;
	
	if (len != s.len) return false;
	
	return memcmp(chars, s.chars, len) == 0;
}

const char* elib::String::c_str() const
{
	return chars;
}
		
char elib::String::operator[](size_t index) const
{
	return chars[index];
}
