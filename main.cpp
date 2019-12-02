#include <iostream>
#include <windows.h>
#include "Gra.h"
#include "Tester.h"

using namespace std;
using namespace Szachy;

int main()
{
    SetConsoleOutputCP( 65001 ); // Umożliwia pisanie w konsoli polskich znaków

    Tester();
    cout << "Inicjalizacja" << endl;
    Gra* szachy = new Gra();
    cout << "Rozpoczęcie gry" << endl;
    szachy->rozpocznij();
    return 0;
}
