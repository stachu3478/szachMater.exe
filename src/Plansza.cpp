#include "Plansza.h"

#include <iostream>
#include <windows.h>
#include "Pole.h"

using namespace Szachy;
using namespace std;

Plansza::Plansza(unsigned int rozmiar)
{
    zresetuj(rozmiar);
}

Plansza::Plansza()
{
    zresetuj(8);
}

void Plansza::rysuj(char* dane, char* kolory)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << " ABCDEFGH " << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << i + 1;
        for (int j = 0; j < 8; j++)
        {
            SetConsoleTextAttribute(hConsole, *(kolory + i * 8 + j));
            cout << *(dane + i * 8 + j);
        }
        cout << i + 1 << endl;
    }
    SetConsoleTextAttribute(hConsole, 0);
    cout << " ABCDEFGH " << endl;
}

void Plansza::zresetuj(unsigned int rozmiar)
{
    delete m_Pola;
    m_Pola = Pole::generuj(rozmiar, rozmiar);
}

Pole* Plansza::pobierzPole(unsigned int poziom, unsigned int pion)
{
    return &m_Pola[poziom * 8 + pion - 1];
}

Plansza::~Plansza()
{
    //dtor
}
