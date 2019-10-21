#ifndef PLANSZA_H
#define PLANSZA_H

#include "Pole.h"
#include "TypPionka.h"

class Plansza
{
    public:
        Plansza(int rozmiar = 8);
        virtual ~Plansza();

        void rysuj();
        void zresetuj(TypPionka* typyPionkow);

    protected:

    private:
        Pole m_Pola[];
};

#endif // PLANSZA_H
