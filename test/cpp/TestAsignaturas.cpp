#include "../../src/include/Asignaturas.h"
#include "../include/TestAsignaturas.h"

#include <assert.h>

void TestCrearAsignaturas()
{
    Asignaturas asignaturas;

    CrearAsignaturas(asignaturas);

    assert(
        CantidadAsignaturas(
            asignaturas) == 0);

    assert(
        ExisteAsignatura(
            asignaturas,
            0) == FALSE);
}

void TestRegistrarPrimeraAsignatura()
{
    Asignaturas asignaturas;
    Asignatura asignatura;
    Asignatura obtenida;

    CrearAsignaturas(asignaturas);

    strcrear(asignatura.nombre);

    strcop(
        asignatura.nombre,
        (char *)"Programacion III");

    asignatura.cantidadHoras = 96;
    asignatura.esOptativa = FALSE;

    RegistrarAsignatura(
        asignaturas,
        asignatura);

    assert(
        CantidadAsignaturas(
            asignaturas) == 1);

    assert(
        ExisteAsignatura(
            asignaturas,
            0) == TRUE);

    obtenida =
        ObtenerAsignatura(
            asignaturas,
            0);

    assert(
        DarNumeroAsignatura(
            obtenida) == 0);
}

void TestRegistrarSegundaAsignatura()
{
    Asignaturas asignaturas;
    Asignatura primera;
    Asignatura segunda;
    Asignatura obtenida;

    CrearAsignaturas(asignaturas);

    strcrear(primera.nombre);

    strcop(
        primera.nombre,
        (char *)"Programacion III");

    primera.cantidadHoras = 96;
    primera.esOptativa = FALSE;

    strcrear(segunda.nombre);

    strcop(
        segunda.nombre,
        (char *)"Base de Datos");

    segunda.cantidadHoras = 80;
    segunda.esOptativa = TRUE;

    RegistrarAsignatura(
        asignaturas,
        primera);

    RegistrarAsignatura(
        asignaturas,
        segunda);

    assert(
        CantidadAsignaturas(
            asignaturas) == 2);

    assert(
        ExisteAsignatura(
            asignaturas,
            1) == TRUE);

    obtenida =
        ObtenerAsignatura(
            asignaturas,
            1);

    assert(
        DarNumeroAsignatura(
            obtenida) == 1);
}

void TestObtenerAsignaturaRegistrada()
{
    Asignaturas asignaturas;
    Asignatura asignatura;
    Asignatura obtenida;

    CrearAsignaturas(asignaturas);

    strcrear(asignatura.nombre);

    strcop(
        asignatura.nombre,
        (char *)"Programacion III");

    asignatura.cantidadHoras = 96;
    asignatura.esOptativa = FALSE;

    RegistrarAsignatura(
        asignaturas,
        asignatura);

    obtenida =
        ObtenerAsignatura(
            asignaturas,
            0);

    assert(
        streq(
            DarNombreAsignatura(obtenida),
            (char *)"Programacion III") == TRUE);

    assert(
        DarCantidadHorasAsignatura(obtenida) ==
        96);

    assert(
        EsAsignaturaOptativa(obtenida) ==
        FALSE);
}

void TestAsignaturas()
{
    TestCrearAsignaturas();
    TestRegistrarPrimeraAsignatura();
    TestRegistrarSegundaAsignatura();
    TestObtenerAsignaturaRegistrada();
}
