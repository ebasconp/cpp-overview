#pragma once

#include "Object.h"

namespace elib
{
	class ArrayList : public Object
	{
		size_t cap;
		size_t len;	
		Object** items;
		
	public:
		ArrayList(size_t initial_capacity = 7);
		~ArrayList();
		
		void add(Object* obj);
		size_t size() const;
		
		void print() const;
		
	private:
		void resize();
	};
}
