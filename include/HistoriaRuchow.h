#ifndef HISTORIARUCHOW_H
#define HISTORIARUCHOW_H

#include "Ruch.h"
#include "Array.h"

#include <string>

namespace Szachy
{
    class HistoriaRuchow
    {
        public:
            HistoriaRuchow();
            HistoriaRuchow(const char* plik);
            virtual ~HistoriaRuchow();
            Ruch* dodaj(Ruch* ruch) { return m_Lista.push(ruch); }

            void renderuj();
            void zapisz(const char* nazwa);
            // Array<Ruch*> zaladuj(const char* nazwa);

        protected:

        private:
            Array<Ruch*> m_Lista;
    };
}

#endif // HISTORIARUCHOW_H
