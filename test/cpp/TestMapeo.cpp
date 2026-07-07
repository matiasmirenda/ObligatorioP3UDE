#include "Mapeo.h"
#include "TestMapeo.h"
#include <cassert>

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

    Asignatura a1 = {1, 100, 60, FALSE};
    Asignatura a2 = {2, 200, 90, TRUE};

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

    Asignatura a = {1, 100, 60, FALSE};

    assert(Pertenece(m, 0) == FALSE);

    Insertar(m, a);

    assert(Pertenece(m, 0) == TRUE);
    assert(Pertenece(m, 1) == FALSE);
}

void TestObtenerMapeo()
{
    Mapeo m;
    Crear(m);

    Asignatura a1 = {1, 100, 60, FALSE};
    Asignatura a2 = {2, 200, 90, TRUE};

    Insertar(m, a1);
    Insertar(m, a2);

    Asignatura r1 = Obtener(m, 0);
    Asignatura r2 = Obtener(m, 1);

    assert(r1.numero == a1.numero);
    assert(r1.nombre == a1.nombre);
    assert(r1.cantHoras == a1.cantHoras);
    assert(r1.optativa == a1.optativa);

    assert(r2.numero == a2.numero);
    assert(r2.nombre == a2.nombre);
    assert(r2.cantHoras == a2.cantHoras);
    assert(r2.optativa == a2.optativa);
}

void TestCantidadRegistradasMapeo()
{
    Mapeo m;
    Crear(m);

    assert(CantidadRegistradas(m) == 0);

    Insertar(m, {1, 100, 60, FALSE});
    assert(CantidadRegistradas(m) == 1);

    Insertar(m, {2, 200, 90, TRUE});
    assert(CantidadRegistradas(m) == 2);

    Insertar(m, {3, 300, 120, FALSE});
    assert(CantidadRegistradas(m) == 3);
}