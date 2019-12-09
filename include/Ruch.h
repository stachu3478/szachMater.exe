/*! \file Ruch.h
    \brief Zwraca poziom pola na kt�rym zosta� utworzony
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
                \brief Domy�lny konstruktor ruchu
                dla pustej referencji
                Nie inicjuje �adnych danych
            */
            Ruch();
            /*!
                \brief Tworzy nowy Ruch
                \param pionek Pionek, kt�ry ma by� przeniesiony
                \param od Pozycja od kt�rej startuje pionek
                \param na Pozycja gdzie ko�czy pionek
            */
            Ruch(Pionek* pionek, Pole* na);
            /*!
                \brief M�wi, kt�ry pionek wykonuje ten ruch
            */
            Pionek* jakiPionek(){ return m_Pionek; };
            /*!
                \brief Zwraca pozcyj� docelow� pionka
            */
            Pole* jakiCel(){ return m_PozycjaDocelowa; };
            /*!
                \brief Zwraca pozycj� startow� pionka
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
