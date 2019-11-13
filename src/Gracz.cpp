#include "Gracz.h"

#include <iostream>
#include "TypPionka.h"
#include "Pionek.h"
#include "Plansza.h"

using namespace Szachy;
using namespace std;

Pionek* Gracz::generujPionki(TypPionka* typyPionkow, Plansza* plansza, bool czarne)
{
    Pionek* pionki[16];
    int poziom = czarne ? 2 : 7;
    for(unsigned int pion = 1; pion <= 8; pion++) // generowanie pionow
    {
        pionki[pion - 1] = new Pionek(&typyPionkow[0], plansza->pobierzPole(poziom, pion));
    }

    poziom = czarne ? 1 : 8;
    int inc = czarne ? 1 : -1;
    int pion = czarne ? 1 : 8;
    pionki[8] = new Pionek(&typyPionkow[3], plansza->pobierzPole(poziom, pion += inc)); // wieza
    pionki[9] = new Pionek(&typyPionkow[1], plansza->pobierzPole(poziom, pion += inc)); // skoczek
    pionki[10] = new Pionek(&typyPionkow[2], plansza->pobierzPole(poziom, pion += inc)); // goniec
    pionki[11] = new Pionek(&typyPionkow[4], plansza->pobierzPole(poziom, pion += inc)); // hetman
    pionki[12] = new Pionek(&typyPionkow[5], plansza->pobierzPole(poziom, pion += inc)); // krol
    pionki[13] = new Pionek(&typyPionkow[2], plansza->pobierzPole(poziom, pion += inc)); // goniec
    pionki[14] = new Pionek(&typyPionkow[1], plansza->pobierzPole(poziom, pion += inc)); // skoczek
    pionki[15] = new Pionek(&typyPionkow[3], plansza->pobierzPole(poziom, pion += inc)); // wieza

    return *pionki;
}

Gracz::Gracz(TypPionka* typyPionkow, Plansza* plansza, bool czarne)
{
    m_pionki = generujPionki(typyPionkow, plansza, czarne);
    m_jestCzarny = czarne;
    cout << "Podaj nazwę gracza: ";
    cin >> m_nazwa;
    cout << endl;
}

Gracz::Gracz(std::string nazwa)
{
    m_nazwa = nazwa;
}

Gracz::~Gracz()
{
    //dtor
}
