#include "Gra.h"

#include <string>

#include "Array.h"
#include "Kolor.h"
#include "Plansza.h"
#include "TypPionka.h"
#include "Gracz.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace Szachy;
using namespace std;

char toChar(std::string str)
{
    char c[str.size() + 1];
    str.copy(c, str.size() + 1);
    c[str.size()] = '\0';
    return *c;
}

void Gra::generujTypyPionkow()
{
    m_TypyPionkow[0] = new TypPionka("Pion", "Najbardziej pospolity pionek", 'O');
    m_TypyPionkow[1] = new TypPionka("Skoczek", "Pionek potrafiący przeskakikaæ inne pionki", 'S');
    m_TypyPionkow[2] = new TypPionka("Goniec", "Pionek bij¹cy na ukos", 'G');
    m_TypyPionkow[3] = new TypPionka("Wie¿a", "Pionek bij¹cy w kolumnach i rzêdach", 'W');
    m_TypyPionkow[4] = new TypPionka("Hetman", "Wa¿ny pionek, posiada najwiêcej mo¿liwoœci ruchu", 'H');
    m_TypyPionkow[5] = new TypPionka("Król", "Najwa¿niejszy pionek, nie mo¿e zostaæ zbity", 'K');
}

Gra::Gra(bool kontynnuj):
    m_Plansza(8)
{
    if (kontynnuj) zaladuj();
    else
    {
        m_szach = false;
        m_koniec = false;
        generujTypyPionkow();
        m_Gracz1 = *(new Gracz(m_TypyPionkow, &m_Plansza, 0));
        m_Gracz2 = *(new Gracz(m_TypyPionkow, &m_Plansza, 7));
    }
}

void Gra::rozpocznij()
{
    cout
        << "Zaczyna gracz "
        << m_Gracz1.jakaNazwa()
        << ". Kolor pionków: "
        << m_Gracz1.JakiKolor().JakaNazwa()
        << endl;
    while (!kolejka(m_Gracz1, m_Gracz2))
        if (kolejka(m_Gracz2, m_Gracz1)) break;
}

bool Gra::kolejka(Gracz gracz, Gracz przeciwnik)
{
    cout << "Kolej gracza " << gracz.jakaNazwa() << endl;
    m_Plansza.rysuj();
    // Wybór ruchu - start
    unsigned int idRuchu;
    unsigned int idPola;
    if (m_szach > 1) m_szach = 0;
    Array< Array<Ruch*> > mozliweRuchy = gracz.mozliwosciRuchu(&m_Plansza, m_szach);
    cout << "Wybierz pionek, aby poruszyć. Dostepne: " << mozliweRuchy.len() << " pionków." << endl;
    for (int i = 0; i < mozliweRuchy.len(); i++)
    {
        Ruch* ruch = mozliweRuchy[i][0];
        Pionek* pionek = ruch->jakiPionek();
        cout << (i + 1) << ". " << pionek->jakaPozycja()->nazwa() << " " << pionek->nazwa() << setw(10);
    }
    cout << endl;
    if (mozliweRuchy.len() == 0)
    {
        zakoncz(przeciwnik);
        return true;
    }
    Array<Ruch*> ruchyPionka = mozliweRuchy.read();
    cout << "Wybierz pole, aby poruszyć pionkiem. Dostepne: " << ruchyPionka.len() << " ruchów." << endl;
    for (int i = 0; i < ruchyPionka.len(); i++)
    {
        Ruch* ruch = ruchyPionka[i];
        cout << (i + 1) << ". " << ruch->jakiCel()->nazwa() << setw(8);
    }
    cout << endl;

    Ruch* ruch = ruchyPionka.read();
    Pionek* pionek = ruch->jakiPionek();
    Pole* cel = ruch->jakiCel();
    m_Plansza.przeniesPionek(pionek, cel);
    if (
        pionek->jakaLitera() == "O"
        && cel->poziom() == (gracz.kierunek() == 1 ? 8 : 1)
    ) pionek->awansuj(m_TypyPionkow[4]); // Damka
    if (gracz.czySzach(pionek, &m_Plansza)) m_szach = true;
    else m_szach = false;

    zapisz();
    return false;
}

void Gra::zakoncz(Gracz zwyciesca)
{
    m_koniec = true;
    cout << "Szach mat! Wygrywa gracz " << zwyciesca.jakaNazwa() << endl;
}

void Gra::zapisz()
{
    ofstream out("savegame.txt");
    out << m_szach << m_koniec;
    // TODO implement children
    out.close();
}

void Gra::zaladuj()
{
    ifstream in("savegame.txt");
    in >> m_szach >> m_koniec;
    // TODO implement children
    in.close();
}

Gra::~Gra()
{
    delete m_TypyPionkow;
}
