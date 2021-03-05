#include <iostream>

template <typename T>
class ArrayList
{
	T* items;
	size_t cap;
	size_t n;
	
public:
	ArrayList(size_t cap = 7)
		: items{ new T[cap] }, cap{cap}, n{0}
	{
	}
	
	~ArrayList()
	{
		delete [] items;
	}
	
	ArrayList<T>& push_back(const T& elem)
	{
		if (n == cap)	resize();
		
		items[n++] = elem;
		
		return *this;
	}
	
	void print() const
	{
		for (size_t i = 0; i < n; i++)
			std::cout << items[i] << "\n";
	}
	
	bool is_empty() const noexcept
	{
		return n == 0;
	}
	
private:
	void resize()
	{
		size_t new_cap = cap * 2;
		T* new_items = new T[new_cap];
		for (size_t i = 0; i < cap; i++)
		{
			new_items[i] = items[i];
		}
		
		delete [] items;
		items = new_items;
		
		cap = new_cap;
	}
};


int main()
{
	ArrayList<int> ints;
	ints.push_back(2).push_back(8)
		.push_back(10).push_back(15).push_back(2).push_back(10)
		.push_back(20).push_back(30)
		.push_back(40);
	
	ints.print();
	
	ArrayList<char> chars;
	chars.push_back('a').push_back('b').push_back('c');
	chars.print();
	
	ArrayList<double> d;
	std::cout << d.is_empty() << "\n";
}
