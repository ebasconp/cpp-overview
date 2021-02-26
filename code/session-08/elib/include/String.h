#ifndef __ELIB_STRING_H
#define __ELIB_STRING_H
// Include guards - Header guards

#include <cstddef>

namespace elib
{
	class String
	{
		char* chars;
		size_t len;
		
	public:
		String(const char* s);
		~String();
		
		String(const String& s);
		String& operator=(const String& s);
		
		bool operator==(const String& ) const;
		
		const char* c_str() const;
		
		char operator[](size_t index) const;
		
		inline size_t length() const
		{
			return len;
		}
	};
}

#endif
