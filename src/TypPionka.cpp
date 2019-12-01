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

TypPionka::TypPionka(std::string c_nazwa, std::string c_opis, char c_litera):
    m_MozliweRuchy(10)
{
    nazwa = c_nazwa;
    opis = c_opis;
    litera = c_litera;
    // m_MozliweRuchy = mozliweRuchy;
}

///DO gry
/*TypPionka** TypPionka::generuj()
{
    cout << "Tworzenie typów pionków" << endl;
    TypPionka* typy[6];
    typy[0] = new TypPionka("Pion", "Najbardziej pospolity pionek", 'O');
    typy[1] = new TypPionka("Skoczek", "Pionek potrafiący przeskakikaæ inne pionki", 'S');
    typy[2] = new TypPionka("Goniec", "Pionek bij¹cy na ukos", 'G');
    typy[3] = new TypPionka("Wie¿a", "Pionek bij¹cy w kolumnach i rzêdach", 'W');
    typy[4] = new TypPionka("Hetman", "Wa¿ny pionek, posiada najwiêcej mo¿liwoœci ruchu", 'H');
    typy[5] = new TypPionka("Król", "Najwa¿niejszy pionek, nie mo¿e zostaæ zbity", 'K');
    cout << "Utworzono typy pionków" << endl;
    return typy;
}*/

std::string TypPionka::info()
{
    return nazwa + "\n" + opis + "\nReprezentowany przez literę " + litera + "\n";
}

// Nie wiem co dalej z tym
void TypPionka::dodajRuch(int x, int y)
{
    Array<char> xy(2);
    xy.push(x);
    xy.push(y);
    m_MozliweRuchy.push(xy);
}
/*Array<int*>& TypPionka::mozliwosciRuchu()
{
    Array<int*> pola(4);
    switch ((int)*litera.c_str())
    {
        case 'O':
            {
                cout << "Dodaje przesuniecie 1" << endl;
                pola.push(utworzPrzesuniecie(2, 0));
                cout << "Dodaje przesuniecie 2" << endl;
                pola.push(utworzPrzesuniecie(1, 0));
                cout << "Dodaje przesuniecie 3" << endl;
                pola.push(utworzPrzesuniecie(1, 1));
                cout << "Dodaje przesuniecie 4" << endl;
                pola.push(utworzPrzesuniecie(1, -1));
                //pola[0] = { 2, 0 }
                //pola[1] = { 1, 0 };
            }; break;
    };
    Array<int*>& polaRef = pola;
    return polaRef;
}*/

TypPionka::~TypPionka()
{
    //dtor
}
