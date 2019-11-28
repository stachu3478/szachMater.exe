#include "Pole.h"
#include <cmath>
#include <string>
#include <iostream>

using namespace Szachy;
using namespace std;

Pole::Pole(int num, Kolor* kolor)
{
    m_Kolor = kolor;
    if (num < 0 || num > 63)
    {
        cout << "Niewłaściwa pozycja pola\n";
        throw -1;
    }
    this->numer = num;
}

Pole::Pole(int rzad, int kolumna)
{
    m_Kolor = 0;
    if (rzad < 1 || rzad > 8 || kolumna < 1 || kolumna > 8)
    {
        cout << "Niewłaściwa pozycja pola\n";
        throw -1;
    }
    this->numer = rzad * 8 + kolumna - 9;
    // cout << "Nowe pole ma numer " << (int)numer << endl;
}

Pole::~Pole()
{}

Pole& Pole::operator=(const Pole& rhs)
{
    if (this == &rhs) return *this; //assignment operator
    this->numer = rhs.numer;
    return *this;
}

/// CO TO MA KUŹWA ZNACZYĆ? BRAK PRZECHODNIEJ REKURSJI WSKAŹNIKÓW???!!!
/*Pole& Pole::operator=(const Pionek& rhs)
{
    if (m_pionek == &rhs) return *this; //assignment operator
    if (m_pionek != 0)
    {
        m_pionek->zbij();
    }
    m_pionek = rhs;
    m_pionek->przenies(this);
    return *this;
}*/

/// Przeniesiono do planszy
/*Pole* Pole::generuj(int szerokosc, int wysokosc)
{
    Pole* pola[szerokosc * wysokosc];
    unsigned int licznik = 0;
    for(int szer = 1; szer <= szerokosc; szer++)
    {
        for(int wys = 1; wys <= wysokosc; wys++, licznik++)
        {
            // cout << "Pole nr " << licznik << endl;
            pola[licznik] = new Pole(szer, wys);
        }
    }
    return *pola;
}*/

bool Pole::operator==(const Pole& rhs)
{
    if (this == &rhs) return true;
    return this->numer == rhs.numer;
}

bool Pole::operator!=(const Pole& rhs)
{
    return !(*this == rhs);
}

string Pole::nazwa()
{
    string nazwaPola = "";
    nazwaPola += char(48 + this->numer / 8); //cyferka
    nazwaPola += char(65 + this->numer % 8); //literka
    return nazwaPola;
}
