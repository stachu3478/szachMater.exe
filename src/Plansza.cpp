#include "Plansza.h"

#include "Pole.h"
#include "TypPionka.h"

Plansza::Plansza(unsigned int rozmiar = 8)
{
    m_Pola = Pole::generuj(rozmiar, rozmiar);
}

void Plansza::rysuj()
{

}

void Plansza::zresetuj(TypPionka* typyPionkow)
{

}

Plansza::~Plansza()
{
    //dtor
}
