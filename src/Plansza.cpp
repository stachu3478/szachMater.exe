#include "Plansza.h"

#include <iostream>
#include <windows.h>
#include "Pole.h"

using namespace Szachy;
using namespace std;

void Plansza::generujPola(int szerokosc, int wysokosc)
{
    unsigned int licznik = 0;
    for(int szer = 1; szer <= szerokosc; szer++)
    {
        for(int wys = 1; wys <= wysokosc; wys++, licznik++)
        {
            // cout << "Pole nr " << licznik << endl;
            m_Pola[licznik] = new Pole(szer, wys);
        }
    }
}

Plansza::Plansza(int rozmiar)
{
    cout << "Przygotowywanie planszy" << endl;
    generujPola(rozmiar, rozmiar);
    cout << "Przygotowywanie planszy koniec" << endl;
    //zresetuj(rozmiar);
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
        SetConsoleTextAttribute(hConsole, 7);
        cout << i + 1 << endl;
    }
    SetConsoleTextAttribute(hConsole, 7);
    cout << " ABCDEFGH " << endl;
}

void Plansza::zresetuj(int rozmiar)
{
    // delete m_Pola;
    generujPola(rozmiar, rozmiar);
}

Pole* Plansza::pobierzPole(unsigned int poziom, unsigned int pion)
{
    int indeks = poziom * 8 + pion - 9;
    cout << "Pobieram indeks " << indeks << endl;
    Pole* pole = m_Pola[indeks];
    cout << "Pobrane pole ma numer " << (int)pole->pobierzNumer() << endl;
    return pole;
}

Plansza::~Plansza()
{
    //dtor
}
