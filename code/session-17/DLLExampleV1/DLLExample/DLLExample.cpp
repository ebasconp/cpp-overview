#include <iostream>

#include "mydll.h"

int main()
{
    Person r{ "Elena", "Rokova", 1995 };
    Person s{ "Juana", "Robins", 1925 };
    r.show();
    s.show();
}
