#ifndef PLANSZA_H
#define PLANSZA_H

#include "Kolor.h"
#include "Pole.h"
#include "TypPionka.h"
#include "Pionek.h"

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
            Pionek* operator[](Pole index);
            void przydzielPionek(Pionek* pionek);

        protected:

        private:
            Szachy::Pole* m_Pola[64];
            Szachy::Pionek* m_PozycjePionkow[64];
            Kolor m_KolorPolaA;
            Kolor m_KolorPolaB;
    };
}

#endif // PLANSZA_H
