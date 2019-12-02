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
    // cout << "Nowy pionek ma pole nr " << (int)pozycja->pobierzNumer() << endl;
    cout << "Nowy pionek ma literke " << typ->jakaLitera() << endl;
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
    cout << "Przesuniecia koniec " << endl;
    int x = m_pozycja->poziom();
    int y = m_pozycja->pion();
    cout << "x i y pionka " << endl;
    Array<Pole> pola(4);
    cout << "Deklaracja pĂłl" << przesuniecia->len() << endl;
    int licznik = 0;
    for (int i = 0; i < przesuniecia->len(); i++)
    {
        przesuniecia->printItems();
        mozliwoscRuchu(&pola, (*przesuniecia)[i][0] * kierunek, (*przesuniecia)[i][1] * kierunek);
    }
    cout << "pionek mozliwosci koniec" << endl;
    Array<Pole>& polaRef = pola;
    return polaRef;
}

// FIXME
// void Pionek::info()
// {
//    cout << "Pionek gracza " << m_gracz->jakaNazwa() << endl;
//    m_typ->info();
//}

Pionek::~Pionek()
{
    //dtor
}
