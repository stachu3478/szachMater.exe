#ifndef TYPPIONKA_H
#define TYPPIONKA_H

#include <string>

class TypPionka
{
    public:
        /** Default constructor */
        TypPionka(std::string nazwa, std::string opis, std::string sciezka);
        /** Default destructor */
        virtual ~TypPionka();

        const std::string nazwa; //!< Member variable "nazwa"
        const std::string opis; //!< Member variable "opis"

    protected:

    private:
};

#endif // TYPPIONKA_H
