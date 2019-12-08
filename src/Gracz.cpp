#include "Gracz.h"

#include <iostream>
#include <cmath>

#include "TypPionka.h"
#include "Pionek.h"
#include "Plansza.h"
#include "Ruch.h"
#include "Array.h"
#include "Kolor.h"
#include "toChar.h"

using namespace Szachy;
using namespace std;

void Gracz::generujPionki(Array<TypPionka*> typyPionkow, Plansza* plansza)
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
}

void Gracz::przydzielPionki()
{
    for (int i = 0; i < 16; i++)
    {
        m_Plansza->przydzielPionek(m_pionki[i]);
    }
}

Gracz::Gracz(Array<TypPionka*> typyPionkow, Plansza* plansza, unsigned char kolor, bool kontynnuj):
    m_KolorPionkow(kolor == 0 ? "Czarny" : "Biały", kolor)
{
    m_Plansza = plansza;
    generujPionki(typyPionkow, plansza);
    if (!kontynnuj)
    {
        przydzielPionki();
        cout << "Podaj nazwę gracza. Kolor pionków: " << m_KolorPionkow.JakaNazwa() << endl;
        cin >> m_nazwa;
        cout << endl;
    }
}

Gracz::Gracz():
    m_KolorPionkow()
{}


Pole*& dup(Pole* pole)
{
    Pole* poleDup = pole;
    Pole*& poleDupRef = poleDup;
    return poleDupRef;
}

bool sprawdzPole(Pole* pole, Plansza* plansza, char* litery, int l, Kolor* kolor)
{
    if (pole == 0) return false;
    Pionek* pionek;
    string litera;
    if (
        (pionek = plansza->pobierzPionek(pole))
        && pionek->JakiKolor() != kolor
    )
    {
        litera = pionek->jakaLitera();
        for (int i = 0; i < l; i++)
        {
            string ls = "";
            ls += litery[i];
            if (litera == ls) return true;
        }
    }
    return false;
}

bool sprawdzPrzesuniecie(Pole* pole, int x, int y, Plansza* plansza, char* litery, int l, Kolor* kolor)
{
    Pole* dupPole = dup(pole);
    return
        plansza->pobierzPolePrzes(dupPole, x, y)
        && sprawdzPole(dupPole, plansza, litery, l, kolor);
}

/// Sprawdza czy pionek ma wolną drogę
bool sprawdzCzyPoleWolne(Pole*& pole, int x, int y, Plansza* plansza)
{
    return
        plansza->pobierzPolePrzes(pole, x, y)// << endl
        && (plansza->pobierzPionek(pole) == 0);// << endl;
}

Pole* znajdzZajetePole(Pole* pole, int xd, int yd, Plansza* plansza)
{
    Pole* dupPole = dup(pole);
    do
    {} while(sprawdzCzyPoleWolne(dupPole, xd, yd, plansza));
    if (dupPole == pole) return NULL;
    return dupPole;
}

int kierunek(Kolor* kolor) { return kolor->JakaWartosc() != 0 ? -1 : 1; }

bool poleBezpieczne(Pole* pole, Kolor* kolor, Plansza* plansza)
{
    Array<Pole>* pola = new Array<Pole>(10);
    int ptr = 0;

    int k = kierunek(kolor);

    Pionek* pionek;
    char litera;
    char wkh[3] = {'W', 'K', 'H'};
    char gkh[3] = {'G', 'K', 'H'};
    char pgkh[4] = {'O', 'G', 'K', 'H'};
    char wh[2] = {'W', 'H'};
    char gh[2] = {'G', 'H'};
    char s[1] = {'S'};
    if (
        sprawdzPrzesuniecie(pole, 0, 1, plansza, wkh, 3, kolor)
        || sprawdzPrzesuniecie(pole, 0, -1, plansza, wkh, 3, kolor)
        || sprawdzPrzesuniecie(pole, 1, 0, plansza, wkh, 3, kolor)
        || sprawdzPrzesuniecie(pole, -1, 0, plansza, wkh, 3, kolor)
        || sprawdzPole(znajdzZajetePole(pole, 0, 1, plansza), plansza, wh, 2, kolor)
        || sprawdzPole(znajdzZajetePole(pole, 0, -1, plansza), plansza, wh, 2, kolor)
        || sprawdzPole(znajdzZajetePole(pole, 1, 0, plansza), plansza, wh, 2, kolor)
        || sprawdzPole(znajdzZajetePole(pole, -1, 0, plansza), plansza, wh, 2, kolor)
        || sprawdzPrzesuniecie(pole, k, 1, plansza, pgkh, 4, kolor)
        || sprawdzPrzesuniecie(pole, k, -1, plansza, pgkh, 4, kolor)
        || sprawdzPrzesuniecie(pole, -k, 1, plansza, gkh, 3, kolor)
        || sprawdzPrzesuniecie(pole, -k, -1, plansza, gkh, 3, kolor)
        || sprawdzPole(znajdzZajetePole(pole, 1, 1, plansza), plansza, gh, 2, kolor)
        || sprawdzPole(znajdzZajetePole(pole, 1, -1, plansza), plansza, gh, 2, kolor)
        || sprawdzPole(znajdzZajetePole(pole, -1, 1, plansza), plansza, gh, 2, kolor)
        || sprawdzPole(znajdzZajetePole(pole, -1, -1, plansza), plansza, gh, 2, kolor)

        || sprawdzPrzesuniecie(pole, 2, 1, plansza, s, 1, kolor)
        || sprawdzPrzesuniecie(pole, -2, 1, plansza, s, 1, kolor)
        || sprawdzPrzesuniecie(pole, 2, -1, plansza, s, 1, kolor)
        || sprawdzPrzesuniecie(pole, -2, -1, plansza, s, 1, kolor)
        || sprawdzPrzesuniecie(pole, 1, 2, plansza, s, 1, kolor)
        || sprawdzPrzesuniecie(pole, -1, 2, plansza, s, 1, kolor)
        || sprawdzPrzesuniecie(pole, 1, -2, plansza, s, 1, kolor)
        || sprawdzPrzesuniecie(pole, -1, -2, plansza, s, 1, kolor)
    ) return false;
    return true;
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

void przeszukajPolaPionka(Pionek* pionek, Array<Pole>* pola, int xd, int yd, Plansza* plansza)
{
    Pole* pole = pionek->jakaPozycja();
    int x = 0, y = 0;
    Pole* dupPole = dup(pole);
    do
    {
        Pole* potPole = dup(pole);
        if (sprawdzCzyMozePrzejsc(pionek, potPole, x += xd, y += yd, plansza))
            pola->push(potPole);
        dupPole = dup(pole);
    } while(sprawdzCzyPoleWolne(dupPole, x, y, plansza));
}

Array<Pole>& mozliwePolaPionka(Pionek* pionek, Plansza* plansza)
{
    Kolor* kolor = pionek->JakiKolor();
    int k = kierunek(kolor); // kierunek
    Array<Pole>* pola = new Array<Pole>(10);
    string litera = pionek->jakaLitera();
    Pole* pole = pionek->jakaPozycja();
    switch ((int)*litera.c_str())
    {
        case 'O':
        {
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
        case 'W':
        {
            przeszukajPolaPionka(pionek, pola, 1, 0, plansza);
            przeszukajPolaPionka(pionek, pola, -1, 0, plansza);
            przeszukajPolaPionka(pionek, pola, 0, 1, plansza);
            przeszukajPolaPionka(pionek, pola, 0, -1, plansza);
        }; break;
        case 'H':
        {
            przeszukajPolaPionka(pionek, pola, 1, 0, plansza);
            przeszukajPolaPionka(pionek, pola, -1, 0, plansza);
            przeszukajPolaPionka(pionek, pola, 0, 1, plansza);
            przeszukajPolaPionka(pionek, pola, 0, -1, plansza);
        };
        case 'G':
        {
            przeszukajPolaPionka(pionek, pola, 1, 1, plansza);
            przeszukajPolaPionka(pionek, pola, 1, -1, plansza);
            przeszukajPolaPionka(pionek, pola, -1, 1, plansza);
            przeszukajPolaPionka(pionek, pola, -1, -1, plansza);
        }; break;
        case 'K':
        {
            for (int j = -1; j <= 1;j ++)
                for (int l = -1; l <= 1; l++)
            {
                if (l == 0 && j == 0) continue;
                Pole* potPole = dup(pole);
                if (
                    sprawdzCzyMozePrzejsc(pionek, potPole, j, l, plansza)
                    && poleBezpieczne(potPole, kolor, plansza)
                ) pola->push(potPole);
            };
        }
    };
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

Array< Array<Ruch*> >& Gracz::mozliwosciRuchu(Plansza* plansza, bool szach)
{
    Array< Array<Ruch*> > ruchyPionkow;
    for (int i = 0; i < 16; i++)
    {
        Pionek* pionek = m_pionki[i];
        // TODO ruchy pionków zbijających dodać
        if (szach && pionek->jakaLitera() != "K") continue;
        if (!pionek->czyZbity())
        {
            Array<Ruch*> ruchy = mozliwosciPionka(pionek, plansza);
            if (ruchy.len() > 0) ruchyPionkow.push(ruchy);
        }
    }
    Array< Array<Ruch*> >& ruchyPionkowRef = ruchyPionkow;
    return ruchyPionkowRef;
}

bool Gracz::czySzach(Pionek* pionek, Plansza* plansza)
{
    Array<Pole> pola = mozliwePolaPionka(pionek, plansza);
    for (int i = 0; i < pola.len(); i++)
    {
        Pionek* potKrol = plansza->pobierzPionek(&pola[i]);
        if (
            potKrol == 0
            || potKrol->jakaLitera() != "K"
        ) continue;
        cout << m_nazwa << ": Szach!" << endl;
        return true;
    }
    return false;
}

void Gracz::zapisz(ofstream& out)
{
    out << m_nazwa << endl;
    for (int i = 0; i < 16; i++)
    {
        out << (int)m_pionki[i]->jakaPozycja()->pobierzNumer() << endl;
        m_pionki[i]->zapisz(out);
    };
}

void Gracz::zaladuj(ifstream& in)
{
    in >> m_nazwa;
    int pozycja;
    for (int i = 0; i < 16; i++)
    {
        in >> pozycja;
        m_Plansza->przeniesPionek(m_pionki[i], m_Plansza->pobierzPole(pozycja));
        m_pionki[i]->zaladuj(in);
    };
}

Gracz::~Gracz()
{
    //dtor
}
