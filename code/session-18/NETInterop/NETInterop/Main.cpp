#include <iostream>
#include <string>
#include <windows.h>

using namespace System;
using namespace System::Runtime::InteropServices;

ref class X
{
public:
    int y;
};

int main()
{
    X^ instance = gcnew X();
    instance->y = 2;

    Console::WriteLine(instance->y);

    String^ s = gcnew String("Hello world from .NET String");
    Console::WriteLine("This is a test from .NET");

    /*std::wstring p;
    for (int i = 0; i < s->Length; i++)
    {
        p += s[i];
    }*/
    
    BSTR bstr = (BSTR) ((void*) Marshal::StringToBSTR(s));

    std::wcout << bstr << "\n";

    ::SysFreeString(bstr);

    return 0;
}
