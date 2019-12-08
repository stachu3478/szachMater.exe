/*! \file Gracz.h
    \brief Plik nag³ówkowy dla klasy Gracz
*/

#ifndef GRACZ_H
#define GRACZ_H

#include <string>
#include <fstream>
#include "Kolor.h"
#include "Ruch.h"
#include "Pionek.h"
#include "TypPionka.h"
#include "Plansza.h"
#include "Array.h"

namespace Szachy
{
    /*!
        \brief Najwy¿szy poziom klasy programu
    */
    class Gracz
    {
        public:
            Gracz(Array<TypPionka*> typyPionkow, Plansza* plansza, unsigned char kolor, bool kontynnuj);
            Gracz();
            virtual ~Gracz();
            void generujPionki(Array<Szachy::TypPionka*> typyPionkow, Plansza* plansza);
            void przydzielPionki();
            std::string jakaNazwa() { return m_nazwa; };
            Kolor JakiKolor() { return m_KolorPionkow; };
            bool czySzach(Pionek* pionek, Plansza* plansza);
            Pionek* pobierzPionek(int n) { return m_pionki[n]; };
            Array< Array<Ruch*> >& mozliwosciRuchu(Plansza* plansza, bool szach);
            int kierunek() { return m_KolorPionkow.JakaWartosc() != 0 ? -1 : 1; }

            void zapisz(std::ofstream& f);
            void zaladuj(std::ifstream& f);
        protected:

        private:
            std::string m_nazwa;
            Szachy::Plansza* m_Plansza;
            Szachy::Pionek* m_pionki[16];
            Kolor m_KolorPionkow;
    };
}

#endif // GRACZ_H
