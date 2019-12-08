#ifndef GRA_H
#define GRA_H

#include "Gracz.h"
#include "Plansza.h"
#include "TypPionka.h"

char toChar(std::string a);

namespace Szachy
{
    class Gra
    {
        public:
            Gra(bool kontynnuj);
            virtual ~Gra();

            void generujTypyPionkow();
            void rozpocznij();
            void zakoncz(Gracz zwyciesca);
            bool kolejka(Gracz gracz, Gracz przeciwnik);

            void zapisz();
            void zaladuj();

        protected:

        private:
            unsigned int m_Status;
            unsigned int m_LicznikCzasu;
            Szachy::Plansza m_Plansza;
            Szachy::Gracz m_Gracz1;
            Szachy::Gracz m_Gracz2;
            Szachy::TypPionka* m_TypyPionkow[5];
            bool m_szach;
            bool m_koniec;
    };
}

#endif // GRA_H
