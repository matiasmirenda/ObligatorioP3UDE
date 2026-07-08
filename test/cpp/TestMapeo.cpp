#include "../../src/include/Mapeo.h"
#include "../include/TestMapeo.h"

#include <cassert>

Asignatura CrearAsignaturaMapeoTest(char nombre[], int horas, Boolean optativa)
{
    Asignatura a;

    strcrear(a.nombre);
    strcop(a.nombre, nombre);
    a.cantidadHoras = horas;
    a.esOptativa = optativa;

    return a;
}

void TestCrearMapeo()
{
    Mapeo m;

    Crear(m);

    assert(CantidadRegistradas(m) == 0);

    for (int i = 0; i < TAM; i++)
    {
        assert(Pertenece(m, i) == FALSE);
    }
}

void TestInsertarMapeo()
{
    Mapeo m;
    Crear(m);

    char n1[] = "Programacion";
    char n2[] = "Matematica";

    Asignatura a1 = CrearAsignaturaMapeoTest(n1, 60, FALSE);
    Asignatura a2 = CrearAsignaturaMapeoTest(n2, 90, TRUE);

    Insertar(m, a1);

    assert(CantidadRegistradas(m) == 1);
    assert(Pertenece(m, 0) == TRUE);
    assert(Pertenece(m, 1) == FALSE);

    Insertar(m, a2);

    assert(CantidadRegistradas(m) == 2);
    assert(Pertenece(m, 0) == TRUE);
    assert(Pertenece(m, 1) == TRUE);
    assert(Pertenece(m, 2) == FALSE);
}

void TestPerteneceMapeo()
{
    Mapeo m;
    Crear(m);

    char n[] = "Disenio";
    Asignatura a = CrearAsignaturaMapeoTest(n, 60, FALSE);

    assert(Pertenece(m, 0) == FALSE);

    Insertar(m, a);

    assert(Pertenece(m, 0) == TRUE);
    assert(Pertenece(m, 1) == FALSE);
}

void TestObtenerMapeo()
{
    Mapeo m;
    Crear(m);

    char n1[] = "Programacion";
    char n2[] = "Matematica";

    Asignatura a1 = CrearAsignaturaMapeoTest(n1, 60, FALSE);
    Asignatura a2 = CrearAsignaturaMapeoTest(n2, 90, TRUE);

    Insertar(m, a1);
    Insertar(m, a2);

    Asignatura r1 = Obtener(m, 0);
    Asignatura r2 = Obtener(m, 1);

    assert(streq(DarNombreAsignatura(r1), DarNombreAsignatura(a1)));
    assert(DarCantidadHorasAsignatura(r1) == DarCantidadHorasAsignatura(a1));
    assert(EsAsignaturaOptativa(r1) == EsAsignaturaOptativa(a1));

    assert(streq(DarNombreAsignatura(r2), DarNombreAsignatura(a2)));
    assert(DarCantidadHorasAsignatura(r2) == DarCantidadHorasAsignatura(a2));
    assert(EsAsignaturaOptativa(r2) == EsAsignaturaOptativa(a2));
}

void TestCantidadRegistradasMapeo()
{
    Mapeo m;
    Crear(m);

    char n1[] = "A";
    char n2[] = "B";
    char n3[] = "C";

    Asignatura a1 = CrearAsignaturaMapeoTest(n1, 60, FALSE);
    Asignatura a2 = CrearAsignaturaMapeoTest(n2, 90, TRUE);
    Asignatura a3 = CrearAsignaturaMapeoTest(n3, 120, FALSE);

    assert(CantidadRegistradas(m) == 0);

    Insertar(m, a1);
    assert(CantidadRegistradas(m) == 1);

    Insertar(m, a2);
    assert(CantidadRegistradas(m) == 2);

    Insertar(m, a3);
    assert(CantidadRegistradas(m) == 3);
}
