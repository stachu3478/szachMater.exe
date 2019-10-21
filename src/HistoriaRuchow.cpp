#include "HistoriaRuchow.h"

#include "Ruch.h"
#include <iostream>

using namespace Szachy;

HistoriaRuchow::HistoriaRuchow()
{
    m_Lista = new Ruch[100];
    m_Licznik = 0;
    m_Pozycja = 0;
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
