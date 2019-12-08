#include "Ruch.h"

#include <iostream>
#include "Pionek.h"
#include "Pole.h"
#include "TypPionka.h"

using namespace Szachy;
using namespace std;

Ruch::Ruch()
{}

Ruch::Ruch(Pionek* pionek, Pole* od, Pole* na)
{
    m_Pionek = pionek;
    m_PozycjaStartowa = od;
    m_PozycjaDocelowa = na;
}

Ruch::~Ruch()
{
    //dtor
}
