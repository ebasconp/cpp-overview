#include <iostream>
#include <string>

#include <windows.h>

#include "../TestDLL/IClass.h"

using SAY_HI_PTR = void(*)();
using IS_EVEN_OR_ODD_PTR = const char* (*)(int);
using CREATE_MYCLASS_PTR = IClass* (*)(const char*);

template <typename PROC>
PROC LoadFunction(HMODULE module, const char* name)
{
    FARPROC fproc = ::GetProcAddress(module, name);
    if (fproc == nullptr)
    {
        throw std::string { "Could not load function " } + name;
    }

    return reinterpret_cast<PROC>(fproc);
}

int main()
{
    try
    {
        HMODULE module = ::LoadLibrary(L"TestDLL.dll");
        if (module == 0)
        {
            std::cerr << "Could not load TestDLL.dll\n";
            return -1;
        }

        auto sh = LoadFunction<SAY_HI_PTR>(module, "say_hi");
        auto eoo = LoadFunction<IS_EVEN_OR_ODD_PTR>(module, "is_even_or_odd");
        auto cmc = LoadFunction<CREATE_MYCLASS_PTR>(module, "create_my_class");


        sh();
        std::cout << eoo(10) << "\n";
        std::cout << eoo(15) << "\n";

        IClass* mc = cmc("Hello from DLL");
        if (mc != nullptr)
            mc->print();
        else
            std::cerr << "NULL POINTER";

        bool result = ::FreeLibrary(module);
        std::cout << "R: " << result << "\n";
        return 0;
    }
    catch (const std::string& e)
    {
        std::cerr << e << "\n";
        return -2;
    }

}

