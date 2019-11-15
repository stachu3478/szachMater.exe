#ifndef GRACZ_H
#define GRACZ_H

#include <string>
#include "Ruch.h"
#include "Pionek.h"
#include "TypPionka.h"
#include "Plansza.h"

namespace Szachy
{
    class Gracz
    {
        public:
            Gracz(TypPionka* typyPionkow, Plansza* plansza, bool czarne);
            virtual ~Gracz();
            void generujPionki(TypPionka* typyPionkow, Plansza* plansza);
            std::string jakaNazwa() { return m_nazwa; };
            bool czyCzarny() { return m_jestCzarny; };
            bool czySzach();
            bool czyPrzegral();
            Pionek* pobierzPionek(int n) { return m_pionki[n]; };
            Ruch* mozliwosciRuchu();
        protected:

        private:
            std::string m_nazwa;
            Szachy::Pionek* m_pionki[16];
            bool m_jestCzarny;
    };
}

#endif // GRACZ_H
