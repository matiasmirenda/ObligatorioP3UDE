#include "../../src/include/String.h"
#include "../include/TestString.h"

#include <assert.h>

void TestStrcrear()
{
    String s;

    strcrear(s);

    assert(s != NULL);
    assert(s[0] == '\0');

    strdestruir(s);
}

void TestStrlar()
{
    String s;

    strcrear(s);
    strcop(s, (char *)"Hola");

    assert(strlar(s) == 4);

    strdestruir(s);
}

void TestStrcop()
{
    String origen;
    String destino;

    strcrear(origen);
    strcrear(destino);

    strcop(origen, (char *)"Programacion");
    strcop(destino, origen);

    assert(streq(destino, origen) == TRUE);

    strdestruir(origen);
    strdestruir(destino);
}

void TestStreq()
{
    String a;
    String b;
    String c;

    strcrear(a);
    strcrear(b);
    strcrear(c);

    strcop(a, (char *)"Curso");
    strcop(b, (char *)"Curso");
    strcop(c, (char *)"Otro");

    assert(streq(a, b) == TRUE);
    assert(streq(a, c) == FALSE);

    strdestruir(a);
    strdestruir(b);
    strdestruir(c);
}

void TestString()
{
    TestStrcrear();
    TestStrlar();
    TestStrcop();
    TestStreq();
}