#include "TypPionka.h"
#include <string>
#include <iostream>

using namespace std;
using namespace Szachy;

int* utworzPrzesuniecie(int x, int y)
{
    int xy[2] = { x, y };
    return xy;
}

TypPionka::TypPionka(std::string c_nazwa, std::string c_opis, char c_litera)
{
    nazwa = c_nazwa;
    opis = c_opis;
    litera = c_litera;
}

TypPionka* TypPionka::generuj()
{
    TypPionka* typy[6];
    typy[0] = new TypPionka("Pion", "Najbardziej pospolity pionek", 'O');
    typy[1] = new TypPionka("Skoczek", "Pionek potrafi¹cy przeskakikaæ inne pionki", 'S');
    typy[2] = new TypPionka("Goniec", "Pionek bij¹cy na ukos", 'G');
    typy[3] = new TypPionka("Wie¿a", "Pionek bij¹cy w kolumnach i rzêdach", 'W');
    typy[4] = new TypPionka("Hetman", "Wa¿ny pionek, posiada najwiêcej mo¿liwoœci ruchu", 'H');
    typy[5] = new TypPionka("Król", "Najwa¿niejszy pionek, nie mo¿e zostaæ zbity", 'K');
    return *typy;
}

std::string TypPionka::info()
{
    return nazwa + "\n" + opis + "\nReprezentowany przez literę " + litera + "\n";
}

int** TypPionka::mozliwosciRuchu()
{
    int x = 4, y = 2;
    int* pola[x];
    switch ((int)*litera.c_str())
    {
        case 'O':
            {
                pola[0] = utworzPrzesuniecie(2, 0);
                pola[1] = utworzPrzesuniecie(1, 0);
                pola[2] = utworzPrzesuniecie(1, 1);
                pola[3] = utworzPrzesuniecie(1, -1);
                //pola[0] = { 2, 0 }
                //pola[1] = { 1, 0 };
            }; break;
    };
    return pola;
}

TypPionka::~TypPionka()
{
    //dtor
}
