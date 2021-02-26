#ifndef __ELIB_OBJECT_H
#define __ELIB_OBJECT_H

#include "String.h"

namespace elib
{
	class Object
	{
	public:
		Object() = default;
		virtual ~Object() = default;
		
		Object(const Object& ) = delete;
		Object& operator=(const Object& ) = delete;
		
		virtual bool equals(const Object& ) const;
		
		virtual String to_string() const;
	};
}

#endif

