#include "Tester.h"

#include <iostream>

#include "Kolor.h"
#include "Array.h"
#include "TypPionka.h"
#include "Pole.h"
#include "Pionek.h"
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
}

void testPole()
{
    Pole pole(3, 4);
    if (pole.pion() != 4) throw pole;
    if (pole.poziom() != 3) throw pole;
    if (pole.nazwa() != "3D") throw pole;
    if (pole.pobierzNumer() != 19) throw pole;
}

void testGracz()
{
    // nie wiem dlaczego ten test dziala
}

void testPlansza()
{
    Plansza* plansza = new Plansza(8);
    Pole* pole = plansza->pobierzPole(2, 3);
    assert(2 * 8 + 3 - 9, (int)pole->pobierzNumer());

    assert((int)pole->poziom(), 2);
    assert((int)pole->pion(), 3);
    Pole*& poleRef = pole;

    Pole* pole2 = plansza->pobierzPole(pole->poziom(), pole->pion());
    assert((int)pole->poziom(), 2);
    assert((int)pole->pion(), 3);
    assert(pole == pole2, true);

    assert(plansza->pobierzPolePrzes(poleRef, 1, 2), true);
    assert((int)pole->poziom(), 3);
    assert((int)pole->pion(), 5);

    assert(plansza->pobierzPolePrzes(poleRef, -2, 1), true);
    assert((int)pole->poziom(), 1);
    assert((int)pole->pion(), 6);

    assert(plansza->pobierzPolePrzes(poleRef, 3, -4), true);
    assert((int)pole->poziom(), 4);
    assert((int)pole->pion(), 2);

    assert(plansza->pobierzPolePrzes(poleRef, 0, 0), true);
    assert((int)pole->poziom(), 4);
    assert((int)pole->pion(), 2);

    assert(plansza->pobierzPolePrzes(poleRef, 5, 4), false);
    assert(plansza->pobierzPolePrzes(poleRef, 3, -2), false);
}

void testStringChar()
{
    char ca = 'a';
    string sa = "a";
    string sb = "b";

    string sca = "";
    sca += ca;
    assert(sa == sca, true);
    assert(sa == sb, false);
    assert(sca == sb, false);
}

void testPionek()
{
    TypPionka* typ1 = new TypPionka("a", "b", 'q');
    Kolor* kolor1 = new Kolor();
    Pole* pole1 = new Pole();
    TypPionka* typ = typ1;
    Kolor* kolor = kolor1;
    Pole* pole = pole1;
    Pionek pion(&*typ, &*pole, &*kolor);
    pion.zbij();
    assert(pion.czyZbity(), true);
}

Tester::Tester()
{
    testArray();
    testTypPionka();
    testPole();
    testGracz();
    testPlansza();
    testStringChar();
    testPionek();
}

Tester::~Tester()
{
    //dtor
}
