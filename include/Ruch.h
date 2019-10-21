#ifndef RUCH_H
#define RUCH_H

#include "Pionek.h"
#include "Pole.h"
#include "TypPionka.h"

namespace Szachy
{
    class Ruch
    {
        public:
            Ruch(Pionek* pionek, Pole* od, Pole* na);
            virtual ~Ruch();
            void renderuj();
            void wykonaj();
            void cofnij();

        protected:

        private:
            Pionek* m_Pionek;
            Pole* m_PozycjaStartowa;
            Pole* m_PozycjaDocelowa;
            TypPionka* m_zbityPionek;
    };
}

#endif // RUCH_H
