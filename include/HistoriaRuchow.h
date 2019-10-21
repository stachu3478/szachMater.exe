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
            HistoriaRuchow(std::string plik);
            virtual ~HistoriaRuchow();
            Ruch& Ruch::operator+=(const Ruch& rhs);

            void renderuj();
            void zapisz();

        protected:

        private:
            unsigned int m_Licznik;
            unsigned int m_Pozycja;
            Ruch m_Lista[];
            void zaladuj(std::string plik);
    };
}

#endif // HISTORIARUCHOW_H
