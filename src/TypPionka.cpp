#include "TypPionka.h"
#include <string>
#include <iostream>

#include "Array.h"

using namespace std;
using namespace Szachy;

int*& utworzPrzesuniecie(int x, int y)
{
    int* xy = new int[2]{ x, y };
    int*& xd = xy;
    return xd;
}

TypPionka::TypPionka(std::string c_nazwa, std::string c_opis, char c_litera)
{
    nazwa = c_nazwa;
    opis = c_opis;
    litera = c_litera;
}

TypPionka::~TypPionka()
{
    //dtor
}
