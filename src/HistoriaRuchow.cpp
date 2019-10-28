#include "HistoriaRuchow.h"

#include "Ruch.h"
#include <iostream>
#include <fstream>

using namespace Szachy;
using namespace std;

HistoriaRuchow::HistoriaRuchow()
{
    Ruch listaRuchow[100];
    m_Lista = listaRuchow;
    m_Licznik = 0;
    m_Pozycja = 0;
}

void HistoriaRuchow::zapisz(std::string plik)
{
    ofstream dest(plik);
    // TODO zapisac dane binarnie
}

Ruch[] HistoriaRuchow::zaladuj(std::string plik)
{
    ifstream source(plik);
    // TODO zaladowac dane binarne
}

HistoriaRuchow::HistoriaRuchow(std::string plik)
{
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
