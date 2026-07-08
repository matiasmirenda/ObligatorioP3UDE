#include "../../src/include/Lista.h"
#include "../include/TestLista.h"

#include <cassert>

void TestCrear()
{
    Lista l;

    Crear(l);

    assert(l.prim == NULL);
    assert(l.ult == NULL);
}

void TestEsVacia()
{
    Lista l;
    Crear(l);

    assert(EsVacia(l) == TRUE);

    Curso c = {101, {1, 1, 2026}, 10};
    InsBack(l, c);

    assert(EsVacia(l) == FALSE);
}

void TestLargo()
{
    Lista l;
    Crear(l);

    assert(Largo(l) == 0);

    Curso c1 = {101, {1, 1, 2026}, 10};
    Curso c2 = {102, {2, 2, 2026}, 9};
    Curso c3 = {103, {3, 3, 2026}, 8};

    InsBack(l, c1);
    assert(Largo(l) == 1);

    InsBack(l, c2);
    assert(Largo(l) == 2);

    InsBack(l, c3);
    assert(Largo(l) == 3);
}

void TestInsBack()
{
    Lista l;
    Crear(l);

    Curso c1 = {101, {1, 1, 2026}, 10};
    Curso c2 = {102, {2, 2, 2026}, 9};

    InsBack(l, c1);

    assert(l.prim == l.ult);
    assert(Largo(l) == 1);

    InsBack(l, c2);

    assert(l.prim != l.ult);
    assert(Largo(l) == 2);
    assert(l.ult->sig == NULL);
}

void TestUltimo()
{
    Lista l;
    Crear(l);

    Curso c1 = {101, {1, 1, 2026}, 10};
    Curso c2 = {102, {2, 2, 2026}, 9};

    InsBack(l, c1);
    InsBack(l, c2);

    Curso u = Ultimo(l);

    assert(DarNumeroAsignaturaCurso(u) == DarNumeroAsignaturaCurso(c2));
    assert(DarCalificacionCurso(u) == DarCalificacionCurso(c2));
}

void TestKEsimo()
{
    Lista l;
    Crear(l);

    Curso c1 = {101, {1, 1, 2026}, 10};
    Curso c2 = {102, {2, 2, 2026}, 9};
    Curso c3 = {103, {3, 3, 2026}, 8};

    InsBack(l, c1);
    InsBack(l, c2);
    InsBack(l, c3);

    assert(DarNumeroAsignaturaCurso(KEsimo(l, 1)) == DarNumeroAsignaturaCurso(c1));
    assert(DarNumeroAsignaturaCurso(KEsimo(l, 2)) == DarNumeroAsignaturaCurso(c2));
    assert(DarNumeroAsignaturaCurso(KEsimo(l, 3)) == DarNumeroAsignaturaCurso(c3));

    assert(DarCalificacionCurso(KEsimo(l, 1)) == DarCalificacionCurso(c1));
    assert(DarCalificacionCurso(KEsimo(l, 2)) == DarCalificacionCurso(c2));
    assert(DarCalificacionCurso(KEsimo(l, 3)) == DarCalificacionCurso(c3));
}
