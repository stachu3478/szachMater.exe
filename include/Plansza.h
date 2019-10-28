#ifndef PLANSZA_H
#define PLANSZA_H

#include "Pole.h"
#include "TypPionka.h"

namespace Szachy
{
    class Plansza
    {
        public:
            Plansza(int rozmiar = 8);
            virtual ~Plansza();

            void rysuj();
            void zresetuj();
            Pole* pobierzPole(unsigned int poziom, unsigned int pion);

        protected:

        private:
            Szachy::Pole m_Pola[];
    };
}

#endif // PLANSZA_H
