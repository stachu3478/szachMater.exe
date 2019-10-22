#include "HistoriaRuchow.h"

#include "Ruch.h"
#include <iostream>
#include <fstream>

using namespace Szachy;
using namespace std;

HistoriaRuchow::HistoriaRuchow()
{
    m_Lista = new Ruch[100];
    m_Licznik = 0;
    m_Pozycja = 0;
}

void HistoriaRuchow::zapisz(std::string plik)
{
    ofstream dest(plik);

}

Ruch[] HistoriaRuchow::zaladuj(std::string plik)
{
    ifstream source(plik);
    source.width
}

HistoriaRuchow::HistoriaRuchow(std::string plik)
{
    // TODO ładowanie pliku
}

HistoriaRuchow& HistoriaRuchow::operator+=(const Ruch& ruch)
{
    m_Lista[m_Licznik++] = ruch;
}

HistoriaRuchow::~HistoriaRuchow()
{
    //dtor
}
