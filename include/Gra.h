/*! \file Gra.h
    \brief Plik nagłówkowy dla klasy Gra
*/

#ifndef GRA_H
#define GRA_H

#include "Gracz.h"
#include "Plansza.h"
#include "TypPionka.h"

/*!
    \brief Cała przestrzeń dotycząca mechaniki gry
*/
namespace Szachy
{
    /*!
        \brief Najwyższy poziom klasy programu
    */
    class Gra
    {
        public:
            /*!
                \brief Przygotowuje dane wymagane do rozpoczęcia gry
                \param kontynuuj Określa czy postęp w grze ma zostać załadowany z pliku
                lub ma być rozpoczęta nowa gra
            */
            Gra(bool kontynnuj);
            virtual ~Gra();

            /*!
                \brief Rozpoczyna grę, i tym samym wykonuje tury aż do skończenia gry
                \param demo Określa czy w grę mają grać gracze komputerowi
            */
            void rozpocznij(bool demo);

        protected:

        private:

            void generujTypyPionkow();
            void zakoncz(Gracz zwyciesca);
            bool kolejka(Gracz gracz, Gracz przeciwnik);

            void zapisz();
            void zaladuj();

            Szachy::Plansza m_Plansza;
            Szachy::Gracz m_Gracz1;
            Szachy::Gracz m_Gracz2;
            Array<Szachy::TypPionka*> m_TypyPionkow;
            bool m_szach;
            bool m_koniec;
            bool m_Kolejka;
            bool m_demo;
    };
}

#endif // GRA_H
