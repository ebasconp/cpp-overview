#pragma once
//#pragma once no es parte del estandar

#include "Object.h"

namespace elib
{
	class Comparable : public Object
	{
	public:
		virtual int compare_to(const Comparable& obj) const = 0;
	};
}

// Si una clase tiene todos sus métodos virtuales puros,
// en C++ se llama ABC: Abstract Base Class
