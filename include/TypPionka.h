#ifndef TYPPIONKA_H
#define TYPPIONKA_H

#include <string>

namespace Szachy
{
    class TypPionka
    {
        public:
            /** Default constructor */
            TypPionka(std::string nazwa, std::string opis, char sciezka);
            /** Default destructor */
            virtual ~TypPionka();
            static TypPionka* generuj();
            std::string jakaLitera() { return litera; };
            std::string jakaNazwa() { return nazwa; };
            std::string info();
            int** mozliwosciRuchu();

        protected:

        private:
            std::string nazwa; //!< Member variable "nazwa"
            std::string opis; //!< Member variable "opis"
            std::string litera;
    };
}

#endif // TYPPIONKA_H
