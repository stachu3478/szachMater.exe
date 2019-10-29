#include "Ruch.h"

#include <iostream>
#include "Pionek.h"
#include "Pole.h"
#include "TypPionka.h"

using namespace Szachy;
using namespace std;

Ruch::Ruch(Pionek* pionek, Pole* od, Pole* na, Pionek* zbityPionek)
{
    m_Pionek = pionek;
    m_PozycjaStartowa = od;
    m_PozycjaDocelowa = na;
    m_ZbityPionek = zbityPionek;
    m_Wykonany = false;
}

void Ruch::renderuj()
{
    // TODO polyfill dla nazwy gracza
    cout << 'Gracz' << ' przeniósł z ' << m_PozycjaStartowa->nazwa() << ' na ' << m_PozycjaDocelowa->nazwa() << endl;
    if(m_ZbityPionek != 0)
    {
        cout << 'Pionek ' << m_ZbityPionek->nazwa() << ' został zbity.' << endl;
    }
}

void Ruch::wykonaj()
{}

void Ruch::cofnij()
{}

Ruch::~Ruch()
{
    //dtor
}
