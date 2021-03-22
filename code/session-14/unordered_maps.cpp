#include <iostream>
#include <unordered_map>
#include <string>

void test0()
{
	std::unordered_map<std::string, int> meses;
	
	meses["enero"] = 1;
	meses["febrero"] = 2;
	meses["marzo"] = 3;
	meses["abril"] = 4;
	meses["mayo"] = 5;
	meses["junio"] = 6;
	meses["julio"] = 7;
	meses["agosto"] = 8;
	meses["septiembre"] = 9;
	meses["octubre"] = 10;
	meses["noviembre"] = 11;
	meses["diciembre"] = 12;
	
	for (const std::pair<std::string, int>& p : meses)
	{
		std::cout << p.first << "; " << p.second << "\n";
	}
}

struct hash_int_p
{
	size_t operator()(const int* p) const
	{
		return *p;
	}
};

struct int_p_comparator
{
	bool operator()(const int* a, const int* b) const
	{
		return *a == *b;
	}
};

void test1()
{
	std::unordered_map<int*, std::string, hash_int_p, int_p_comparator> meses;
	meses[new int{1}] = "January"; // O(1) + K
	meses[new int{2}] = "February";
	meses[new int{3}] = "March";
	meses[new int{4}] = "April";
	meses[new int{5}] = "May";
	meses[new int{6}] = "June";
	meses[new int{7}] = "July";
	meses[new int{8}] = "August";
	meses[new int{9}] = "September";
	meses[new int{10}] = "October";
	meses[new int{11}] = "November";
	meses[new int{12}] = "December";	
	
	for (auto& e : meses)
	{
		std::cout << *(e.first) << "; " << e.second << "\n";
	}
	
	int f = 3;
	auto it = meses.find(&f); // O(1)
	if (it == meses.end())
		std::cerr << "Not found\n";
	else
		std::cout << it->second << "\n";
		
	for (auto& e : meses)
		delete e.first;
}

int main()
{
	//test0();
	test1();
	
}
