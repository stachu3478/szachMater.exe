#include "Tester.h"

#include <iostream>

#include "Kolor.h"
#include "Array.h"
#include "TypPionka.h"
#include "Pole.h"
#include "Plansza.h"
#include "Gracz.h"

using namespace std;
using namespace Szachy;

template <class T>
void assert(T a, T b)
{
    if (a != b)
    {
        cout << "AssertionError: " << a << " != " << b << endl;
        cout << "Addresses: " << &a << " " << &b << endl;
        throw a;
    }
}

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

void testPlansza()
{
    Plansza* plansza = new Plansza(8);
    Pole* pole = plansza->pobierzPole(2, 3);
    assert(2 * 8 + 3 - 9, (int)pole->pobierzNumer());

    if (pole->pion() != 3) throw plansza;
    if (pole->poziom() != 2) throw plansza;
    Pole*& poleRef = pole;
    if (!plansza->pobierzPolePrzes(poleRef, 1, 2)) throw plansza;

    assert((int)pole->pion(), 5);
    assert((int)pole->poziom(), 3);

    assert(plansza->pobierzPolePrzes(poleRef, 3, 4), false);
    assert(plansza->pobierzPolePrzes(poleRef, -3, 3), false);
}

Tester::Tester()
{
    testArray();
    testTypPionka();
    testPole();
    testGracz();
    testPlansza();
}

Tester::~Tester()
{
    //dtor
}
