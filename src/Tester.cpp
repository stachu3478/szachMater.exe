#include "Tester.h"

#include "Kolor.h"
#include "Array.h"
#include "TypPionka.h"
#include "Pole.h"
#include "Plansza.h"
#include "Gracz.h"

using namespace Szachy;

void testArray()
{
    Array<int> a(10);
    for(int i = 0; i < 50; i++)
    {
        a.push(i);
    }
    for(int i = 0; i < a.len(); i++)
    {
        if (a[i] != i) throw -1;
    }
}

void testTypPionka()
{
    TypPionka typ("test", "test1" , 'T');
    if (typ.jakaLitera() != "T") throw typ;
    if (typ.jakaNazwa() != "test") throw typ;

    typ.dodajRuch(3, 4);
    Array< Array<char> >* xys = typ.mozliwosciRuchu();
    Array<char> xy = (*xys)[0];
    if (xy[0] != 3) throw typ;
    if (xy[1] != 4) throw typ;
}

void testPole()
{
    Pole pole(3, 4);
    if (pole.pion() != 4) throw pole;
    if (pole.poziom() != 3) throw pole;
    if (pole.nazwa() != "3D") throw pole;
    if (pole.pobierzNumer() != 19) throw pole;

    pole.przesun(2, 3);
    if (pole.pion() != 7) throw pole;
    if (pole.poziom() != 5) throw pole;

    if (pole.przesun(0, -7)) throw pole;
    if (pole.pion() != 7) throw pole;

    if (pole.przesun(0, 2)) throw pole;
    if (pole.pion() != 7) throw pole;
}

void testGracz()
{
    Gracz* gracz = new Gracz();
    if (gracz->maSzach()) throw gracz;
    gracz->szachuj();
    if (!gracz->maSzach()) throw gracz;
}

Tester::Tester()
{
    testArray();
    testTypPionka();
    testPole();
}

Tester::~Tester()
{
    //dtor
}
