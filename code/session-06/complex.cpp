#include <iostream>

struct Complex
{
	double r;
	double im;
	
	Complex operator+(const Complex& b) const
	{
		return { r + b.r, im + b.im };
	}
	
	Complex operator+(double d) const
	{
		return operator+({d, 0});
	}
	
	Complex& operator+=(const Complex& c)
	{
		this->r += c.r;
		this->im += c.im;
		
		return *this;
	}
	
	Complex& operator++() // prefix ++
	{
		r++;
		return *this;
	}
	
	Complex operator++(int) // postfix ++
	{
		Complex result { *this };
		r++;
		return result;
	}
	
	/*operator double()
	{
		return r;
	}*/
	
	void print() const
	{
		std::cout << "(" << r << "; " << im << ")\n";
	}
	
	bool operator==(const Complex& c) const
	{
		if (this == &c)
		{
			return true;
		}
		
		return r == c.r && im == c.im;
	}
};

Complex operator+(double d, const Complex& c)
{
	return c + d;
}


int main()
{
	Complex m { 10, 2 }; // 10 + 2i
	Complex n { 5, 4 }; // 5 + 4i
	
	Complex o = m + n;
	//Complex o = m.operator+(n);
	
	Complex p = m + 4;
	p.print();
	
	Complex q = 10 + n;
	q.print();
	
	Complex r { 1, 1};
	Complex s { r += Complex { 2, 2 } }; // copy
	
	r.print();
	s.print();
	
	Complex a { 15, 2 };
	(++a).print();
	(a++).print();
	a.print();
	
	//double z = (double) a;
	//std::cout << z << "\n";
	
	Complex b { 15, 2 };
	Complex c { 15, 3 };
	
	std::cout << (b == b) << "\n";
	
}
