
#include "../../src/include/Alumnos.h"
#include "../include/TestAlumnos.h"

#include <assert.h>

void TestCrearAlumnos()
{
    Alumnos alumnos;

    CrearAlumnos(alumnos);

    assert(
        ExisteAlumno(
            alumnos,
            12345678) == FALSE);
}

void TestInscribirAlumno()
{
    Alumnos alumnos;
    Alumno alumno;

    CrearAlumnos(alumnos);

    alumno.cedula = 12345678;

    InscribirAlumno(
        alumnos,
        alumno);

    assert(
        ExisteAlumno(
            alumnos,
            12345678) == TRUE);
}

void TestObtenerAlumno()
{
    Alumnos alumnos;
    Alumno alumno;
    Alumno obtenido;

    CrearAlumnos(alumnos);

    alumno.cedula = 12345678;

    InscribirAlumno(
        alumnos,
        alumno);

    obtenido =
        ObtenerAlumno(
            alumnos,
            12345678);

    assert(
        obtenido.cedula ==
        12345678);
}

void TestModificarAlumno()
{
    Alumnos alumnos;
    Alumno alumno;
    Alumno modificado;
    Alumno obtenido;

    CrearAlumnos(alumnos);

    alumno.cedula = 12345678;

    strcrear(alumno.nombre);
    strcop(
        alumno.nombre,
        (char *)"Juan");

    InscribirAlumno(
        alumnos,
        alumno);

    modificado =
        ObtenerAlumno(
            alumnos,
            12345678);

    strcop(
        modificado.nombre,
        (char *)"Pedro");

    ModificarAlumno(
        alumnos,
        modificado);

    obtenido =
        ObtenerAlumno(
            alumnos,
            12345678);

    assert(
        ExisteAlumno(
            alumnos,
            12345678) == TRUE);

    assert(
        streq(
            obtenido.nombre,
            (char *)"Pedro") == TRUE);
}

void TestAlumnos()
{
    TestCrearAlumnos();
    TestInscribirAlumno();
    TestObtenerAlumno();
    TestModificarAlumno();
}
