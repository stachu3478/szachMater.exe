#include <iostream>
#include <fstream>
#include "Pionek.h"
#include "TypPionka.h"
#include "Pole.h"
#include "Array.h"

using namespace std;
using namespace Szachy;

Pionek::Pionek(TypPionka* typ, Pole* pozycja, Kolor* kolor)
{
    m_zbity = false;
    m_Kolor = kolor;
    m_typ = typ;
    m_pozycja = pozycja;
}

void Pionek::przenies(Pole* pole)
{
    m_pozycja = pole;
    m_bylPierwszyRuch = true;
}

void Pionek::zbij()
{
    if (jakaLitera() == "K")
    {
        cout << "Nie można zbić króla!!!" << endl;
        throw *this;
    };
    m_zbity = true;
}

void Pionek::zapisz(ofstream& out)
{
    out << (m_bylPierwszyRuch ? 1 : 0) << endl;
    out << (m_zbity ? 1 : 0) << endl;
}

void Pionek::zaladuj(ifstream& in)
{
    in >> m_bylPierwszyRuch;
    in >> m_zbity;
}

Pionek::~Pionek()
{
    //dtor
}
