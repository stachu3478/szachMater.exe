/*! \file Gracz.h
    \brief Plik nag³ówkowy dla klasy Gracz
*/

#ifndef GRACZ_H
#define GRACZ_H

#include <string>
#include <fstream>
#include "Kolor.h"
#include "Ruch.h"
#include "Pionek.h"
#include "TypPionka.h"
#include "Plansza.h"
#include "Array.h"

namespace Szachy
{
    /*!
        \brief Abstrakcja użytkownika aplikacji
    */
    class Gracz
    {
        public:
            /*!
                \brief Tworzy nową instancję gracza
                i pyta o nazwę użytkownika
                \param typyPionkow Typy pionków zdefiniowane w grze
                potrzebne do generowania pionków
                \param plansza Plansza przypisana do gry
                potrzebna do przypisania pionków do planszy
                \param kolor Identyfikator koloru pionków
                przypisany do gracza
                \param kontynnuj Określa czy dane gracza mają być
                załadowane ze wejścia plików
            */
            Gracz(Array<TypPionka*> typyPionkow, Plansza* plansza, unsigned char kolor, bool kontynnuj);
            /*!
                \brief Pusty konstruktor
                Nie generuje danych przy inicjalizacji przez referencję
            */
            Gracz();
            virtual ~Gracz();
            /*!
                \brief Buduje zestaw pionków dla gracza i przypisuje je do planszy
                \param typyPionkow Zestaw typów pionków z których mają być wygenerowane pionki
            */
            void generujPionki(Array<Szachy::TypPionka*> typyPionkow);
            /*!
                \brief Zwraca podaną nazwę gracza
            */
            std::string jakaNazwa() { return m_nazwa; };
            /*!
                \brief Zwraca kolor pionków przypisany do gracza
            */
            Kolor JakiKolor() { return m_KolorPionkow; };
            /*!
                \brief Sprawdza czy dany pionek szachuje króla
                przeciwnika
            */
            bool czySzach(Pionek* pionek);
            /*!
                \brief Zwraca pionek danego gracza po indeksie
                \param n Indeks pionka w tablicy
            */
            Pionek* pobierzPionek(int n) { return m_pionki[n]; };
            /*!
                \brief Podaje możliwe ruchy po pionkach gracza
                które może wykonać
            */
            Array< Array<Ruch*> >& mozliwosciRuchu(bool szach);
            /*!
                \brief Zwraca kierunek w którym wędrują piony tego gracza
                pomiędzy 1 a -1
            */
            int kierunek() { return m_KolorPionkow.JakaWartosc() != 0 ? -1 : 1; }

            /*!
                \brief Zapisuje dane gracza przy użyciu
                potoku pliku
            */
            void zapisz(std::ofstream& f);
            /*!
                \brief Ładuje dane gracza
                przy użyciu potoku pliku
            */
            void zaladuj(std::ifstream& f);
        protected:

        private:
            void przydzielPionki();
            Array<Ruch*>& mozliwosciPionka(Pionek* pionek);
            Array<Pole>& mozliwePolaPionka(Pionek* pionek);

            std::string m_nazwa;
            Szachy::Plansza* m_Plansza;
            Szachy::Pionek* m_pionki[16];
            Kolor m_KolorPionkow;
    };
}

#endif // GRACZ_H
