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
            Ruch(Pionek* pionek, Pole* od, Pole* na, Pionek* zbity);
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
