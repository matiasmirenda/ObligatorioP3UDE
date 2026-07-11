#include "../../src/include/Curso.h"
#include "../include/TestCurso.h"

#include <assert.h>
#include <stdio.h>

void TestCargarCurso()
{
    Curso curso;

    FILE *archivo =
        fopen(
            "build/input_curso.txt",
            "w");

    assert(archivo != NULL);

    fprintf(archivo, "3\n");
    fprintf(archivo, "10\n");
    fprintf(archivo, "7\n");
    fprintf(archivo, "2026\n");
    fprintf(archivo, "8\n");

    fclose(archivo);

    FILE *entrada =
        freopen(
            "build/input_curso.txt",
            "r",
            stdin);

    assert(entrada != NULL);

    CargarCurso(curso);

    assert(
        DarNumeroAsignaturaCurso(curso) ==
        3);

    assert(
        DarCalificacionCurso(curso) ==
        8);
}

void TestCursoAprobado()
{
    Curso curso =
        {3, {10, 7, 2026}, 6};

    assert(
        CursoAprobado(curso) ==
        TRUE);

    curso.calificacion = 12;

    assert(
        CursoAprobado(curso) ==
        TRUE);
}

void TestCursoNoAprobado()
{
    Curso curso =
        {3, {10, 7, 2026}, 5};

    assert(
        CursoAprobado(curso) ==
        FALSE);

    curso.calificacion = 0;

    assert(
        CursoAprobado(curso) ==
        FALSE);
}

void TestDarFechaFinalizacionCurso()
{
    Curso curso =
        {3, {10, 7, 2026}, 8};

    Fecha fecha =
        DarFechaFinalizacionCurso(curso);

    assert(fecha.dia == 10);
    assert(fecha.mes == 7);
    assert(fecha.anio == 2026);
}

void TestCurso()
{
    TestCargarCurso();
    TestCursoAprobado();
    TestCursoNoAprobado();
    TestDarFechaFinalizacionCurso();
}