#include "Gra.h"

#include "Plansza.h"
#include "TypPionka.h"
#include "Gracz.h"
#include "HistoriaRuchow.h"

using namespace Szachy;

Gra::Gra():
    m_Plansza(8),
    m_Gracz1(m_TypyPionkow, &m_Plansza, true),
    m_Gracz2(m_TypyPionkow, &m_Plansza, false),
    m_HistoriaRuchow()
{
    m_TypyPionkow = TypPionka::generuj();
}

void Gra::resetuj()
{
    // FIXME
    // delete m_Plansza;
    m_HistoriaRuchow.zapisz(m_Gracz1.jakaNazwa() + " vs " + m_Gracz2.jakaNazwa());
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
