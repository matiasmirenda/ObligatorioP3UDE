
#include "../../src/include/Alumno.h"
#include "../include/TestAlumno.h"

#include <assert.h>
#include <stdio.h>

void TestCargarAlumno()
{
    Alumno alumno;

    FILE *archivo =
        fopen("build/input_alumno.txt", "w");

    assert(archivo != NULL);

    fprintf(archivo, "Carolina\n");
    fprintf(archivo, "Perez\n");
    fprintf(archivo, "099123456\n");
    fprintf(archivo, "12345678\n");

    fclose(archivo);

    FILE *entrada =
        freopen(
            "build/input_alumno.txt",
            "r",
            stdin);

    assert(entrada != NULL);

    CargarAlumno(alumno);

    assert(DarCedula(alumno) == 12345678);
    assert(CantidadCursosAlumno(alumno) == 0);
    assert(CantidadCursosAprobadosAlumno(alumno) == 0);
}

void TestDarDatosAlumno()
{
    Alumno alumno;

    strcrear(alumno.nombre);
    strcop(
        alumno.nombre,
        (char *)"Carolina");

    strcrear(alumno.apellido);
    strcop(
        alumno.apellido,
        (char *)"Perez");

    strcrear(alumno.telefono);
    strcop(
        alumno.telefono,
        (char *)"099123456");

    alumno.cedula = 12345678;

    Crear(alumno.escolaridad);

    String nombre;
    String apellido;
    String telefono;

    strcrear(nombre);
    strcrear(apellido);
    strcrear(telefono);

    DarNombre(alumno, nombre);
    DarApellido(alumno, apellido);
    DarTelefono(alumno, telefono);

    assert(
        streq(
            nombre,
            (char *)"Carolina") == TRUE);

    assert(
        streq(
            apellido,
            (char *)"Perez") == TRUE);

    assert(
        streq(
            telefono,
            (char *)"099123456") == TRUE);

    strdestruir(nombre);
    strdestruir(apellido);
    strdestruir(telefono);
}

void TestAlumnoSinCursos()
{
    Alumno alumno;

    alumno.cedula = 12345678;

    Crear(alumno.escolaridad);

    assert(
        CantidadCursosAlumno(alumno) ==
        0);

    assert(
        CantidadCursosAprobadosAlumno(alumno) ==
        0);
}

void TestAgregarCursoAlumno()
{
    Alumno alumno;
    Curso curso;

    alumno.cedula = 12345678;

    Crear(alumno.escolaridad);

    curso.numeroAsignatura = 1;
    curso.fechaFinalizacion = {15, 5, 2023};
    curso.calificacion = 8;

    AgregarCursoAlumno(
        alumno,
        curso);

    assert(
        CantidadCursosAlumno(alumno) ==
        1);
}

void TestCantidadCursosAlumno()
{
    Alumno alumno;

    alumno.cedula = 12345678;

    Crear(alumno.escolaridad);

    Curso curso1 =
        {1, {15, 5, 2023}, 8};

    Curso curso2 =
        {2, {20, 6, 2023}, 4};

    assert(
        CantidadCursosAlumno(alumno) ==
        0);

    AgregarCursoAlumno(
        alumno,
        curso1);

    assert(
        CantidadCursosAlumno(alumno) ==
        1);

    AgregarCursoAlumno(
        alumno,
        curso2);

    assert(
        CantidadCursosAlumno(alumno) ==
        2);
}

void TestCantidadCursosAprobadosAlumno()
{
    Alumno alumno;

    alumno.cedula = 12345678;

    Crear(alumno.escolaridad);

    Curso aprobado =
        {1, {15, 5, 2023}, 8};

    Curso noAprobado =
        {2, {20, 6, 2023}, 4};

    AgregarCursoAlumno(
        alumno,
        aprobado);

    AgregarCursoAlumno(
        alumno,
        noAprobado);

    assert(
        CantidadCursosAprobadosAlumno(alumno) ==
        1);
}

void TestTieneAsignaturaAprobadaAlumno()
{
    Alumno alumno;

    alumno.cedula = 12345678;

    Crear(alumno.escolaridad);

    Curso aprobado =
        {5, {15, 5, 2023}, 9};

    Curso noAprobado =
        {6, {20, 6, 2023}, 2};

    AgregarCursoAlumno(
        alumno,
        aprobado);

    AgregarCursoAlumno(
        alumno,
        noAprobado);

    assert(
        TieneAsignaturaAprobadaAlumno(
            alumno,
            5) == TRUE);

    assert(
        TieneAsignaturaAprobadaAlumno(
            alumno,
            6) == FALSE);

    assert(
        TieneAsignaturaAprobadaAlumno(
            alumno,
            10) == FALSE);
}

void TestAlumno()
{
    TestCargarAlumno();
    TestDarDatosAlumno();
    TestAlumnoSinCursos();
    TestAgregarCursoAlumno();
    TestCantidadCursosAlumno();
    TestCantidadCursosAprobadosAlumno();
    TestTieneAsignaturaAprobadaAlumno();
}
