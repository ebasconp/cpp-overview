#include <iostream>

struct range_iterator
{
	int min;
	int max;
	
	bool operator!=(const range_iterator& r) const noexcept
	{
		return min != r.min || max != r.max;
	}
	
	int operator*() const noexcept { return min; }
	
	range_iterator& operator++()
	{
		min++;
		return *this;
	}
};

class range
{
	int min, max;
	
public:
	range(int min, int max) : min{min}, max{max} { }
	
	int get_min() const noexcept { return min; }
	int get_max() const noexcept { return max; }
	
	range_iterator begin()  { return range_iterator{min, max}; }
	range_iterator end()    { return range_iterator{max, max}; }
};


int main()
{
	range r { 10, 20 };
	
	for (auto e : r)
		std::cout << e << "\n";
		
	/*for (auto it = r.begin(); it != r.end(); ++it)
	{
		std::cout << *it << "\n";
	}*/
		
}
