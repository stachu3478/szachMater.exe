#include "Gra.h"

#include <string>

#include "Array.h"
#include "Kolor.h"
#include "Plansza.h"
#include "TypPionka.h"
#include "Gracz.h"
#include "HistoriaRuchow.h"

#include <iostream>
#include <iomanip>

using namespace Szachy;
using namespace std;

char toChar(std::string str)
{
    char c[str.size() + 1];
    str.copy(c, str.size() + 1);
    c[str.size()] = '\0';
    // cout << "to char" << str << endl;
    return *c;
}

void Gra::generujTypyPionkow()
{
    cout << "Tworzenie typów pionków" << endl;
    Array<char*> ruchyPionu(10);
    ruchyPionu.push(new char[2]{2, 1});
    m_TypyPionkow[0] = new TypPionka("Pion", "Najbardziej pospolity pionek", 'O');
    m_TypyPionkow[0]->dodajRuch(1, 0);
    m_TypyPionkow[0]->dodajRuch(2, 0);
    m_TypyPionkow[0]->dodajRuch(1, 1);
    m_TypyPionkow[0]->dodajRuch(1, -1);
    m_TypyPionkow[1] = new TypPionka("Skoczek", "Pionek potrafiący przeskakikaæ inne pionki", 'S');
    m_TypyPionkow[1]->dodajRuch(2, -1);
    m_TypyPionkow[1]->dodajRuch(2, 1);
    m_TypyPionkow[1]->dodajRuch(-2, -1);
    m_TypyPionkow[1]->dodajRuch(-2, 1);
    m_TypyPionkow[1]->dodajRuch(1, -2);
    m_TypyPionkow[1]->dodajRuch(1, 2);
    m_TypyPionkow[1]->dodajRuch(-1, -2);
    m_TypyPionkow[1]->dodajRuch(-1, 2);
    m_TypyPionkow[2] = new TypPionka("Goniec", "Pionek bij¹cy na ukos", 'G');
    for (int i = -7; i <= 7; i++)
    {
        m_TypyPionkow[2]->dodajRuch(i, i);
        m_TypyPionkow[2]->dodajRuch(i, -i);
    }
    m_TypyPionkow[3] = new TypPionka("Wie¿a", "Pionek bij¹cy w kolumnach i rzêdach", 'W');
    for (int i = -7; i <= 7; i++)
    {
        m_TypyPionkow[3]->dodajRuch(i, 0);
        m_TypyPionkow[3]->dodajRuch(0, i);
    }
    m_TypyPionkow[4] = new TypPionka("Hetman", "Wa¿ny pionek, posiada najwiêcej mo¿liwoœci ruchu", 'H');
    m_TypyPionkow[5] = new TypPionka("Król", "Najwa¿niejszy pionek, nie mo¿e zostaæ zbity", 'K');
    cout << "Utworzono typy pionków" << endl;
}

/// Typy pionków muszą być w argumencie aby zainicjalizować gracza z pionkami
Gra::Gra():
    m_Plansza(8),
    //m_Gracz1,
    //m_Gracz2,
    m_HistoriaRuchow()
{
    cout << "konstruktor gra" << endl;
    generujTypyPionkow();
    m_Gracz1 = *(new Gracz(m_TypyPionkow, &m_Plansza, 0));
    m_Gracz2 = *(new Gracz(m_TypyPionkow, &m_Plansza, 7));
}

void Gra::rozpocznij()
{
    cout
        << "Zaczyna gracz "
        << m_Gracz1.jakaNazwa()
        << ". Kolor pionków: "
        << m_Gracz1.JakiKolor().JakaNazwa()
        << endl;
    while(1)
    {
        kolejka(m_Gracz1);
        kolejka(m_Gracz2);
    }
}

void Gra::kolejka(Gracz gracz)
{
    cout << "Kolej gracza " << gracz.jakaNazwa() << endl;
    m_Plansza.rysuj();
    // Wybór ruchu - start
    unsigned int idRuchu;
    unsigned int idPola;
    Array< Array<Ruch*> > mozliweRuchy = gracz.mozliwosciRuchu(&m_Plansza);
    cout << "Wybierz pionek, aby poruszyć. Dostepne: " << mozliweRuchy.len() << " pionków." << endl;
    for (int i = 0; i < mozliweRuchy.len(); i++)
    {
        Ruch* ruch = mozliweRuchy[i][0];
        Pionek* pionek = ruch->jakiPionek();
        cout << (i + 1) << ". " << pionek->jakaPozycja()->nazwa() << " " << pionek->nazwa() << setw(10);
    }
    cout << endl;

    Array<Ruch*> ruchyPionka = mozliweRuchy.read();
    cout << "Wybierz pole, aby poruszyć pionkiem. Dostepne: " << ruchyPionka.len() << " ruchów." << endl;
    for (int i = 0; i < ruchyPionka.len(); i++)
    {
        Ruch* ruch = ruchyPionka[i];
        cout << (i + 1) << ". " << ruch->jakiCel()->nazwa() << setw(8);
    }
    cout << endl;

    Ruch* ruch = ruchyPionka.read();
    m_Plansza.przeniesPionek(ruch->jakiPionek(), ruch->jakiCel());
    // Wybór ruchu - koniec
}

void Gra::resetuj()
{
    // FIXME
    // delete m_Plansza;
    string str = m_Gracz1.jakaNazwa() + " vs " + m_Gracz2.jakaNazwa();
    char c = toChar(str);
    m_HistoriaRuchow.zapisz(&c);
}

Gra::~Gra()
{
    delete m_TypyPionkow;
    // FIXME
    // delete m_Plansza;
    // delete m_Gracz1;
    // delete m_Gracz2;
    // delete m_HistoriaRuchow;
}
