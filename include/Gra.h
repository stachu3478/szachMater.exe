#ifndef GRA_H
#define GRA_H

#include "Gracz.h"
#include "Plansza.h"
#include "TypPionka.h"
#include "HistoriaRuchow.h"

namespace Szachy
{
    class Gra
    {
        public:
            Gra();
            virtual ~Gra();

            unsigned int GetStatus() { return m_Status; }
            void SetStatus(unsigned int val) { m_Status = val; }
            unsigned int GetLicznikCzasu() { return m_LicznikCzasu; }
            void SetLicznikCzasu(unsigned int val) { m_LicznikCzasu = val; }
            Szachy::Gracz GetGracz1() { return m_Gracz1; }
            void SetGracz1(Szachy::Gracz val) { m_Gracz1 = val; }
            Szachy::Gracz GetGracz2() { return m_Gracz2; }
            void SetGracz2(Szachy::Gracz val) { m_Gracz2 = val; }
            Szachy::Plansza GetPlansza() { return m_Plansza; }
            void resetuj();

        protected:

        private:
            unsigned int m_Status;
            unsigned int m_LicznikCzasu;
            Szachy::Gracz m_Gracz1;
            Szachy::Gracz m_Gracz2;
            Szachy::Plansza m_Plansza;
            Szachy::TypPionka m_TypyPionkow[];
            Szachy::HistoriaRuchow m_HistoriaRuchow;
    };
}

#endif // GRA_H
