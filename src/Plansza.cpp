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
            Kolor* kolor = &(((licznik / 8 + licznik % 8) % 2) ? m_KolorPolaA : m_KolorPolaB);
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

void Plansza::rysuj()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << " ABCDEFGH " << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << i + 1;
        for (int j = 0; j < 8; j++)
        {
            int index = i * 8 + j;

            Pionek* pionek = m_PozycjePionkow[index];
            string litera = pionek ? pionek->jakaLitera() : " ";
            int kolorPionka = pionek ? pionek->JakiKolor()->JakaWartosc() : 0;

            Pole* pole = m_Pola[index];
            char kolor = pole->JakiKolor()->JakaWartosc() * 16 + kolorPionka;

            SetConsoleTextAttribute(hConsole, kolor);
            cout << litera;
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
    Pole* pole = m_Pola[indeks];
    return pole;
}

bool Plansza::pobierzPolePrzes(Pole*& pole, int x, int y)
{
    int pion = pole->pion() + y;
    int poziom = pole->poziom() + x;
    if (
        pion > 0
        && pion < 9
        && poziom > 0
        && poziom < 9
    )
    {
        pole = pobierzPole(poziom, pion);
        return true;
    }
    return false;
}

void Plansza::przydzielPionek(Pionek* pionek)
{
    char id = pionek->jakaPozycja()->pobierzNumer();
    if (m_PozycjePionkow[id] != 0)
    {
        Pionek* zbity = m_PozycjePionkow[id];
        zbity->zbij();
    }
    m_PozycjePionkow[id] = pionek;
}

void Plansza::przeniesPionek(Pionek* pionek, Pole* pozycja)
{
    char id = pionek->jakaPozycja()->pobierzNumer();
    m_PozycjePionkow[id] = 0;
    pionek->przenies(pozycja);
    przydzielPionek(pionek);
}

Plansza::~Plansza()
{
    //dtor
}
