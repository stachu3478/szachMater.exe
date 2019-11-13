#ifndef PLANSZA_H
#define PLANSZA_H

#include "Pole.h"
#include "TypPionka.h"

namespace Szachy
{
    class Plansza
    {
        public:
            Plansza(unsigned int rozmiar);
            Plansza();
            virtual ~Plansza();

            void rysuj(char* a, char* b);
            void zresetuj(unsigned int rozmiar);
            Pole* pobierzPole(unsigned int poziom, unsigned int pion);

        protected:

        private:
            Szachy::Pole* m_Pola;
    };
}

#endif // PLANSZA_H
