#ifndef PLANSZA_H
#define PLANSZA_H

#include "Pole.h"
#include "TypPionka.h"

namespace Szachy
{
    class Plansza
    {
        public:
            Plansza(int rozmiar);
            Plansza();
            virtual ~Plansza();

            void rysuj(char* a, char* b);
            void zresetuj(int rozmiar);
            void generujPola(int a, int b);
            Pole* pobierzPole(unsigned int poziom, unsigned int pion);

        protected:

        private:
            Szachy::Pole* m_Pola[64];
    };
}

#endif // PLANSZA_H
