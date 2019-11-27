#ifndef KOLOR_H
#define KOLOR_H

#include <string>

class Kolor
{
    public:
        /** Default constructor */
        Kolor();
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
