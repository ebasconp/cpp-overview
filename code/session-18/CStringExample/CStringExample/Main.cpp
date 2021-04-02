#include <iostream>

#include <string>

#include <atlstr.h>

int main()
{
	std::wstring s = L"Hello ";

	CString w = L"world";

	CString hw{ s.c_str() };

	hw += w;

	
	std::wcout << hw.GetString() << "\n";


}