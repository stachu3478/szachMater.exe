/*! \file Plansza.h
    \brief Plik klasy Plansza
*/

#ifndef PLANSZA_H
#define PLANSZA_H

#include "Kolor.h"
#include "Pole.h"
#include "TypPionka.h"
#include "Pionek.h"

namespace Szachy
{
    /*!
        \brief Abstrakcja planszy
    */
    class Plansza
    {
        public:
            /*!
                \brief Definiuje plansz� jako kwadrat o podanym rozmiarze
                \param rozmiar D�ugo�� boku w polach
            */
            Plansza(int rozmiar);
            /*!
                \brief Konstruktor domy�lny dla pustej referencji
            */
            Plansza();
            virtual ~Plansza();

            /*!
                \brief Wyprowadza w konsoli plansz�
                z polami i pionkami
                w ustawionych kolorach
            */
            void rysuj();
            /*!
                \brief Pobiera klas� Pola z planszy
                \param poziom Poziom planszy
                \param pion Pion planszy
            */
            Pole* pobierzPole(unsigned int poziom, unsigned int pion);
            /*!
                \brief Pobiera klas� Pola z planszy
                \param i Indeks pola na planszy
            */
            Pole* pobierzPole(int i);
            bool pobierzPolePrzes(Pole*& pole, int x, int y);
            Pionek* pobierzPionek(Pole* pole) { return m_PozycjePionkow[(int)pole->pobierzNumer()]; };
            void przydzielPionek(Pionek* pionek);
            void przeniesPionek(Pionek* pionek, Pole* pozycja);

        protected:

        private:
            void generujPola(int a, int b);

            Szachy::Pole* m_Pola[64];
            Szachy::Pionek* m_PozycjePionkow[64];
            Kolor m_KolorPolaA;
            Kolor m_KolorPolaB;
    };
}

#endif // PLANSZA_H
