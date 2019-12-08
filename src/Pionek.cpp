#include <iostream>
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

Pole*& Pionek::mozliwoscRuchu(Array<Pole>* pola, int x, int y)
{
    Pole pole(m_pozycja);
    if (pole.przesun(x, y)) pola->push(pole);
}

Array<Pole>& Pionek::mozliwosciRuchu(char kierunek)
{
    Array< Array<char> >* przesuniecia = m_typ->mozliwosciRuchu();
    int x = m_pozycja->poziom();
    int y = m_pozycja->pion();
    Array<Pole> pola(4);
    int licznik = 0;
    for (int i = 0; i < przesuniecia->len(); i++)
    {
        przesuniecia->printItems();
        mozliwoscRuchu(&pola, (*przesuniecia)[i][0] * kierunek, (*przesuniecia)[i][1] * kierunek);
    }
    Array<Pole>& polaRef = pola;
    return polaRef;
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

Pionek::~Pionek()
{
    //dtor
}
