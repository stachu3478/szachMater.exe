#ifndef RUCH_H
#define RUCH_H

#include "Pole.h"
#include "TypPionka.h"
#include "Pionek.h"

namespace Szachy
{
    class Ruch
    {
        public:
            Ruch();
            Ruch(Pionek* pionek, Pole* od, Pole* na);
            Pionek* jakiPionek(){ return m_Pionek; };
            Pole* jakiCel(){ return m_PozycjaDocelowa; };
            virtual ~Ruch();
            void renderuj();
            void wykonaj();
            void cofnij();

        protected:

        private:
            Pionek* m_Pionek;
            Pole* m_PozycjaStartowa;
            Pole* m_PozycjaDocelowa;
            Pionek* m_ZbityPionek;
            bool m_Wykonany;
    };
}

#endif // RUCH_H
