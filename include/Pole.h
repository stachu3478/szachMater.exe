#ifndef POLE_H
#define POLE_H

#include <string>

namespace Szachy
{
    /// Jest odzwierciedleniem pola na szachownicy
    /// Pole jest identyfikowane przez pole numer
    class Pole
    {
        public:
            /// Tworzy nowe pole
            /// \param poziom - pozycja od góry do do³u
            /// najmniejsza wartoœæ okreœla pole na górze
            /// jako cyfrowa pozycja pola (od 1 do 8)
            /// jest bardziej znacz¹ca w wartoœci
            /// \param pion - pozycja od lewej do prawej
            /// najmniejsza wartoœæ okreœla pole po lewej
            /// jako literowa pozycja pola (od 1 do 8)
            /// jest mniej znacząca w wartoœci
            Pole(int poziom, int pion);
            /// Tworzy zdefiniowaną listę pól z odniesieniem pozycji
            //static Pole* generuj(int szerokosc, int wysokosc);
            /// Zwraca czyteln¹ nazwê pola na szachownicy
            /// \return - Reprezentacja cyfrowej i literowej pozycji np. 5C, 1A, 5F
            std::string nazwa();
            /// Destruktor klasy Pole
            virtual ~Pole();
            /// Implementacja przypisania klas typu Pole
            Pole& operator=(const Pole& other);
            /// Implementacja przenoszenia pionka na dane pole
            // FIXME
            // Pole& operator=(const Szachy::Pionek& other);
            /// Implementacje porównań klas typu Pole
            bool operator==(const Pole& other);
            bool operator!=(const Pole& other);
            /// Zwrot identyfikatora
            char pobierzNumer() { return numer; };
            char poziom() { return numer / 8; };
            char pion() { return numer % 8; };

        protected:

        private:
            /// Reprezentuje pozycję pola na szachownicy
            /// jest rozumiany jako liczony od prawej do lewej
            /// a nastêpnie od góry do dołu
            unsigned char numer;
            // FIXME
            // Szachy::Pionek* m_pionek;
    };
}

#endif // POLE_H
