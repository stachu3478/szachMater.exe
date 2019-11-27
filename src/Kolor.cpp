#include "Kolor.h"
#include <string>

using namespace std;

Kolor::Kolor()
{}

Kolor::Kolor(std::string nazwa, unsigned char wartosc)
{
    m_Nazwa = nazwa;
    m_Wartosc = wartosc;
}

Kolor::~Kolor()
{
    //dtor
}
