#include "../../src/include/Asignatura.h"
#include "../include/TestAsignatura.h"

#include <assert.h>
#include <stdio.h>

void TestCargarAsignaturaNoOptativa()
{
    Asignatura asignatura;

    FILE *archivo =
        fopen(
            "build/input_asignatura.txt",
            "w");

    assert(archivo != NULL);

    fprintf(archivo, "Programacion III\n");
    fprintf(archivo, "96\n");
    fprintf(archivo, "0\n");

    fclose(archivo);

    FILE *entrada =
        freopen(
            "build/input_asignatura.txt",
            "r",
            stdin);

    assert(entrada != NULL);

    CargarAsignatura(asignatura);

    assert(
        streq(
            DarNombreAsignatura(asignatura),
            (char *)"Programacion III") == TRUE);

    assert(
        DarCantidadHorasAsignatura(asignatura) ==
        96);

    assert(
        EsAsignaturaOptativa(asignatura) ==
        FALSE);
}

void TestCargarAsignaturaOptativa()
{
    Asignatura asignatura;

    FILE *archivo =
        fopen(
            "build/input_asignatura_2.txt",
            "w");

    assert(archivo != NULL);

    fprintf(archivo, "Disenio Textil\n");
    fprintf(archivo, "80\n");
    fprintf(archivo, "1\n");

    fclose(archivo);

    FILE *entrada =
        freopen(
            "build/input_asignatura_2.txt",
            "r",
            stdin);

    assert(entrada != NULL);

    CargarAsignatura(asignatura);

    assert(
        streq(
            DarNombreAsignatura(asignatura),
            (char *)"Disenio Textil") == TRUE);

    assert(
        DarCantidadHorasAsignatura(asignatura) ==
        80);

    assert(
        EsAsignaturaOptativa(asignatura) ==
        TRUE);
}

void TestDarNumeroAsignatura()
{
    Asignatura asignatura;

    asignatura.numero = 7;

    assert(
        DarNumeroAsignatura(
            asignatura) == 7);
}

void TestAsignatura()
{
    TestCargarAsignaturaNoOptativa();
    TestCargarAsignaturaOptativa();
    TestDarNumeroAsignatura();
}
