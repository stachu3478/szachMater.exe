/*! \file Ruch.h
    \brief Zwraca poziom pola na którym zosta³ utworzony
*/

#ifndef RUCH_H
#define RUCH_H

#include "Pole.h"
#include "TypPionka.h"
#include "Pionek.h"

namespace Szachy
{
    /*!
        \brief Abstrakcja ruchu
    */
    class Ruch
    {
        public:
            /*!
                \brief Domyœlny konstruktor ruchu
                dla pustej referencji
                Nie inicjuje ¿adnych danych
            */
            Ruch();
            /*!
                \brief Tworzy nowy Ruch
                \param pionek Pionek, który ma byæ przeniesiony
                \param od Pozycja od której startuje pionek
                \param na Pozycja gdzie koñczy pionek
            */
            Ruch(Pionek* pionek, Pole* na);
            /*!
                \brief Mówi, który pionek wykonuje ten ruch
            */
            Pionek* jakiPionek(){ return m_Pionek; };
            /*!
                \brief Zwraca pozcyjê docelow¹ pionka
            */
            Pole* jakiCel(){ return m_PozycjaDocelowa; };
            /*!
                \brief Zwraca pozycjê startow¹ pionka
            */
            Pole* jakiStart(){ return m_PozycjaStartowa; };
            virtual ~Ruch();

        protected:

        private:
            Pionek* m_Pionek;
            Pole* m_PozycjaStartowa;
            Pole* m_PozycjaDocelowa;
    };
}

#endif // RUCH_H
