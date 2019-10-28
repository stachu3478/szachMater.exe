#include <iostream>
#include <windows.h>
#include "Gra.h"

using namespace std;
using namespace Szachy;

int main()
{
    SetConsoleOutputCP( 65001 ); // Umożliwia pisanie w konsoli polskich znaków

    Gra szachy();
    /* Pole pole1(1, 1);
    Pole pole2(1, 1);
    Pole pole3(2, 8);
    Gracz ja("gosciu");
    TypPionka tp("Pion", "To jest Pion", 'O');
    Pionek mojPionek(&tp, pole1, &ja);
    cout << "Hello world!" << endl << "To jest jakaś pozycja na szachownicy: " << endl << pole1.nazwa() << endl;
    cout << "A to parę ich porównań:" << endl << (pole1 == pole2) << endl << (pole1 == pole3) << endl << (pole1 != pole2) << endl << (pole1 != pole3);
    mojPionek.info(); */
    return 0;
}
