#include "Plansza.h"

#include "Pole.h"
#include "TypPionka.h"

using namespace Szachy;

Plansza::Plansza(unsigned int rozmiar)
{
    zresetuj(rozmiar);
}

Plansza::Plansza()
{
    zresetuj(8);
}

void Plansza::rysuj()
{

}

void Plansza::zresetuj(unsigned int rozmiar)
{
    delete m_Pola;
    m_Pola = Pole::generuj(rozmiar, rozmiar);
}

Pole* Plansza::pobierzPole(unsigned int poziom, unsigned int pion)
{
    return &m_Pola[poziom * 8 + pion - 1];
}

Plansza::~Plansza()
{
    //dtor
}
