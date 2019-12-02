#include "Gracz.h"

#include <iostream>
#include <cmath>

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

/// Sprawdza czy pionek ma wolną drogę
bool sprawdzCzyPoleWolne(Pole* pole, int x, int y, Plansza* plansza)
{
    return
        pole->przesun(x, y)
        && plansza->pobierzPionek(pole) == 0;
}

/// Sprawdza czy pionek moze przejsc na pole lub zbic przeciwnika
bool sprawdzCzyMozePrzejsc(Pionek* pionek, Pole* pole, int x, int y, Plansza* plansza)
{
    if (!pole->przesun(x, y)) return false;
    Pionek* pionekCel = plansza->pobierzPionek(pole);
    return
        pionekCel == 0
        || pionekCel->JakiKolor() != pionek->JakiKolor();
}

bool sprawdzCzyMozeBic(Pionek* pionek, Pole* pole, int x, int y, Plansza* plansza)
{
    if (!pole->przesun(x, y)) return false;
    Pionek* pionekCel = plansza->pobierzPionek(pole);
    return
        pionekCel != 0
        && pionekCel->JakiKolor() != pionek->JakiKolor();
}

void przeszukajPola(Pionek* pionek, Array<Pole>* pola, int xd, int yd, Plansza* plansza)
{
    int x = 0, y = 0;
    Pole* pole = pionek->jakaPozycja();
    do
    {
        Pole potPole(pole);
        Pole& pref = potPole;
        if (sprawdzCzyMozePrzejsc(pionek, &potPole, x += xd, y += yd, plansza))
            pola->push(pref);
    } while(sprawdzCzyPoleWolne(new Pole(pole), x, y, plansza));
}

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
            string litera = pionek->jakaLitera();
            Pole* pole = pionek->jakaPozycja();
            switch ((int)*litera.c_str())
            {
                case 'O':
                {
                    // Prosto
                    Pole potPole1(pole);
                    if (
                        !pionek->czyBylPierwszyruch()
                        && sprawdzCzyPoleWolne(&potPole1, 2 * k, 0, plansza)
                    )
                        pola.push(potPole1);
                    Pole potPole2(pole);
                    if (sprawdzCzyPoleWolne(&potPole2, 1 * k, 0, plansza))
                        pola.push(potPole2);

                    // Bicie na ukos
                    Pole potPole3(pole);
                    if (sprawdzCzyMozeBic(pionek, &potPole3, 1 * k, -1, plansza))
                        pola.push(potPole3);
                    Pole potPole4(pole);
                    if (sprawdzCzyMozeBic(pionek, &potPole4, 1 * k, 1, plansza))
                        pola.push(potPole4);
                }; break;
                case 'S': // FIXME duplicate moves
                {
                    for (int m = -2; m <= 2; m++)
                    {
                        if (m == 0) continue;
                        int j = abs(m) == 1 ? 2 : 1;
                        Pole potPole1(pole);
                        if (sprawdzCzyMozePrzejsc(pionek, &potPole1, m, j, plansza))
                            pola.push(potPole1);
                        Pole potPole2(pole);
                        if (sprawdzCzyMozePrzejsc(pionek, &potPole2, m, -j, plansza))
                            pola.push(potPole1);
                    }
                }; break;
                case 'G':
                {
                    przeszukajPola(pionek, &pola, 1, 1, plansza);
                    przeszukajPola(pionek, &pola, 1, -1, plansza);
                    przeszukajPola(pionek, &pola, -1, 1, plansza);
                    przeszukajPola(pionek, &pola, -1, -1, plansza);
                }; break;
                case 'W':
                {
                    przeszukajPola(pionek, &pola, 1, 0, plansza);
                    przeszukajPola(pionek, &pola, -1, 0, plansza);
                    przeszukajPola(pionek, &pola, 0, 1, plansza);
                    przeszukajPola(pionek, &pola, 0, -1, plansza);
                }; break;
                case 'H':
                {
                    przeszukajPola(pionek, &pola, 1, 0, plansza);
                    przeszukajPola(pionek, &pola, -1, 0, plansza);
                    przeszukajPola(pionek, &pola, 0, 1, plansza);
                    przeszukajPola(pionek, &pola, 0, -1, plansza);
                    przeszukajPola(pionek, &pola, 1, 1, plansza);
                    przeszukajPola(pionek, &pola, 1, -1, plansza);
                    przeszukajPola(pionek, &pola, -1, 1, plansza);
                    przeszukajPola(pionek, &pola, -1, -1, plansza);
                }
            }
            // cout << "A teraz inicjalizacja kolejnej arrejki" << endl;
            Array<Ruch*> ruchy(pola.len());
            // cout << "Wow udalo nam sie! To teraz dodamy mozliwy ruch do listy" << pola.len() << endl;
            // Pole* pozycja = m_pionki[i]->jakaPozycja();
            for (int j = 0; j < pola.len(); j++)
            { // TODO sprawdzanie czy pole jest zajęte
                // cout << "Dodawanie ruchu pionka " << endl;
                ruchy.push(new Ruch(*&m_pionki[i], m_pionki[i]->jakaPozycja(), &pola[j]));
            }
            // cout << "Koniec????" << endl;
            if (ruchy.len() > 0) ruchyPionkow.push(ruchy);
        }
    }
    Array< Array<Ruch*> >& ruchyPionkowRef = ruchyPionkow;
    // cout << "Tera Koniec????" << endl;
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
