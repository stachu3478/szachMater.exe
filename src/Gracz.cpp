#include "Gracz.h"

#include <iostream>

#include "TypPionka.h"
#include "Pionek.h"
#include "Plansza.h"
#include "Ruch.h"
#include "Array.h"
#include "Kolor.h"

using namespace Szachy;
using namespace std;

void Gracz::generujPionki(TypPionka** typyPionkow, Plansza* plansza)
{
    bool jestCzarny = m_KolorPionkow.JakaWartosc() == 0;
    int poziom = jestCzarny ? 2 : 7;
    for(unsigned int pion = 1; pion <= 8; pion++) // generowanie pionow
    {
        m_pionki[pion - 1] = new Pionek(typyPionkow[0], plansza->pobierzPole(poziom, pion), &m_KolorPionkow);
    }

    poziom = jestCzarny ? 1 : 8;
    int inc = jestCzarny ? 1 : -1;
    int pion = jestCzarny ? 1 : 8;
    m_pionki[8] = new Pionek(typyPionkow[3], plansza->pobierzPole(poziom, pion), &m_KolorPionkow); // wieza
    m_pionki[9] = new Pionek(typyPionkow[1], plansza->pobierzPole(poziom, pion += inc), &m_KolorPionkow); // skoczek
    m_pionki[10] = new Pionek(typyPionkow[2], plansza->pobierzPole(poziom, pion += inc), &m_KolorPionkow); // goniec
    m_pionki[11] = new Pionek(typyPionkow[4], plansza->pobierzPole(poziom, pion += inc), &m_KolorPionkow); // hetman
    m_pionki[12] = new Pionek(typyPionkow[5], plansza->pobierzPole(poziom, pion += inc), &m_KolorPionkow); // krol
    m_pionki[13] = new Pionek(typyPionkow[2], plansza->pobierzPole(poziom, pion += inc), &m_KolorPionkow); // goniec
    m_pionki[14] = new Pionek(typyPionkow[1], plansza->pobierzPole(poziom, pion += inc), &m_KolorPionkow); // skoczek
    m_pionki[15] = new Pionek(typyPionkow[3], plansza->pobierzPole(poziom, pion += inc), &m_KolorPionkow); // wieza

    for (int i = 0; i < 16; i++)
    {
        plansza->przydzielPionek(m_pionki[i]);
    }
}

Gracz::Gracz(TypPionka** typyPionkow, Plansza* plansza, unsigned char kolor):
    m_KolorPionkow(kolor == 0 ? "Czarny" : "Biały", kolor)
{
    cout << "Inicjalizacja gracza" << endl;
    generujPionki(typyPionkow, plansza);
    cout << "Podaj nazwę gracza: ";
    cin >> m_nazwa;
    cout << endl;
}

Gracz::Gracz():
    m_KolorPionkow()
{}

Array< Array<Ruch*> >& Gracz::mozliwosciRuchu(Plansza* plansza)
{
    Array< Array<Ruch*> > ruchyPionkow;
    for (int i = 0; i < 16; i++)
    {
        if (!m_pionki[i]->czyZbity())
        {
            char k = m_KolorPionkow.JakaWartosc() != 0 ? -1 : 1; // kierunek
            Array<Pole> pola(10);// = m_pionki[i]->mozliwosciRuchu(kierunek);
            Pionek* pionek = m_pionki[i];
            cout << "xffxdxdxd" << pola.len() << endl;
            string litera = pionek->jakaLitera();
            switch ((int)*litera.c_str())
            {
                case 'O':
                {
                    // Prosto
                    Pole* pole = pionek->jakaPozycja();
                    Pole potPole1(pole);
                    if (
                        !pionek->czyBylPierwszyruch()
                        && potPole1.przesun(2 * k, 0)
                        && plansza->pobierzPionek(&potPole1) == 0
                    )
                        pola.push(potPole1);
                    Pole potPole2(pole);
                    if (potPole2.przesun(1 * k, 0) && plansza->pobierzPionek(&potPole2) == 0)
                        pola.push(potPole2);

                    // Bicie na ukos
                    Pole potPole3(pole);
                    if (potPole3.przesun(1 * k, 1) && plansza->pobierzPionek(&potPole3) != 0)
                        pola.push(potPole3);
                    Pole potPole4(pole);
                    if (potPole4.przesun(1 * k, 1) && plansza->pobierzPionek(&potPole4) != 0)
                        pola.push(potPole4);
                }; break;
            }
            cout << "A teraz inicjalizacja kolejnej arrejki" << endl;
            Array<Ruch*> ruchy(pola.len());
            cout << "Wow udalo nam sie! To teraz dodamy mozliwy ruch do listy" << pola.len() << endl;
            // Pole* pozycja = m_pionki[i]->jakaPozycja();
            for (int j = 0; j < pola.len(); j++)
            { // TODO sprawdzanie czy pole jest zajęte
                cout << "Dodawanie ruchu pionka " << endl;
                ruchy.push(new Ruch(*&m_pionki[i], m_pionki[i]->jakaPozycja(), &pola[j]));
            }
            cout << "Koniec????" << endl;
            if (ruchy.len() > 0) ruchyPionkow.push(ruchy);
        }
    }
    Array< Array<Ruch*> >& ruchyPionkowRef = ruchyPionkow;
    cout << "Tera Koniec????" << endl;
    return ruchyPionkowRef;
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
