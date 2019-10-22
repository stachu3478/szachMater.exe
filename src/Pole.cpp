#include "Pole.h"
#include <cmath>
#include <string>
#include <iostream>

using namespace Szachy;
using namespace std;

Pole::Pole(unsigned int poziom, unsigned int pion)
{
    m_pionek = 0;
    if (poziom < 1 || poziom > 8 || pion < 1 || pion > 8)
    {
        cout << "Niewłaściwa pozycja pola\n";
        throw -1;
    }
    this->numer = poziom * 8 + pion - 1;
}

Pole::~Pole()
{
    delete m_pionek;
}

Pole& Pole::operator=(const Pole& rhs)
{
    if (this == &rhs) return *this; //assignment operator
    this->numer = rhs.numer;
    return *this;
}

Pole& Pole::operator=(const Pionek& rhs)
{
    if (m_pionek == &rhs) return *this; //assignment operator
    if (m_pionek != 0)
    {
        m_pionek->zbij();
    }
    m_pionek = rhs;
    m_pionek->przenies(this);
    return *this;
}

Pole generuj(unsigned int szerokosc, unsigned int wysokosc)
{
    Pole pola[szerokosc * wysokosc];
    unsigned int licznik = 0;
    for(unsigned int szer = 1; szer <= szerokosc; szer++)
    {
        for(unsigned int wys = 1; wys <= wysokosc; wys++, licznik++)
        {
            pola[licznik] = new Pole(szer, wys);
        }
    }
    return pola;
}

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
