#ifndef TYPPIONKA_H
#define TYPPIONKA_H

#include <string>
#include "Array.h"

namespace Szachy
{
    class TypPionka
    {
        public:
            /** Default constructor */
            TypPionka(std::string nazwa, std::string opis, char sciezka);
            /** Default destructor */
            virtual ~TypPionka();
            //static TypPionka** generuj();
            std::string jakaLitera() { return litera; };
            std::string jakaNazwa() { return nazwa; };
            std::string info();
            Array< Array<char> >* mozliwosciRuchu() { return &m_MozliweRuchy; };
            void dodajRuch(int x, int y);

        protected:

        private:
            std::string nazwa; //!< Member variable "nazwa"
            std::string opis; //!< Member variable "opis"
            std::string litera;
            Array< Array<char> > m_MozliweRuchy;
    };
}

#endif // TYPPIONKA_H
