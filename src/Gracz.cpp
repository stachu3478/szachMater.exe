#include "Gracz.h"

#include <string>
#include "TypPionka.h"
#include "Pionek.h"
#include "Plansza.h"

using namespace Szachy;
using namespace std;

Gracz::Gracz(TypPionka* typyPionkow, Plansza* plansza, bool czarne)
{
    m_pionki = *generujPionki(typyPionkow);
    m_jestCzarny = czarne;
    cout << "Podaj nazwê gracza: ";
    cin >> m_nazwa;
    cout << endl;
}

Gracz::Gracz(std::string nazwa)
{
    m_nazwa = nazwa;
}

Pionek* Gracz::generujPionki(TypPionka* typyPionkow, Plansza* plansza)
{
    Pionek pionki[16];
    int poziom = m_jestCzarny ? 2 : 7;
    for(unsigned int pion = 1; i <= 8; i++) // generowanie pionow
    {
        pionki[pion - 1] = new Pionek(typyPionkow[0], plansza->pobierzPole(poziom, pion), this);
    }

    poziom = m_jestCzarny ? 1 : 8;
    int inc = m_jestCzarny ? 1 : -1;
    int pion = m_jestCzarny ? 1 : 8;
    pionki[8] = new Pionek(typyPionkow[3], plansza->pobierzPole(poziom, pion += inc), this); // wieza
    pionki[9] = new Pionek(typyPionkow[1], plansza->pobierzPole(poziom, pion += inc), this); // skoczek
    pionki[10] = new Pionek(typyPionkow[2], plansza->pobierzPole(poziom, pion += inc), this); // goniec
    pionki[11] = new Pionek(typyPionkow[4], plansza->pobierzPole(poziom, pion += inc), this); // hetman
    pionki[12] = new Pionek(typyPionkow[5], plansza->pobierzPole(poziom, pion += inc), this); // krol
    pionki[13] = new Pionek(typyPionkow[2], plansza->pobierzPole(poziom, pion += inc), this); // goniec
    pionki[14] = new Pionek(typyPionkow[1], plansza->pobierzPole(poziom, pion += inc), this); // skoczek
    pionki[15] = new Pionek(typyPionkow[3], plansza->pobierzPole(poziom, pion += inc), this); // wieza

    return pionki;
}

Gracz::~Gracz()
{
    //dtor
}
