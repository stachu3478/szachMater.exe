#include "Gra.h"

#include <string>
#include <stdio.h>

#include "Array.h"
#include "Kolor.h"
#include "Plansza.h"
#include "TypPionka.h"
#include "Gracz.h"
#include "toChar.h"

// sleep_for
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <thread>
#include <chrono>

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace Szachy;
using namespace std;

void Gra::generujTypyPionkow()
{
    m_TypyPionkow.push(new TypPionka("Pion", "Najbardziej pospolity pionek", 'O'));
    m_TypyPionkow.push(new TypPionka("Skoczek", "Pionek potrafiący feskakikaæ inne pionki", 'S'));
    m_TypyPionkow.push(new TypPionka("Goniec", "Pionek bij¹cy na ukos", 'G'));
    m_TypyPionkow.push(new TypPionka("Wie¿a", "Pionek bij¹cy w kolumnach i rzêdach", 'W'));
    m_TypyPionkow.push(new TypPionka("Hetman", "Wa¿ny pionek, posiada najwiêcej mo¿liwoœci ruchu", 'H'));
    m_TypyPionkow.push(new TypPionka("Król", "Najwa¿niejszy pionek, nie mo¿e zostaæ zbity", 'K'));
}

Gra::Gra(bool kontynnuj):
    m_Plansza(8),
    m_TypyPionkow(6)
{
    m_Kolejka = 0;
    generujTypyPionkow();
    m_szach = false;
    m_koniec = false;
    m_Gracz1 = *(new Gracz(m_TypyPionkow, &m_Plansza, 0, kontynnuj));
    m_Gracz2 = *(new Gracz(m_TypyPionkow, &m_Plansza, 7, kontynnuj));
    if (kontynnuj) zaladuj();
}

void Gra::rozpocznij(bool demo)
{
    cout
        << "Zaczyna gracz "
        << m_Gracz1.jakaNazwa()
        << ". Kolor pionków: "
        << m_Gracz1.JakiKolor().JakaNazwa()
        << endl;
    m_demo = demo;
    while (!m_koniec)
    {
        if (m_Kolejka)
            kolejka(m_Gracz1, m_Gracz2);
        else
            kolejka(m_Gracz2, m_Gracz1);
        m_Kolejka = !m_Kolejka;
        cout << m_Kolejka << endl;
    }
    remove("savegame.txt");
}

bool Gra::kolejka(Gracz gracz, Gracz przeciwnik)
{
    cout << "Kolej gracza " << gracz.jakaNazwa() << endl;
    m_Plansza.rysuj();
    // Wybór ruchu - start
    if (m_szach > 1) m_szach = 0;
    Array< Array<Ruch*> > mozliweRuchy = gracz.mozliwosciRuchu(m_szach);

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
    Array<Ruch*> ruchyPionka = m_demo ? mozliweRuchy.random() : mozliweRuchy.read();

    cout << "Wybierz pole, aby poruszyć pionkiem. Dostepne: " << ruchyPionka.len() << " ruchów." << endl;
    for (int i = 0; i < ruchyPionka.len(); i++)
    {
        Ruch* ruch = ruchyPionka[i];
        cout << (i + 1) << ". " << ruch->jakiCel()->nazwa() << setw(8);
    }
    cout << endl;

    Ruch* ruch = m_demo ? ruchyPionka.random() : ruchyPionka.read();
    Pionek* pionek = ruch->jakiPionek();
    Pole* cel = ruch->jakiCel();
    m_Plansza.przeniesPionek(pionek, cel);
    if (
        pionek->jakaLitera() == "O"
        && cel->poziom() == (gracz.kierunek() == 1 ? 8 : 1)
    ) pionek->awansuj(m_TypyPionkow[4]); // Damka
    if (gracz.czySzach(pionek)) m_szach = true;
    else m_szach = false;

    if (!m_demo) zapisz();
    else this_thread::sleep_for(chrono::seconds(1));
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
    out << m_szach << endl;
    out << m_koniec << endl;
    out << !m_Kolejka << endl;
    m_Gracz1.zapisz(out);
    m_Gracz2.zapisz(out);
    out.flush();
    out.close();
}

void Gra::zaladuj()
{
    ifstream in("savegame.txt");
    in >> m_szach;
    in >> m_koniec;
    in >> m_Kolejka;
    m_Gracz1.zaladuj(in);
    m_Gracz2.zaladuj(in);
    in.close();
}

Gra::~Gra()
{}
