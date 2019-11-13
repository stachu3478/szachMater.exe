#include "HistoriaRuchow.h"

#include "Ruch.h"
#include <iostream>
#include <fstream>

using namespace Szachy;
using namespace std;

Ruch* HistoriaRuchow::przygotujListe()
{
    Ruch* lista[100];
    return *lista;
}

HistoriaRuchow::HistoriaRuchow()
{
    m_Lista = przygotujListe();
    m_Licznik = 0;
    m_Pozycja = 0;
}

void HistoriaRuchow::zapisz(const char* plik)
{
    ofstream dest(plik);
    dest.close();
    // TODO zapisac dane binarnie
}

Ruch* HistoriaRuchow::zaladuj(const char* plik)
{
    ifstream source(plik);
    source.close();
    return przygotujListe();
    // TODO zaladowac dane binarne
}

HistoriaRuchow::HistoriaRuchow(const char* plik)
{
    m_Lista = zaladuj(plik);
    m_Licznik = 0;
    m_Pozycja = 0;
    // TODO ładowanie pliku
}

HistoriaRuchow& HistoriaRuchow::operator+=(const Ruch& ruch)
{
    m_Lista[m_Licznik++] = ruch;
    return *this;
}

HistoriaRuchow::~HistoriaRuchow()
{
    //dtor
}
