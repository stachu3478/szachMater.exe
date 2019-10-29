#ifndef HISTORIARUCHOW_H
#define HISTORIARUCHOW_H

#include "Ruch.h"

#include <string>

namespace Szachy
{
    class HistoriaRuchow
    {
        public:
            HistoriaRuchow();
            HistoriaRuchow(const char* plik);
            virtual ~HistoriaRuchow();
            HistoriaRuchow& operator+=(const Ruch& rhs);

            void renderuj();
            void zapisz(const char* nazwa);
            static Ruch* zaladuj(const char* nazwa);
            static Ruch* przygotujListe();

        protected:

        private:
            unsigned int m_Licznik;
            unsigned int m_Pozycja;
            Szachy::Ruch* m_Lista;
    };
}

#endif // HISTORIARUCHOW_H
