#include "../../src/include/Hash.h"
#include "../include/TestHash.h"

#include <assert.h>

void TestCrearHash()
{
    Hash hash;

    Crear(hash);

    assert(
        Pertenece(
            hash,
            12345678) == FALSE);
}

void TestInsertarHash()
{
    Hash hash;
    Alumno alumno;

    Crear(hash);

    alumno.cedula = 12345678;

    Insertar(
        hash,
        alumno);

    assert(
        Pertenece(
            hash,
            12345678) == TRUE);
}

void TestObtenerHash()
{
    Hash hash;
    Alumno alumno;
    Alumno obtenido;

    Crear(hash);

    alumno.cedula = 12345678;

    Insertar(
        hash,
        alumno);

    obtenido =
        Obtener(
            hash,
            12345678);

    assert(
        obtenido.cedula ==
        12345678);
}

void TestEliminarPrimerNodoHash()
{
    Hash hash;
    Alumno alumno;

    Crear(hash);

    alumno.cedula = 12345678;

    Insertar(
        hash,
        alumno);

    Eliminar(
        hash,
        12345678);

    assert(
        Pertenece(
            hash,
            12345678) == FALSE);
}

void TestEliminarNodoInternoHash()
{
    Hash hash;
    Alumno primero;
    Alumno segundo;
    Alumno tercero;

    Crear(hash);

    primero.cedula = 1;
    segundo.cedula = 102;
    tercero.cedula = 203;

    Insertar(
        hash,
        primero);

    Insertar(
        hash,
        segundo);

    Insertar(
        hash,
        tercero);

    Eliminar(
        hash,
        102);

    assert(
        Pertenece(
            hash,
            102) == FALSE);

    assert(
        Pertenece(
            hash,
            1) == TRUE);

    assert(
        Pertenece(
            hash,
            203) == TRUE);
}

void TestColisionesHash()
{
    Hash hash;
    Alumno primero;
    Alumno segundo;
    Alumno tercero;

    Crear(hash);

    primero.cedula = 1;
    segundo.cedula = 102;
    tercero.cedula = 203;

    Insertar(
        hash,
        primero);

    Insertar(
        hash,
        segundo);

    Insertar(
        hash,
        tercero);

    assert(
        Obtener(
            hash,
            1)
            .cedula == 1);

    assert(
        Obtener(
            hash,
            102)
            .cedula == 102);

    assert(
        Obtener(
            hash,
            203)
            .cedula == 203);
}

void TestClaveNegativaHash()
{
    Hash hash;
    Alumno alumno;

    Crear(hash);

    alumno.cedula = -50;

    Insertar(
        hash,
        alumno);

    assert(
        Pertenece(
            hash,
            -50) == TRUE);

    assert(
        Obtener(
            hash,
            -50)
            .cedula == -50);

    Eliminar(
        hash,
        -50);

    assert(
        Pertenece(
            hash,
            -50) == FALSE);
}

void TestHash()
{
    TestCrearHash();
    TestInsertarHash();
    TestObtenerHash();
    TestEliminarPrimerNodoHash();
    TestEliminarNodoInternoHash();
    TestColisionesHash();
    TestClaveNegativaHash();
}