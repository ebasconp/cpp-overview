#include <iostream>

#include "mydll.h"

int main()
{
    const char* p = is_even_or_odd(10);
    std::cout << p << "\n";


    std::cout << is_even_or_odd(11) << "\n";

    Person r{ "Elena", "Rokova", 1995 };
    r.show();
}
