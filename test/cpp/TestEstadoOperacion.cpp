#include "../../src/include/EstadoOperacion.h"
#include "../include/TestEstadoOperacion.h"

void TestMostrarEstadoOK()
{
    MostrarEstadoOperacion(OK);
}

void TestMostrarEstadoMaximoAsignaturas()
{
    MostrarEstadoOperacion(
        MAXIMO_ASIGNATURAS_ALCANZADO);
}

void TestMostrarEstadoAsignatura1NoExiste()
{
    MostrarEstadoOperacion(
        ASIGNATURA1_NO_EXISTE);
}

void TestMostrarEstadoAsignatura2NoExiste()
{
    MostrarEstadoOperacion(
        ASIGNATURA2_NO_EXISTE);
}

void TestMostrarEstadoAlumnoYaExiste()
{
    MostrarEstadoOperacion(
        ALUMNO_YA_EXISTE);
}

void TestMostrarEstadoAlumnoNoExiste()
{
    MostrarEstadoOperacion(
        ALUMNO_NO_EXISTE);
}

void TestMostrarEstadoMismaAsignatura()
{
    MostrarEstadoOperacion(
        MISMA_ASIGNATURA);
}

void TestMostrarEstadoPreviaturaGeneraCiclo()
{
    MostrarEstadoOperacion(
        PREVIATURA_GENERA_CICLO);
}

void TestMostrarEstadoAsignaturaYaAprobada()
{
    MostrarEstadoOperacion(
        ASIGNATURA_YA_APROBADA);
}

void TestMostrarEstadoPreviasNoAprobadas()
{
    MostrarEstadoOperacion(
        PREVIAS_NO_APROBADAS);
}

void TestMostrarEstadoFechaInvalida()
{
    MostrarEstadoOperacion(
        FECHA_INVALIDA);
}

void TestMostrarEstadoFechaAnteriorUltimoCurso()
{
    MostrarEstadoOperacion(
        FECHA_ANTERIOR_ULTIMO_CURSO);
}

void TestMostrarEstadoCalificacionInvalida()
{
    MostrarEstadoOperacion(
        CALIFICACION_INVALIDA);
}

void TestMostrarEstadoDesconocido()
{
    MostrarEstadoOperacion(
        (EstadoOperacion)999);
}

void TestEstadoOperacion()
{
    TestMostrarEstadoOK();

    TestMostrarEstadoMaximoAsignaturas();

    TestMostrarEstadoAsignatura1NoExiste();

    TestMostrarEstadoAsignatura2NoExiste();

    TestMostrarEstadoAlumnoYaExiste();

    TestMostrarEstadoAlumnoNoExiste();

    TestMostrarEstadoMismaAsignatura();

    TestMostrarEstadoPreviaturaGeneraCiclo();

    TestMostrarEstadoAsignaturaYaAprobada();

    TestMostrarEstadoPreviasNoAprobadas();

    TestMostrarEstadoFechaInvalida();

    TestMostrarEstadoFechaAnteriorUltimoCurso();

    TestMostrarEstadoCalificacionInvalida();

    TestMostrarEstadoDesconocido();
}