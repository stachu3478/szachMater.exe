#include <iostream>
#include "Pole.h"

using namespace std;
using namespace Szachy;

int main()
{
    Pole pole1(1, 1);
    Pole pole2(1, 1);
    Pole pole3(2, 8);
    cout << "Hello world!" << endl << "To jest jakaœ pozycja na szachownicy: " << endl << pole1.nazwa() << endl;
    cout << "A to parê ich porównañ:" << endl << (pole1 == pole2) << endl << (pole1 == pole3) << endl << (pole1 != pole2) << endl << (pole1 != pole3);

    return 0;
}
