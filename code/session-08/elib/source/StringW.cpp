#include "StringW.h"

#include <cstring>


elib::StringW::StringW(const String& src) : str{src}
{
}
		
elib::String
elib::StringW::to_string() const
{
	return str;
}
		
bool
elib::StringW::equals(const Object& src) const
{
	const StringW* src_ptr = dynamic_cast<const StringW*>(&src);
	if (src_ptr == nullptr)
		return false;
		
	return this->compare_to(*src_ptr);
}
		
int
elib::StringW::compare_to(const Comparable& src) const
{
	const StringW* src_ptr = dynamic_cast<const StringW*>(&src);
	if (src_ptr == nullptr)
		return 0xFFFFFFFF;
		
	return strcmp(str.c_str(), src_ptr->c_str());
}

const char* 
elib::StringW::c_str() const
{
	return str.c_str();
}
