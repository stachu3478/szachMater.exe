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
            bool czySzach(Pionek* pionek, Plansza* plansza);
            Pionek* pobierzPionek(int n) { return m_pionki[n]; };
            Array< Array<Ruch*> >& mozliwosciRuchu(Plansza* plansza, bool szach);
            int kierunek() { return m_KolorPionkow.JakaWartosc() != 0 ? -1 : 1; }

            // U¿ycie settera w tym przypadku nie dzia³a
            // zmienna musi byæ publiczna
            int m_szach;
        protected:

        private:
            std::string m_nazwa;
            Szachy::Pionek* m_pionki[16];
            Kolor m_KolorPionkow;
    };
}

#endif // GRACZ_H
