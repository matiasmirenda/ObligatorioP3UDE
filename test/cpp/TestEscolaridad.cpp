#include "../../src/include/Escolaridad.h"
#include "../include/TestEscolaridad.h"

#include <assert.h>

void TestCrearEscolaridad()
{
    Escolaridad escolaridad;

    Crear(escolaridad);

    assert(
        EsVacia(escolaridad) ==
        TRUE);

    assert(
        Largo(escolaridad) ==
        0);
}

void TestEsVaciaEscolaridad()
{
    Escolaridad escolaridad;

    Crear(escolaridad);

    assert(
        EsVacia(escolaridad) ==
        TRUE);

    Curso curso =
        {1, {1, 7, 2026}, 8};

    InsBack(
        escolaridad,
        curso);

    assert(
        EsVacia(escolaridad) ==
        FALSE);
}

void TestLargoEscolaridad()
{
    Escolaridad escolaridad;

    Crear(escolaridad);

    assert(
        Largo(escolaridad) ==
        0);

    InsBack(
        escolaridad,
        {1, {1, 7, 2026}, 8});

    assert(
        Largo(escolaridad) ==
        1);

    InsBack(
        escolaridad,
        {2, {2, 7, 2026}, 5});

    assert(
        Largo(escolaridad) ==
        2);
}

void TestInsBackEscolaridad()
{
    Escolaridad escolaridad;

    Crear(escolaridad);

    Curso curso1 =
        {1, {1, 7, 2026}, 8};

    Curso curso2 =
        {2, {2, 7, 2026}, 5};

    InsBack(
        escolaridad,
        curso1);

    InsBack(
        escolaridad,
        curso2);

    assert(
        Largo(escolaridad) ==
        2);

    assert(
        DarNumeroAsignaturaCurso(
            KEsimo(escolaridad, 1)) == 1);

    assert(
        DarNumeroAsignaturaCurso(
            KEsimo(escolaridad, 2)) == 2);
}

void TestUltimoEscolaridad()
{
    Escolaridad escolaridad;

    Crear(escolaridad);

    Curso curso1 =
        {1, {1, 7, 2026}, 8};

    Curso curso2 =
        {2, {2, 7, 2026}, 5};

    InsBack(
        escolaridad,
        curso1);

    InsBack(
        escolaridad,
        curso2);

    Curso ultimo =
        Ultimo(escolaridad);

    assert(
        DarNumeroAsignaturaCurso(
            ultimo) == 2);

    assert(
        DarCalificacionCurso(
            ultimo) == 5);
}

void TestKEsimoEscolaridad()
{
    Escolaridad escolaridad;

    Crear(escolaridad);

    InsBack(
        escolaridad,
        {1, {1, 7, 2026}, 8});

    InsBack(
        escolaridad,
        {2, {2, 7, 2026}, 5});

    InsBack(
        escolaridad,
        {3, {3, 7, 2026}, 10});

    assert(
        DarNumeroAsignaturaCurso(
            KEsimo(escolaridad, 1)) == 1);

    assert(
        DarNumeroAsignaturaCurso(
            KEsimo(escolaridad, 2)) == 2);

    assert(
        DarNumeroAsignaturaCurso(
            KEsimo(escolaridad, 3)) == 3);
}

void TestAsignaturaAprobadaEscolaridad()
{
    Escolaridad escolaridad;

    Crear(escolaridad);

    InsBack(
        escolaridad,
        {1, {1, 7, 2026}, 5});

    InsBack(
        escolaridad,
        {2, {2, 7, 2026}, 6});

    assert(
        AsignaturaAprobada(
            escolaridad,
            1) == FALSE);

    assert(
        AsignaturaAprobada(
            escolaridad,
            2) == TRUE);

    assert(
        AsignaturaAprobada(
            escolaridad,
            10) == FALSE);
}

void TestCantidadAprobadosEscolaridad()
{
    Escolaridad escolaridad;

    Crear(escolaridad);

    assert(
        CantidadAprobados(
            escolaridad) == 0);

    InsBack(
        escolaridad,
        {1, {1, 7, 2026}, 5});

    assert(
        CantidadAprobados(
            escolaridad) == 0);

    InsBack(
        escolaridad,
        {2, {2, 7, 2026}, 6});

    assert(
        CantidadAprobados(
            escolaridad) == 1);

    InsBack(
        escolaridad,
        {3, {3, 7, 2026}, 10});

    assert(
        CantidadAprobados(
            escolaridad) == 2);
}

void TestCantidadCursosEscolaridad()
{
    Escolaridad escolaridad;

    Crear(escolaridad);

    assert(
        CantidadCursosEscolaridad(
            escolaridad) == 0);

    InsBack(
        escolaridad,
        {1, {1, 7, 2026}, 5});

    assert(
        CantidadCursosEscolaridad(
            escolaridad) == 1);

    InsBack(
        escolaridad,
        {2, {2, 7, 2026}, 8});

    assert(
        CantidadCursosEscolaridad(
            escolaridad) == 2);
}

void TestEscolaridad()
{
    TestCrearEscolaridad();
    TestEsVaciaEscolaridad();
    TestLargoEscolaridad();
    TestInsBackEscolaridad();
    TestUltimoEscolaridad();
    TestKEsimoEscolaridad();
    TestAsignaturaAprobadaEscolaridad();
    TestCantidadAprobadosEscolaridad();
    TestCantidadCursosEscolaridad();
}