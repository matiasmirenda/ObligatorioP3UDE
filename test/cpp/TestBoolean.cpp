#include "../../src/include/Boolean.h"
#include "../include/TestBoolean.h"

#include <assert.h>
#include <stdio.h>

static void PrepararEntradaBoolean(
    const char nombreArchivo[],
    const char contenido[])
{
    FILE *archivo = fopen(nombreArchivo, "w");
    assert(archivo != NULL);

    fprintf(archivo, "%s", contenido);
    fclose(archivo);

    FILE *entrada =
        freopen(nombreArchivo, "r", stdin);

    assert(entrada != NULL);
}

void TestCargarBooleanFalse()
{
    Boolean valor;

    PrepararEntradaBoolean(
        "build/input_boolean_false.txt",
        "0\n");

    Cargar(valor);

    assert(valor == FALSE);
}

void TestCargarBooleanTrue()
{
    Boolean valor;

    PrepararEntradaBoolean(
        "build/input_boolean_true.txt",
        "1\n");

    Cargar(valor);

    assert(valor == TRUE);
}

void TestDesplegarBooleanFalse()
{
    Desplegar(FALSE);
}

void TestDesplegarBooleanTrue()
{
    Desplegar(TRUE);
}

void TestCargarBooleanValorInvalido()
{
    Boolean valor;

    PrepararEntradaBoolean(
        "build/input_boolean_invalido.txt",
        "5\n"
        "1\n");

    Cargar(valor);

    assert(valor == TRUE);
}

void TestBoolean()
{
    TestCargarBooleanFalse();
    TestCargarBooleanTrue();
    TestCargarBooleanValorInvalido();
    TestDesplegarBooleanFalse();
    TestDesplegarBooleanTrue();
}