#include "Gra.h"

#include "Gracz.h"
#include "Plansza.h"
#include "TypPionka.h"
#include "HistoriaRuchow.h"

Gra::Gra()
{
    m_TypyPionkow = TypPionka::generuj();
    m_Plansza = new Plansza(8);
    m_Gracz1 = new Gracz(&m_TypyPionkow, &m_Plansza, true);
    m_Gracz2 = new Gracz(&m_TypyPionkow, &m_Plansza, false);
    m_HistoriaRuchow = new HistoriaRuchow();
}

void Gra::resetuj()
{
    delete m_Plansza;
    m_HistoriaRuchow.zapisz(m_Gracz1.jakaNazwa() + ' vs ' + m_Gracz2.jakaNazwa())
}

Gra::~Gra()
{
    //dtor
}
