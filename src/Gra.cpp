#include "Gra.h"

#include "Gracz.h"
#include "Plansza.h"
#include "TypPionka.h"
#include "HistoriaRuchow.h"

TypPionka Gra::utworzTypyPionkow()
{
    TypPionka typy[6];

    typy[0] = new TypPionka("Pion", "Najbardziej pospolity pionek", "O");
    typy[1] = new TypPionka("Skoczek", "Pionek potrafi¹cy przeskakikaæ inne pionki", "S");
    typy[2] = new TypPionka("Goniec", "Pionek bij¹cy na ukos", "G");
    typy[3] = new TypPionka("Wie¿a", "Pionek bij¹cy w kolumnach i rzêdach", "W");
    typy[4] = new TypPionka("Hetman", "Wa¿ny pionek, posiada najwiêcej mo¿liwoœci ruchu", "H");
    typy[5] = new TypPionka("Król", "Najwa¿niejszy pionek, nie mo¿e zostaæ zbity", "K");

    return typy
}

Gra::Gra()
{
    m_Gracz1 = new Gracz();
    m_Gracz2 = new Gracz();
    m_Plansza = new Plansza(8);
    m_HistoriaRuchow = new HistoriaRuchow();
    m_TypyPionkow = utworzTypyPionkow();
}

Gra::~Gra()
{
    //dtor
}
