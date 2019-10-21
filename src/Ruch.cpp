#include "Ruch.h"

#include "Pionek.h"
#include "Pole.h"
#include "TypPionka.h"

using namespace Szachy;

Ruch::Ruch(Pionek* pionek, Pole* od, Pole* na)
{
    m_Pionek = pionek;
    m_pozycjaStartowa = od;
    m_pozycjaDocelowa = na;
}

void Ruch::renderuj()
{
    m_Pionek->jakiGracz()
}

void Ruch::wykonaj()
{

}

void Ruch::cofnij()
{

}

Ruch::~Ruch()
{
    //dtor
}
