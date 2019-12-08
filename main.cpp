#include <iostream>
#include <windows.h>
#include "Gra.h"
#include "Tester.h"

using namespace std;
using namespace Szachy;

int main()
{
    SetConsoleOutputCP( 65001 ); // Umożliwia pisanie w konsoli polskich znaków (nie działa)

    Tester();
    cout << "Inicjalizacja" << endl;

    int odp;
    cout << "1. Nowa gra" << endl
    << "2. Kontynnuj" << endl
    << "3. Gra komputerow" << endl
    << "4. Wyjdź" << endl;
    cin >> odp;
    switch(odp)
    {
        case 1:
        {
            Gra* szachy = new Gra(false);
            szachy->rozpocznij(false);
        };break;
        case 2:
        {
            Gra* szachy = new Gra(true);
            szachy->rozpocznij(false);
        };break;
        case 3:
        {
            Gra* szachy = new Gra(false);
            szachy->rozpocznij(true);
        };break;
        default:
        {
            return 0;
        };
    };
    return 0;
}
