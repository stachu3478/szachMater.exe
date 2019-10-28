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
            Szachy::Ruch HistoriaRuchow::operator+=(const Ruch& rhs);

            void renderuj();
            void zapisz(std::string nazwa);
            static void zaladuj(std::string nazwa);

        protected:

        private:
            unsigned int m_Licznik;
            unsigned int m_Pozycja;
            Szachy::Ruch m_Lista[];
    };
}

#endif // HISTORIARUCHOW_H
