#ifndef KOLOR_H
#define KOLOR_H

#include <string>

/*!
    \brief Reprezentuje kolor
    znaków i t³¹ w konsoli
*/
class Kolor
{
    public:
        /*!
            \brief Konstruktor domyœlny
            Nie generuje ¿adnych danych, dla pustej referencji
        */
        Kolor();
        /*!
            \brief Tworzy kolor i przypisuje mu
            wartoœæ oraz nazwê
            \param nazwa Nazwa danego koloru
            \param wartosc Liczba okreœlaj¹ca kolorstykê w konsoli
        */
        Kolor(std::string nazwa, unsigned char wartosc);
        /** Default destructor */
        virtual ~Kolor();

        /** Access m_Wartosc
         * \return The current value of m_Wartosc
         */
        unsigned char JakaWartosc() { return m_Wartosc; }
        /** Access m_Nazwa
         * \return The current value of m_Nazwa
         */
        std::string JakaNazwa() { return m_Nazwa; }

    protected:

    private:
        std::string m_Nazwa; //!< Member variable "m_Nazwa"
        unsigned char m_Wartosc; //!< Member variable "m_Wartosc"
};

#endif // KOLOR_H
