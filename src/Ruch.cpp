#include "Ruch.h"

#include <iostream>
#include "Pionek.h"
#include "Pole.h"
#include "TypPionka.h"

using namespace Szachy;
using namespace std;

Ruch::Ruch(Pionek* pionek, Pole* od, Pole* na)
{
    m_Pionek = pionek;
    m_pozycjaStartowa = od;
    m_pozycjaDocelowa = na;
    m_zbityPionek = 0;
    m_wykonany = false;
}

void Ruch::renderuj()
{
    cout << m_Pionek->jakiGracz()->jakaNazwa() << ' przeniósł z ' << m_pozycjaStartowa->nazwa() << ' na ' << m_pozycjaDocelowa->nazwa() << endl;
    if(m_zbityPionek != 0)
    {
        cout << 'Pionek ' << m_zbityPionek->nazwa() << ' został zbity.' << endl;
    }
}

void Ruch::wykonaj()
{
    if
    Pionek* pionek = m_pozycjaDocelowa->jakiPionek();
    if(pionek != 0)
    {
        m_zbityPionek = pionek;
    }
    m_pozycjaDocelowa = pionek;
}

void Ruch::cofnij()
{

}

Ruch::~Ruch()
{
    //dtor
}
