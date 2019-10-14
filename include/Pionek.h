#ifndef PIONEK_H
#define PIONEK_H

#include "TypPionka.h"
#include "Pole.h"
#include "Gracz.h"

namespace Szachy
{
    class Pionek
    {
        public:
            Pionek(const TypPionka& typ, const Pole& pozycja, const Gracz& gracz);
            virtual ~Pionek();

            TypPionka jakiTyp() { return m_typ; }
            Pole jakaPozycja() { return m_pozycja; }
            void przenies(Pole val) { m_pozycja = val; }
            Gracz jakiGracz() { return m_gracz; }
            bool czyZbity() { return m_zbity; }
            void zbij() { m_zbity = true; }

        protected:

        private:
            TypPionka m_typ;
            Pole m_pozycja;
            Gracz m_gracz;
            bool m_zbity;
    };
}

#endif // PIONEK_H
