#ifndef GRA_H
#define GRA_H

#include "Gracz.h"
#include "Plansza.h"
#include "TypPionka.h"
#include "HistoriaRuchow.h"

class Gra
{
    public:
        Gra();
        virtual ~Gra();

        unsigned int GetStatus() { return m_Status; }
        void SetStatus(unsigned int val) { m_Status = val; }
        unsigned int GetLicznikCzasu() { return m_LicznikCzasu; }
        void SetLicznikCzasu(unsigned int val) { m_LicznikCzasu = val; }
        Gracz GetGracz1() { return m_Gracz1; }
        void SetGracz1(Gracz val) { m_Gracz1 = val; }
        Gracz GetGracz2() { return m_Gracz2; }
        void SetGracz2(Gracz val) { m_Gracz2 = val; }
        Plansza GetPlansza() { return m_Plansza; }
        void resetuj();

    protected:

    private:
        unsigned int m_Status;
        unsigned int m_LicznikCzasu;
        Gracz m_Gracz1;
        Gracz m_Gracz2;
        Plansza m_Plansza;
        TypPionka m_TypyPionkow[];
        static TypPionka utworzTypyPionkow();
        HistoriaRuchow m_HistoriaRuchow;
};

#endif // GRA_H
