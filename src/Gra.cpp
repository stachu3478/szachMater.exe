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
    // cout << "to char" << str << endl;
    return *c;
}

void Gra::generujTypyPionkow()
{
    cout << "Tworzenie typów pionków" << endl;
    m_TypyPionkow[0] = new TypPionka("Pion", "Najbardziej pospolity pionek", 'O');
    m_TypyPionkow[1] = new TypPionka("Skoczek", "Pionek potrafiący przeskakikaæ inne pionki", 'S');
    m_TypyPionkow[2] = new TypPionka("Goniec", "Pionek bij¹cy na ukos", 'G');
    m_TypyPionkow[3] = new TypPionka("Wie¿a", "Pionek bij¹cy w kolumnach i rzêdach", 'W');
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
    m_Gracz1 = *(new Gracz(m_TypyPionkow, &m_Plansza, true));
    m_Gracz2 = *(new Gracz(m_TypyPionkow, &m_Plansza, false));
}

void Gra::rozpocznij()
{
    //while(1)
    //{
        // Rysowanie planszy - start
        int zhakowanyRozmiar = 64;
        char dane[zhakowanyRozmiar];
        char kolory[zhakowanyRozmiar];
        for (int i = 0; i < 64; i++)
        {
            dane[i] = ' ';
            kolory[i] = 16 * (4 + (((i / 8 + i % 8) % 2) << 1));
        }
        cout << "Początkowe dane planszy przygotowane" << endl;
        for (int i = 0; i < 16; i++)
        {
            Pionek* pionek = m_Gracz1.pobierzPionek(i);
            if (!pionek->czyZbity())
            {
                Pole* pole = pionek->jakaPozycja();// m_Gracz1.pobierzPionek(i).jakaPozycja();
                int numer = (int)pole->pobierzNumer();

                cout << "Wpis do planszy " << numer << endl;
                string litera = pionek->jakaLitera();
                cout << "Literka " << litera << endl;
                dane[numer] = toChar(litera);
                kolory[numer] += 0;
            }
        }
        for (int i = 0; i < 16; i++)
        {
            Pionek* pionek = m_Gracz2.pobierzPionek(i);
            if (!pionek->czyZbity())
            {
                Pole* pole = pionek->jakaPozycja();// m_Gracz1.pobierzPionek(i).jakaPozycja();
                char numer = pole->pobierzNumer();

                dane[numer] = toChar(pionek->jakaLitera());
                kolory[numer] += 7;
            }
        }
        cout << "Dane pionków wpisane do planszy" << endl;
        m_Plansza.rysuj(dane, kolory);
        // Rysowanie planszy - end


    //}
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
