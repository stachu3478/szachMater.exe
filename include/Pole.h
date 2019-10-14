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
            /// jest mniej znacz¹ca w wartoœci
            Pole(int poziom, int pion);
            /// Zwraca czyteln¹ nazwê pola na szachownicy
            /// \return - Reprezentacja cyfrowej i literowej pozycji np. 5C, 1A, 5F
            std::string nazwa();
            /// Destruktor klasy Pole
            virtual ~Pole();
            /// Implementacja przypisania klas typu Pole
            Pole& operator=(const Pole& other);
            /// Implementacje porównań klas typu Pole
            bool operator==(const Pole& other);
            bool operator!=(const Pole& other);

        protected:

        private:
            /// Reprezentuje pozycjê pola na szachownicy
            /// jest rozumiany jako liczony od prawej do lewej
            /// a nastêpnie od góry do dołu
            unsigned short numer;
    };
}

#endif // POLE_H
