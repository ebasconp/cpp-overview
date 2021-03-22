#include <iostream>

#include <map>
#include <string>

struct compare_meses
{
	bool operator()(const std::string& a, const std::string& b) const
	{
		auto lena = a.length();
		auto lenb = b.length();
		
		return std::tie(lena, a) < std::tie(lenb, b);
	}
};

int main()
{
	std::map<std::string, std::string> numbers;
	
	numbers.insert(std::make_pair("one", "uno"));
	numbers.insert(std::pair<std::string, std::string>("two", "dos"));
	numbers.insert(std::pair {"three", "tres" });
	numbers["four"] = "cuatro";
	
	for (auto& p : numbers)
	{
		std::cout << "Key: " << p.first << "; Value: " << p.second << "\n";
	}
	
	auto compare_2 = [](auto& a, auto& b)
	{
		return std::tie(a[a.length() - 1], a) < std::tie(b[b.length() - 1], b);
	};
	
	//std::map<std::string, int, compare_meses> meses;
	
	using mi_mapa = std::map<std::string, int, decltype(compare_2)>;
	
	mi_mapa meses { compare_2 };
	
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
	
	for (auto& p : meses)
		std::cout << p.first << ": " << p.second << "\n";

	meses.erase("noviembre");
	
	mi_mapa::iterator it = meses.find("noviembre");
	//auto it = meses.find("xnoviembre");
	

	
	if (it == meses.end())
		std::cerr << "NOT FOUND\n";
	else
		std::cout << it->first << "; " << it->second << "\n";
	
	return 0;
}
