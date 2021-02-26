#pragma once

#include "Comparable.h"

namespace elib
{
	class StringW : public Comparable
	{
		String str;
		
	public:
		StringW(const String& src);
		
		String to_string() const override;
		
		bool equals(const Object& src) const override;
		
		int compare_to(const Comparable& src) const override;
		
		const char* c_str() const;
	};
}
