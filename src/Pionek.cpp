#include <iostream>
#include "Pionek.h"
#include "TypPionka.h"
#include "Pole.h"
#include "Array.h"

using namespace std;
using namespace Szachy;

Pionek::Pionek(TypPionka* typ, Pole* pozycja)
{
    m_zbity = false;
    // m_gracz = gracz;
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

Array<Pole> Pionek::mozliwosciRuchu()
{
    int** przesuniecia = m_typ->mozliwosciRuchu();
    int x = m_pozycja->poziom();
    int y = m_pozycja->pion();
    Array<Pole> pola();
    int licznik = 0;
    for (int i = 0; i < 4; i++)
    {
        int px = x + przesuniecia[i][0];
        int py = y + przesuniecia[i][1];
        if (
            px > 0
            && px <= 8
            && py > 0
            && py <= 8
        )
        {
            pola.push(new Pole(px, py));
        }
    }
    return pola;
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
