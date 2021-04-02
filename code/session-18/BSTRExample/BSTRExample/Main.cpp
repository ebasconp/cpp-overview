#include <windows.h>

#include <iostream>

void print(const wchar_t* s)
{
	std::wcout << s << "\n";
}

size_t length(BSTR str)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(str);
	bytes -= sizeof(size_t);

	size_t* plen = reinterpret_cast<size_t*>(bytes);
	return *plen / sizeof(wchar_t);
}

int main()
{
	BSTR fp = ::SysAllocString(L"Felices Pascuas");

	print(fp);

	std::cout << length(fp) << "\n";
	std::cout << ::SysStringLen(fp) << "\n";
	std::cout << ::SysStringByteLen(fp) << "\n";


	::SysFreeString(fp);


}