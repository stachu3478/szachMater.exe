/*! \file Pole
    \brief Plik klasy Pole
*/

#ifndef POLE_H
#define POLE_H

#include <string>
#include "Kolor.h"

namespace Szachy
{
    /*!
        Jest odzwierciedleniem pola na szachownicy
        Pole jest identyfikowane przez pole numer
    */
    class Pole
    {
        public:
            /*!
                \brief Tworzy nowe pole na podstawie numeru z innej klasy Pole
                \param num Numer zwrócony przez klasę
                \param kolor Kolor pola
            */
            Pole(int num, Kolor* kolor);
            /*!
                \brief Tworzy nowe pole
                \param poziom - pozycja od góry do do³u
                najmniejsza wartoœæ okreœla pole na górze
                jako cyfrowa pozycja pola (od 1 do 8)
                jest bardziej znacz¹ca w wartoœci
                \param pion - pozycja od lewej do prawej
                najmniejsza wartoœæ okreœla pole po lewej
                jako literowa pozycja pola (od 1 do 8)
                jest mniej znacząca w wartoœci
            */
            Pole(int poziom, int pion);
            /*!
                \brief Tworzy nowe pole z innej klasy Pole
                \param pole Klasa Pole, z której ma być utworzone
            */
            Pole(Szachy::Pole* pole);
            Pole(){};
            /// \brief Zwraca czytelną nazwę pola na szachownicy
            /// \return - Reprezentacja cyfrowej i literowej pozycji np. 5C, 1A, 5F
            std::string nazwa();
            /// Destruktor klasy Pole
            virtual ~Pole();
            /// \brief Implementacja przypisania klas typu Pole
            Pole& operator=(const Pole& other);
            /// \brief Implementacje porównań klas typu Pole
            bool operator==(const Pole& other);
            bool operator!=(const Pole& other);
            /// \brief Zwrot identyfikatora
            char pobierzNumer() { return numer; };
            /*!
                \brief Zwraca poziom pola na którym został utworzony
            */
            char poziom() { return numer / 8 + 1; };
            /*!
                \brief Zwraca pion pola na którym został utworzony
            */
            char pion() { return numer % 8 + 1; };
            /*!
                \brief Zwraca kolor przydzielon do pola
            */
            Kolor* JakiKolor() { return m_Kolor; };

        protected:

        private:
            /// Reprezentuje pozycję pola na szachownicy
            /// jest rozumiany jako liczony od prawej do lewej
            /// a nastêpnie od góry do dołu
            unsigned char numer;
            Kolor* m_Kolor;
    };
}

#endif // POLE_H
