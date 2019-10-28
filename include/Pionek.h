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
            Pionek(TypPionka* typ, Pole* pozycja);
            virtual ~Pionek();

            TypPionka jakiTyp() { return *m_typ; }
            Pole* jakaPozycja() { return m_pozycja; }
            Pole* mozliwosciRuchu();
            std::string jakaLitera() { return m_typ->jakaLitera(); }
            void przenies(Szachy::Pole* val);
            // FIXME
            // Szachy::Gracz jakiGracz() { return *m_gracz; }
            bool czyBylPierwszyruch() { return m_bylPierwszyRuch; }
            bool czyZbity() { return m_zbity; }
            void zbij() { m_zbity = true; }
            void info();

        protected:

        private:
            Szachy::TypPionka* m_typ;
            Szachy::Pole* m_pozycja;
            // FIXME
            // Szachy::Gracz* m_gracz;
            bool m_bylPierwszyRuch;
            bool m_zbity;
    };
}

#endif // PIONEK_H
