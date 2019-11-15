#include "Gracz.h"

#include <iostream>
#include "TypPionka.h"
#include "Pionek.h"
#include "Plansza.h"

using namespace Szachy;
using namespace std;

void Gracz::generujPionki(TypPionka** typyPionkow, Plansza* plansza)
{
    int poziom = m_jestCzarny ? 2 : 7;
    for(unsigned int pion = 1; pion <= 8; pion++) // generowanie pionow
    {
        m_pionki[pion - 1] = new Pionek(typyPionkow[0], plansza->pobierzPole(poziom, pion));
    }

    poziom = m_jestCzarny ? 1 : 8;
    int inc = m_jestCzarny ? 1 : -1;
    int pion = m_jestCzarny ? 1 : 8;
    m_pionki[8] = new Pionek(typyPionkow[3], plansza->pobierzPole(poziom, pion)); // wieza
    m_pionki[9] = new Pionek(typyPionkow[1], plansza->pobierzPole(poziom, pion += inc)); // skoczek
    m_pionki[10] = new Pionek(typyPionkow[2], plansza->pobierzPole(poziom, pion += inc)); // goniec
    m_pionki[11] = new Pionek(typyPionkow[4], plansza->pobierzPole(poziom, pion += inc)); // hetman
    m_pionki[12] = new Pionek(typyPionkow[5], plansza->pobierzPole(poziom, pion += inc)); // krol
    m_pionki[13] = new Pionek(typyPionkow[2], plansza->pobierzPole(poziom, pion += inc)); // goniec
    m_pionki[14] = new Pionek(typyPionkow[1], plansza->pobierzPole(poziom, pion += inc)); // skoczek
    m_pionki[15] = new Pionek(typyPionkow[3], plansza->pobierzPole(poziom, pion += inc)); // wieza
}

Gracz::Gracz(TypPionka** typyPionkow, Plansza* plansza, bool czarne)
{
    cout << "Inicjalizacja gracza" << endl;
    m_jestCzarny = czarne;
    generujPionki(typyPionkow, plansza);
    cout << "Podaj nazwę gracza: ";
    cin >> m_nazwa;
    cout << endl;
}

Gracz::Gracz()
{}

Array<Array<Pole>> mozliwosciRuchu()
{
    Array<Array<Pole>> ruchyPionkow();
    for (int i = 0; i < 16; i++)
    {
        if (!m_pionki.czyZbity())
        {
            ruchyPionkow.push(m_pionki[i].mozliwosciRuchu())
        }
    }
    return ruchyPionkow;
}

// TODO
bool Gracz::czySzach()
{
    // operuj na m_pionki[12]
    return false;
}

// TODO
bool Gracz::czyPrzegral()
{
    // operuj na m_pionki[12]
    return false;
}

Gracz::~Gracz()
{
    //dtor
}
