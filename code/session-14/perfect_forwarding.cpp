#include <iostream>

class A
{
	int* n;
	
public:
	A(int n) : n{new int{n}} { std::cout << "ctor\n"; }
	~A() { delete n; }
	
	A(const A& src) : n{new int{*(src.n)} } { std::cout << "copy\n"; }
	
	A(A&& src) : n{src.n} { std::cout << "movector\n"; src.n = nullptr; }
	
	void print() const
	{
		std::cout << *n << "\n";
	}
};

template <typename K, typename V>
class Pair
{
	K key;
	V value;
	
public:
/*
	Pair(const K& key, const V& value)
		: key{key}, value{value}
	{
	}
	
	Pair(const K& key, V&& value)
		: key{key}, value{std::move(value)}
	{
	}
	
	Pair(K&& key, const V& value)
		: key{std::move(key)}, value{value}
	{
	}
	
	Pair(K&& key, V&& value)
		: key{std::move(key)}, value{std::move(value)}
	{
	}
*/

	// This constructor replaces all the ones above
	template <typename KK, typename VV>
	Pair(KK&& key, VV&& value)
		: key{std::forward<KK>(key)},
		  value{std::forward<VV>(value)}
    {
	}
	
	const K& get_key() const { return key; }
	const V& get_value() const { return value; }
};

int main()
{
	A a { 30 };
	A b { 40 };
	
	std::cout << "***\n";
	
	Pair<A, A> p1 { A { 10 }, A { 20 } };
	
	std::cout << "---\n";
	
	Pair<A, A> p2 { a, A { 50 } };
	std::cout << "---\n";
	
	Pair<A, A> p3 { A { 60 }, b };
	
	std::cout << "---\n";
	
	Pair<A, A> p4 { a, b };
	
	
}
