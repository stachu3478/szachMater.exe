/*! \file Pionek.h
    \brief Plik klasy Pionek
*/

#ifndef PIONEK_H
#define PIONEK_H

#include <fstream>
#include "Kolor.h"
#include "TypPionka.h"
#include "Pole.h"
#include "Array.h"

namespace Szachy
{
    /*!
        \brief Abstrakcja pionka
    */
    class Pionek
    {
        public:
            /*!
                \brief Tworzy nowy pionek
                z okreœlonym typem, pozycj¹ i kolorem
                \param typ Typ pionka
                \param pozycja Startowa pozycja pionka
                \param kolor Kolor który ma byæ przypisany do pionka
            */
            Pionek(TypPionka* typ, Pole* pozycja, Kolor* kolor);
            virtual ~Pionek();

            /*!
                \brief Zwraca typ pionka
            */
            TypPionka jakiTyp() { return *m_typ; };
            /*!
                \brief Zwraca pozycjê pionka
            */
            Pole* jakaPozycja() { return m_pozycja; }
            /*!
                \brief Zwraca literê typu pionka
            */
            std::string jakaLitera() { return m_typ->jakaLitera(); }
            /*!
                \brief Zwraca podan¹ nazwê typu pionka
            */
            std::string nazwa() { return m_typ->jakaNazwa(); };
            /*!
                \brief Przenosi pionek na podane pole
                \param val Pole na które ma byæ przeniesiony pionek
            */
            void przenies(Szachy::Pole* val);
            /*!
                \brief Zwraca kolor przydzielony do pionka
            */
            Kolor* JakiKolor(){ return m_Kolor; }
            /*!
                \brief Mówi czy jakikolwiek ruch tym pionkiem zosta³ wykonany
            */
            bool czyBylPierwszyruch() { return m_bylPierwszyRuch; }
            /*!
                \brief Mówi czy pionek zosta³ ju¿ zbity
            */
            bool czyZbity() { return m_zbity; }
            /*!
                \brief Podmienia typ pionka
                \param typ Docelowy typ
            */
            void awansuj(TypPionka* typ) { m_typ = typ; };
            /*!
                \brief Zbija pionek
            */
            void zbij();

            /*!
                \brief Zapisuje dane pionka
                \param Referencja potoku plikowego
            */
            void zapisz(std::ofstream& f);
            /*!
                \brief £aduje dane pinoka
                \param Referencja potoku plikowego
            */
            void zaladuj(std::ifstream& f);

        protected:

        private:
            Szachy::TypPionka* m_typ;
            Szachy::Pole* m_pozycja;
            Kolor* m_Kolor;
            bool m_bylPierwszyRuch;
            bool m_zbity;
    };
};

#endif // PIONEK_H
