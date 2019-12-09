/*! \file TypPionka.h
    \brief Plik klasy TypPionka
*/

#ifndef TYPPIONKA_H
#define TYPPIONKA_H

#include <string>
#include "Array.h"

namespace Szachy
{
    /*!
        \brief Klasa TypPionka
        Abstrakcja
    */
    class TypPionka
    {
        public:
            /*!
                \brief Domyœlny konstruktor
                \param nazwa Nazwa typu
                \param opi Opis
                \param sciezka Litera
            */
            TypPionka(std::string nazwa, std::string opis, char sciezka);
            /** Default destructor */
            virtual ~TypPionka();
            /*!
                \brief Zwraca literę która jest przypisana do typu pionka
            */
            std::string jakaLitera() { return litera; };
            /*!
                \brief Zwraca nazwę która jest przypisana do typu pionka
            */
            std::string jakaNazwa() { return nazwa; };
        protected:

        private:
            std::string nazwa; //!< Member variable "nazwa"
            std::string opis; //!< Member variable "opis"
            std::string litera;
    };
}

#endif // TYPPIONKA_H
