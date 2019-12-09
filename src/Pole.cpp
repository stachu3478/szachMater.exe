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

Pole::Pole(Pole* pole)
{
    numer = pole->pobierzNumer();
}

Pole::~Pole()
{}

Pole& Pole::operator=(const Pole& rhs)
{
    if (this == &rhs) return *this; //assignment operator
    this->numer = rhs.numer;
    return *this;
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
    nazwaPola += char(49 + this->numer / 8); //cyferka
    nazwaPola += char(65 + this->numer % 8); //literka
    return nazwaPola;
}
