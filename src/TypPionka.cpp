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

TypPionka* TypPionka::generuj()
{
    TypPionka typy[6];
    typy[0] = new TypPionka("Pion", "Najbardziej pospolity pionek", "O");
    typy[1] = new TypPionka("Skoczek", "Pionek potrafi¹cy przeskakikaæ inne pionki", "S");
    typy[2] = new TypPionka("Goniec", "Pionek bij¹cy na ukos", "G");
    typy[3] = new TypPionka("Wie¿a", "Pionek bij¹cy w kolumnach i rzêdach", "W");
    typy[4] = new TypPionka("Hetman", "Wa¿ny pionek, posiada najwiêcej mo¿liwoœci ruchu", "H");
    typy[5] = new TypPionka("Król", "Najwa¿niejszy pionek, nie mo¿e zostaæ zbity", "K");
    return typy;
}

std::string TypPionka::info()
{
    cout << nazwa << endl << opis << endl << "Reprezentowany przez literę " << litera << endl;
}

TypPionka::~TypPionka()
{
    //dtor
}
