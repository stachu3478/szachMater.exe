#include <iostream>
#include "Pionek.h"
#include "TypPionka.h"
#include "Pole.h"

using namespace std;
using namespace Szachy;

Pionek::Pionek(const TypPionka& typ, const Pole& pozycja, const Gracz& gracz):
    m_typ(typ),
    m_pozycja(pozycja),
    m_gracz(gracz)
{
    m_zbity = false;
    cout << "Jestem pionkiem gracza " << endl << m_gracz.nazwa << endl;
    m_typ.info();
}

Pionek::~Pionek()
{
    //dtor
}
