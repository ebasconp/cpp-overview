#include "Object.h"

#include <typeinfo>

bool
elib::Object::equals(const Object& src) const
{
	return this == &src;
}

elib::String
elib::Object::to_string() const
{
	return typeid(*this).name();
}
