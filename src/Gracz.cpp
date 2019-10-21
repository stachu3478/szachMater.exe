#include "Gracz.h"

#include <string>

using namespace Szachy;
using namespace std;

Gracz::Gracz()
{
    cout << "Podaj nazwê gracza: ";
    cin >> m_nazwa;
    cout << endl;
}

Gracz::Gracz(std::string nazwa)
{
    m_nazwa = nazwa;
}

Gracz::~Gracz()
{
    //dtor
}
