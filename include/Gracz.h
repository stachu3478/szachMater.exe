#ifndef GRACZ_H
#define GRACZ_H

#include <string>
#include "Pionek.h"
#include "TypPionka.h"
#include "Plansza.h"

namespace Szachy
{
    class Gracz
    {
        public:
            Gracz(TypPionka* typyPionkow, Plansza* plansza, bool czarne);
            Gracz(std::string nazwa);
            virtual ~Gracz();
            static Szachy::Pionek* generujPionki(TypPionka* typyPionkow, Plansza* plansza, bool czarne);
            std::string jakaNazwa() { return m_nazwa; };
            bool czyCzarny() { return m_jestCzarny; };
        protected:

        private:
            std::string m_nazwa;
            Szachy::Pionek* m_pionki;
            bool m_jestCzarny;
    };
}

#endif // GRACZ_H
