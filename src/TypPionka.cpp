#include "TypPionka.h"
#include <string>
#include <iostream>

using namespace std;
using namespace Szachy;

TypPionka::TypPionka(std::string c_nazwa, std::string c_opis, char c_litera)
{
    nazwa = c_nazwa;
    opis = c_opis;
    litera = c_litera;
}

std::string TypPionka::info()
{
    cout << nazwa << endl << opis << endl << "Reprezentowany przez literę " << litera << endl;
}

TypPionka::~TypPionka()
{
    //dtor
}
