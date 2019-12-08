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

            void rysuj();
            void generujPola(int a, int b);
            Pole* pobierzPole(unsigned int poziom, unsigned int pion);
            bool pobierzPolePrzes(Pole*& pole, int x, int y);
            Pionek* pobierzPionek(Pole* pole) { return m_PozycjePionkow[pole->pobierzNumer()]; };
            void przydzielPionek(Pionek* pionek);
            void przeniesPionek(Pionek* pionek, Pole* pozycja);

        protected:

        private:
            Szachy::Pole* m_Pola[64];
            Szachy::Pionek* m_PozycjePionkow[64];
            Kolor m_KolorPolaA;
            Kolor m_KolorPolaB;
    };
}

#endif // PLANSZA_H
