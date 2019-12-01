#ifndef GRACZ_H
#define GRACZ_H

#include <string>
#include "Kolor.h"
#include "Ruch.h"
#include "Pionek.h"
#include "TypPionka.h"
#include "Plansza.h"
#include "Array.h"

namespace Szachy
{
    class Gracz
    {
        public:
            Gracz(TypPionka** typyPionkow, Plansza* plansza, unsigned char kolor);
            Gracz();
            virtual ~Gracz();
            void generujPionki(TypPionka** typyPionkow, Plansza* plansza);
            std::string jakaNazwa() { return m_nazwa; };
            Kolor JakiKolor() { return m_KolorPionkow; };
            bool czySzach();
            bool czyPrzegral();
            Pionek* pobierzPionek(int n) { return m_pionki[n]; };
            Array< Array<Ruch*> >& mozliwosciRuchu(Plansza* plansza);
        protected:

        private:
            std::string m_nazwa;
            Szachy::Pionek* m_pionki[16];
            Kolor m_KolorPionkow;
    };
}

#endif // GRACZ_H
