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
    m_LiczbaRuchow = 0;
}

void Pionek::przenies(Pole* pole)
{
    m_pozycja = pole;
    m_LiczbaRuchow++;
}

void Pionek::zbij()
{
    if (jakaLitera() == "K")
    {
        cout << "Nie można zbić króla!!!" << endl;
        throw *this;
    };
    m_zbity = 1;
}

void Pionek::zapisz(ofstream& out)
{
    out << m_LiczbaRuchow << endl;
    out << m_zbity << endl;
}

// Przy ładowawniu potrzeba znou ustawić pionek który zwiększa liczbę ruchów
void Pionek::zaladuj(ifstream& in)
{
    in >> m_LiczbaRuchow;
    in >> m_zbity;
    m_LiczbaRuchow--;
}

Pionek::~Pionek()
{
    //dtor
}
