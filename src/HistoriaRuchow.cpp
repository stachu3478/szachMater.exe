#include "HistoriaRuchow.h"

#include "Pole.h"
#include "Ruch.h"
#include "Array.h"
#include <iostream>
#include <fstream>

using namespace Szachy;
using namespace std;

HistoriaRuchow::HistoriaRuchow():
    Array<Ruch*> m_Lista(20)
{}

void HistoriaRuchow::zapisz(const char* plik)
{
    ofstream dest(plik);
    dest << m_Lista.len() << endl;
    for (int i = 0; i < m_Lista.len(); i++)
    {
        Ruch* ruch = m_Lista[i];
        dest << char(ruch->m_PozycjaStartowa->pobierzNumer());
        dest << char(ruch->m_PozycjaDocelowa->pobierzNumer());
    }
    dest.close();
}

Ruch* HistoriaRuchow::zaladuj(const char* plik)
{
    ifstream source(plik);
    int length;
    source >> length;
    for (int i = 0; i < length; i++)
    {
        char start, cel;
        source >> start;
        source >> cel;
        Pole* pole = new Pole(start)
        m_Lista.push(new Ruch()))
    }
    source.close();
    return przygotujListe();
}

HistoriaRuchow::HistoriaRuchow(const char* plik)
    Array<Ruch*> m_Lista(20)
{
    m_Lista = zaladuj(plik);
}

HistoriaRuchow::~HistoriaRuchow()
{
    //dtor
}
