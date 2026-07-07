#include "Escolaridad.h"
#include <assert.h>

void TestCrearEscolaridad()
{
    Escolaridad e;

    Crear(e);

    assert(EsVacia(e) == TRUE);
    assert(Largo(e) == 0);
}

void TestEsVaciaEscolaridad()
{
    Escolaridad e;
    Crear(e);

    assert(EsVacia(e) == TRUE);

    Curso c = {101, {1, 7, 2026}, 8};
    InsBack(e, c);

    assert(EsVacia(e) == FALSE);
}

void TestLargoEscolaridad()
{
    Escolaridad e;
    Crear(e);

    assert(Largo(e) == 0);

    InsBack(e, {101, {1, 7, 2026}, 8});
    assert(Largo(e) == 1);

    InsBack(e, {102, {2, 7, 2026}, 5});
    assert(Largo(e) == 2);

    InsBack(e, {103, {3, 7, 2026}, 10});
    assert(Largo(e) == 3);
}

void TestInsBackEscolaridad()
{
    Escolaridad e;
    Crear(e);

    Curso c1 = {101, {1, 7, 2026}, 8};
    Curso c2 = {102, {2, 7, 2026}, 5};

    InsBack(e, c1);

    assert(Largo(e) == 1);

    InsBack(e, c2);

    assert(Largo(e) == 2);
}

void TestUltimoEscolaridad()
{
    Escolaridad e;
    Crear(e);

    Curso c1 = {101, {1, 7, 2026}, 8};
    Curso c2 = {102, {2, 7, 2026}, 5};

    InsBack(e, c1);
    InsBack(e, c2);

    Curso u = Ultimo(e);

    assert(ObtenerNumAsignatura(u) == 102);
    assert(ObtenerCalificacion(u) == 5);
}

void TestKEsimoEscolaridad()
{
    Escolaridad e;
    Crear(e);

    InsBack(e, {101, {1, 7, 2026}, 8});
    InsBack(e, {102, {2, 7, 2026}, 5});
    InsBack(e, {103, {3, 7, 2026}, 10});

    assert(ObtenerNumAsignatura(KEsimo(e, 1)) == 101);
    assert(ObtenerNumAsignatura(KEsimo(e, 2)) == 102);
    assert(ObtenerNumAsignatura(KEsimo(e, 3)) == 103);
}

void TestAsignaturaAprobadaEscolaridad()
{
    Escolaridad e;
    Crear(e);

    InsBack(e, {101, {1, 7, 2026}, 5});  // Reprobada
    InsBack(e, {102, {2, 7, 2026}, 6});  // Aprobada
    InsBack(e, {103, {3, 7, 2026}, 10}); // Aprobada

    // Existe pero está reprobada
    assert(AsignaturaAprobada(e, 101) == FALSE);

    // Existe y está aprobada
    assert(AsignaturaAprobada(e, 102) == TRUE);
    assert(AsignaturaAprobada(e, 103) == TRUE);

    // No existe
    assert(AsignaturaAprobada(e, 999) == FALSE);
}

void TestCantidadAprobadosEscolaridad()
{
    Escolaridad e;
    Crear(e);

    assert(CantidadAprobados(e) == 0);

    InsBack(e, {101, {1, 7, 2026}, 5});
    assert(CantidadAprobados(e) == 0);

    InsBack(e, {102, {2, 7, 2026}, 6});
    assert(CantidadAprobados(e) == 1);

    InsBack(e, {103, {3, 7, 2026}, 10});
    assert(CantidadAprobados(e) == 2);

    InsBack(e, {104, {4, 7, 2026}, 1});
    assert(CantidadAprobados(e) == 2);
}