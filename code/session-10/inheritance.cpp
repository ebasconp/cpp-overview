#include <iostream>

template <typename T>
class A
{
public: 
	void show(const T& x) const
	{
		std::cout << x << "\n";
	}
};

template <typename T>
class B : public A<T>
{
	T n;
	
public:
	B(const T& n) : n{n} { }
	
	void show_elem() const
	{
		//A<T>::show(n);
		this->show(n);
	}
};

int main()
{
	B<double> m{15};
	m.show_elem();
}
