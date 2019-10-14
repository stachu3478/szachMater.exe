#include "TypPionka.h"
#include <string>

TypPionka::TypPionka(std::string nazwa, std::string opis, std::string sciezka)
{
    this->nazwa = nazwa;
    this->opis = opis;
}

TypPionka::~TypPionka()
{
    //dtor
}
