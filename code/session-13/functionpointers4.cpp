#include <iostream>
#include <cstring>
#include <cstdlib>
#include <tuple>

int comp_int(const void* a, const void* b)
{
	return *static_cast<const int*>(a) - *static_cast<const int*>(b);
}

struct CI
{
	int n;
	const char* c;
};

int comp_ci(const void* a, const void* b)
{
	const CI* ci1 = static_cast<const CI*>(a);
	const CI* ci2 = static_cast<const CI*>(b);
	
	const auto& t1 = std::tie(ci1->n, ci1->c);
	const auto& t2 = std::tie(ci2->n, ci2->c);
	if (t1 == t2) return 0;
	
	if (t1 < t2) return -1;
	
	return 1;
	
}

int main()
{
	int e[] = { 10, 2, 5, 1, 4, 20, -2, 6 };
	
	qsort(e, 8, sizeof(int), comp_int);
	
	for (int x : e) std::cout << x << "\n";
	
	CI c[] = { { 1234567, "P" },  { 1233321, "LP"}, { 1233321, "CB"} };
	
	qsort(c, 3, sizeof(CI), comp_ci);
	
	for (CI& x : c) std::cout << x.n << ", " << x.c << "\n";
	
}
