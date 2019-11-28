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
            Kolor* kolor = &((licznik % 2) ? m_KolorPolaA : m_KolorPolaB);
            m_Pola[licznik] = new Pole(licznik, kolor);
            m_PozycjePionkow[licznik] = 0;
        }
    }
}

Plansza::Plansza(int rozmiar):
    m_KolorPolaA("Oliwkowy", 4),
    m_KolorPolaB("Brązowy", 6)
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

void Plansza::przydzielPionek(Pionek* pionek)
{
    char id = pionek->jakaPozycja()->pobierzNumer();
    if (m_PozycjePionkow[id] != 0)
    {
        cout << "To pole jest już zajęte!" << endl;
        throw pionek;
    }
    m_PozycjePionkow[id] = pionek;
}

Plansza::~Plansza()
{
    //dtor
}
