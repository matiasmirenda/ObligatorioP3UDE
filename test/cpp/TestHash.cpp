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
}