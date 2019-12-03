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
    m_szach = 0;
    generujPionki(typyPionkow, plansza);
    cout << "Podaj nazwę gracza. Kolor pionków: " << m_KolorPionkow.JakaNazwa() << endl;
    cin >> m_nazwa;
    cout << endl;
}

Gracz::Gracz():
    m_KolorPionkow()
{
    m_szach = 0;
}

bool poleBezpieczne(Pole* pole, Kolor* kolor, Plansza* plansza)
{
    // TODO pole bezpieczne dla króla
}

Pole*& dup(Pole* pole)
{
    Pole* poleDup = pole;
    Pole*& poleDupRef = poleDup;
    return poleDupRef;
}

/// Sprawdza czy pionek ma wolną drogę
bool sprawdzCzyPoleWolne(Pole*& pole, int x, int y, Plansza* plansza)
{
    // return
        cout << plansza->pobierzPolePrzes(pole, x, y) << endl
        << (plansza->pobierzPionek(pole) == 0) << endl;
        return false;
}

/// Sprawdza czy pionek moze przejsc na pole lub zbic przeciwnika
bool sprawdzCzyMozePrzejsc(Pionek* pionek, Pole*& pole, int x, int y, Plansza* plansza)
{
    if (!plansza->pobierzPolePrzes(pole, x, y)) return false;
    Pionek* pionekCel = plansza->pobierzPionek(pole);
    return
        pionekCel == 0
        || pionekCel->JakiKolor() != pionek->JakiKolor();
}

bool sprawdzCzyMozeBic(Pionek* pionek, Pole*& pole, int x, int y, Plansza* plansza)
{
    if (!plansza->pobierzPolePrzes(pole, x, y)) return false;
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
        Pole* potPole = dup(pole);
        if (sprawdzCzyMozePrzejsc(pionek, potPole, x += xd, y += yd, plansza))
            pola->push(potPole);
    } while(sprawdzCzyPoleWolne(dup(pole), x, y, plansza));
}

Array<Pole>& mozliwePolaPionka(Pionek* pionek, Plansza* plansza)
{
    char k = pionek->JakiKolor()->JakaWartosc() != 0 ? -1 : 1; // kierunek
    // char k = m_KolorPionkow.JakaWartosc() != 0 ? -1 : 1; // kierunek
    Array<Pole>* pola = new Array<Pole>(10);
    string litera = pionek->jakaLitera();
    Pole* pole = pionek->jakaPozycja();
    switch ((int)*litera.c_str())
    {
        case 'O':
        {
            // Prosto
            Pole* potPole1 = dup(pole);
            if (
                !pionek->czyBylPierwszyruch()
                && sprawdzCzyPoleWolne(potPole1, 2 * k, 0, plansza)
            )
                pola->push(potPole1);
            Pole* potPole2 = dup(pole);
            if (sprawdzCzyPoleWolne(potPole2, 1 * k, 0, plansza))
                pola->push(potPole2);

            // Bicie na ukos
            Pole* potPole3 = dup(pole);
            if (sprawdzCzyMozeBic(pionek, potPole3, 1 * k, -1, plansza))
                pola->push(potPole3);
            Pole* potPole4 = dup(pole);
            if (sprawdzCzyMozeBic(pionek, potPole4, 1 * k, 1, plansza))
                pola->push(potPole4);
        }; break;
        case 'S':
        {
            for (int m = -2; m <= 2; m++)
            {
                if (m == 0) continue;
                int j = abs(m) == 1 ? 2 : 1;
                Pole* potPole1 = dup(pole);
                if (sprawdzCzyMozePrzejsc(pionek, potPole1, m, j, plansza))
                    pola->push(potPole1);
                Pole* potPole2 = dup(pole);
                if (sprawdzCzyMozePrzejsc(pionek, potPole2, m, -j, plansza))
                    pola->push(potPole2);
            }
        }; break;
        case 'G':
        {
            przeszukajPola(pionek, pola, 1, 1, plansza);
            przeszukajPola(pionek, pola, 1, -1, plansza);
            przeszukajPola(pionek, pola, -1, 1, plansza);
            przeszukajPola(pionek, pola, -1, -1, plansza);
        }; break;
        case 'W':
        {
            przeszukajPola(pionek, pola, 1, 0, plansza);
            przeszukajPola(pionek, pola, -1, 0, plansza);
            przeszukajPola(pionek, pola, 0, 1, plansza);
            przeszukajPola(pionek, pola, 0, -1, plansza);
        }; break;
        case 'H':
        {
            przeszukajPola(pionek, pola, 1, 0, plansza);
            przeszukajPola(pionek, pola, -1, 0, plansza);
            przeszukajPola(pionek, pola, 0, 1, plansza);
            przeszukajPola(pionek, pola, 0, -1, plansza);
            przeszukajPola(pionek, pola, 1, 1, plansza);
            przeszukajPola(pionek, pola, 1, -1, plansza);
            przeszukajPola(pionek, pola, -1, 1, plansza);
            przeszukajPola(pionek, pola, -1, -1, plansza);
        }; break;
        case 'K':
        {
            for (int j = -1; j <= 1;j ++)
                for (int k = -1; k <= 1; k++)
            {
                Pole* potPole = dup(pole);
                if (sprawdzCzyMozePrzejsc(pionek, potPole, j, k, plansza ))
                    pola->push(potPole);
            };
        }
    };
    pola->printItems();
    Array<Pole>& polaRef = *pola;
    return polaRef;
}

Array<Ruch*>& mozliwosciPionka(Pionek* pionek, Plansza* plansza)
{
    Array<Pole> pola = mozliwePolaPionka(pionek, plansza);
    Array<Ruch*>* ruchy = new Array<Ruch*>(pola.len());
    for (int j = 0; j < pola.len(); j++)
    {
        ruchy->push(new Ruch(*&pionek, pionek->jakaPozycja(), &pola[j]));
    }
    Array<Ruch*>& ruchyRef = *ruchy;
    return ruchyRef;
}

Array< Array<Ruch*> >& Gracz::mozliwosciRuchu(Plansza* plansza)
{
    Array< Array<Ruch*> > ruchyPionkow;
    for (int i = 0; i < 16; i++)
    {
        Pionek* pionek = m_pionki[i];
        //if (m_szach && pionek->jakaLitera() != "K") continue;
        if (!pionek->czyZbity())
        {
            Array<Ruch*> ruchy = mozliwosciPionka(pionek, plansza);
            if (ruchy.len() > 0) ruchyPionkow.push(ruchy);
        }
    }
    Array< Array<Ruch*> >& ruchyPionkowRef = ruchyPionkow;
    m_szach = 0;
    return ruchyPionkowRef;
}

// TODO
bool Gracz::czySzach(Pionek* pionek, Plansza* plansza)
{
    Array<Pole> pola = mozliwePolaPionka(pionek, plansza);
    for (int i = 0; i < pola.len(); i++)
    {
        Pionek* potKrol = plansza->pobierzPionek(&pola[i]);
        if (
            potKrol != 0
            && potKrol->jakaLitera() == "K"
        )
        {
            cout << m_nazwa << ": Szach!" << endl;
            return true;
        }
    }
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
