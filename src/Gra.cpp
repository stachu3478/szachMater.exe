#include "Gra.h"

#include <string>
#include "Plansza.h"
#include "TypPionka.h"
#include "Gracz.h"
#include "HistoriaRuchow.h"

#include <iostream>

using namespace Szachy;
using namespace std;

char toChar(std::string str)
{
    char c[str.size() + 1];
    str.copy(c, str.size() + 1);
    c[str.size()] = '\0';
    return *c;
}

Gra::Gra(TypPionka* typyPionkow):
    m_Plansza(8),
    m_Gracz1(typyPionkow, &m_Plansza, true),
    m_Gracz2(typyPionkow, &m_Plansza, false),
    m_HistoriaRuchow()
{
    cout << "konstruktor gra" << endl;
    // m_TypyPionkow = TypPionka::generuj();
}

void Gra::rozpocznij()
{
    while(1)
    {
        // Rysowanie planszy - start
        int zhakowanyRozmiar = 64;
        char dane[zhakowanyRozmiar];
        char kolory[zhakowanyRozmiar];
        for (int i = 0; i < 64; i++)
        {
            dane[i] = '_';
            kolory[i] = 6 + (i % 2) >> 1;
        }
        for (int i = 0; i < 16; i++)
        {
            Pionek* pionek = m_Gracz1.pobierzPionek(i);
            if (pionek->czyZbity())
            {
                Pole* pole = pionek->jakaPozycja();// m_Gracz1.pobierzPionek(i).jakaPozycja();
                char numer = pole->pobierzNumer();

                dane[numer] = toChar(pionek->jakaLitera());
                kolory[numer] = 240;
            }
        }
        for (int i = 0; i < 16; i++)
        {
            Pionek* pionek = m_Gracz2.pobierzPionek(i);
            if (pionek->czyZbity())
            {
                Pole* pole = pionek->jakaPozycja();// m_Gracz1.pobierzPionek(i).jakaPozycja();
                char numer = pole->pobierzNumer();

                dane[numer] = toChar(pionek->jakaLitera());
                kolory[numer] = 15;
            }
        }
        m_Plansza.rysuj(dane, kolory);
        // Rysowanie planszy - end


    }
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
