#include <iostream>
#include <cstring>
#include <ctime>

constexpr size_t SIZE = 1'000'000'000;

class Fat
{
	char* s;
	
public:
	Fat() : s{new char[SIZE]} { }
	
	// RULE OF 3
	~Fat() { delete [] s; }
	
	Fat(const Fat& src) : s{new char[SIZE]}
	{
		std::cout << "ctor\n";
		memcpy(s, src.s, SIZE);
	}
	
	Fat& operator=(const Fat& src)
	{
		std::cout << "op=\n";
		delete [] s;
		
		s = new char[SIZE];
		memcpy(s, src.s, SIZE);
		
		return * this;
	}
	
	//RULE OF 5:
	//MOVE CONSTRUCTOR
	Fat(Fat&& src) : s{src.s}
	{
		std::cout << "move ctor\n";
		src.s = nullptr;
	}
	
	//MOVE OPERATOR=
	Fat& operator=(Fat&& src)
	{
		std::cout << "move op=\n";
		delete [] s;
		s = src.s;
		src.s = nullptr;
		
		return *this;
	}
};

Fat crear()
{
	Fat f;
	Fat g = std::move(f);
	return g;
}

int main()
{
	clock_t t0 = clock();
	Fat f;
	f = crear();
	auto t1 = clock();
	
	std::cout << (t1 - t0) << "\n";
}
