#include <iostream>
#include "Pionek.h"
#include "TypPionka.h"
#include "Pole.h"

using namespace std;
using namespace Szachy;

Pionek::Pionek(TypPionka* typ, const Pole& pozycja, Gracz* gracz):
    m_pozycja(pozycja)
{
    m_zbity = false;
    m_gracz = gracz;
    m_typ = typ;
}

void Pionek::przenies(Pole pole)
{
    m_pozycja = pole;
    m_bylPierwszyRuch = true;
}

void Pionek::info()
{
    cout << "Pionek gracza " << m_gracz->jakaNazwa() << endl;
    m_typ->info();
}

Pionek::~Pionek()
{
    //dtor
}
