#ifndef PIONEK_H
#define PIONEK_H

#include "Kolor.h"
#include "TypPionka.h"
#include "Pole.h"
#include "Array.h"

namespace Szachy
{
    class Pionek
    {
        public:
            Pionek(TypPionka* typ, Pole* pozycja, Kolor* kolor);
            virtual ~Pionek();

            TypPionka jakiTyp() { return *m_typ; }
            Pole* jakaPozycja() { return m_pozycja; }
            Array<Pole>& mozliwosciRuchu();
            std::string jakaLitera() { return m_typ->jakaLitera(); }
            std::string nazwa() { return m_typ->jakaNazwa(); };
            void przenies(Szachy::Pole* val);
            Kolor* JakiKolor(){ return m_Kolor; }
            bool czyBylPierwszyruch() { return m_bylPierwszyRuch; }
            bool czyZbity() { return m_zbity; }
            void zbij() { m_zbity = true; }
            void info();

        protected:

        private:
            Szachy::TypPionka* m_typ;
            Szachy::Pole* m_pozycja;
            Kolor* m_Kolor;
            bool m_bylPierwszyRuch;
            bool m_zbity;
    };
}

#endif // PIONEK_H
