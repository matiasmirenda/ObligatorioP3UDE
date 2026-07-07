#include "../../src/include/Hash.h"
#include "../include/TestHash.h"

#include <assert.h>

void TestHash()
{
    Hash hash;
    Alumno a;
    Alumno b;
    Alumno aux;

    Crear(hash);

    a.cedula = 12345678;
    b.cedula = 87654321;

    // Al comenzar no hay alumnos
    assert(Pertenece(hash, 12345678) == FALSE);
    assert(Pertenece(hash, 87654321) == FALSE);

    // Insertar primero
    Insertar(hash, a);

    assert(Pertenece(hash, 12345678) == TRUE);
    assert(Pertenece(hash, 87654321) == FALSE);

    aux = Obtener(hash, 12345678);
    assert(aux.cedula == 12345678);

    // Insertar segundo
    Insertar(hash, b);

    assert(Pertenece(hash, 87654321) == TRUE);

    aux = Obtener(hash, 87654321);
    assert(aux.cedula == 87654321);

    // Eliminar primero
    Eliminar(hash, 12345678);

    assert(Pertenece(hash, 12345678) == FALSE);
    assert(Pertenece(hash, 87654321) == TRUE);

    // Eliminar segundo
    Eliminar(hash, 87654321);

    assert(Pertenece(hash, 87654321) == FALSE);

    // -----------------------------
    // Eliminar un nodo que no es el primero
    // -----------------------------
    Alumno c, d, e;

    c.cedula = 1;
    d.cedula = 102;
    e.cedula = 203;

    Insertar(hash, c);
    Insertar(hash, d);
    Insertar(hash, e);

    Eliminar(hash, 1);

    assert(Pertenece(hash, 1) == FALSE);
    assert(Pertenece(hash, 102) == TRUE);
    assert(Pertenece(hash, 203) == TRUE);

    Eliminar(hash, 102);
    Eliminar(hash, 203);

    assert(Pertenece(hash, 102) == FALSE);
    assert(Pertenece(hash, 203) == FALSE);

    // -----------------------------
    // Clave negativa
    // -----------------------------
    Alumno f;
    f.cedula = -50;

    Insertar(hash, f);

    assert(Pertenece(hash, -50) == TRUE);

    aux = Obtener(hash, -50);
    assert(aux.cedula == -50);

    Eliminar(hash, -50);

    assert(Pertenece(hash, -50) == FALSE);
}