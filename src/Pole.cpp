#include "Pole.h"
#include <cmath>
#include <string>
#include <iostream>

using namespace Szachy;
using namespace std;

Pole::Pole(int poziom, int pion)
{
    //ctor
    if (poziom < 1 || poziom > 8 || pion < 1 || pion > 8)
    {
        cout << "Niewłaściwa pozycja pola\n";
        throw -1;
    }
    this->numer = poziom * 8 + pion - 1;
}

Pole::~Pole()
{
    //dtor
}

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
    nazwaPola += char(48 + this->numer / 8); //cyferka
    nazwaPola += char(65 + this->numer % 8); //literka
    return nazwaPola;
}
