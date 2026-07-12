#include "../../src/include/Previas.h"
#include "../../src/include/Boolean.h"
#include "../include/TestPrevias.h"

#include <cassert>

// Operacion auxiliar de test: indica si "valor" esta presente
// entre las primeras "cant" posiciones de "arr".
static Boolean ContieneValor(int arr[], int cant, int valor)
{
    Boolean encontrado = FALSE;
    int i = 0;
    while (i < cant && !encontrado)
    {
        if (arr[i] == valor)
            encontrado = TRUE;
        i++;
    }
    return encontrado;
}

void TestCrearPreviaturas()
{
    Previaturas P;
    CrearPreviaturas(P);

    assert(EsPreviaDirecta(P, 0, 1) == FALSE);
}

void TestAgregarPrevia()
{
    Previaturas P;
    CrearPreviaturas(P);

    // u == v: no se admiten lazos
    assert(AgregarPrevia(P, 3, 3) == FALSE);

    // Caso valido: 0 es previa directa de 1
    assert(AgregarPrevia(P, 0, 1) == TRUE);
    assert(EsPreviaDirecta(P, 0, 1) == TRUE);

    // Intentar (1, 0) formaria un ciclo, ya que existe camino 0 -> 1
    assert(AgregarPrevia(P, 1, 0) == FALSE);
}

void TestEsPreviaDirecta()
{
    Previaturas P;
    CrearPreviaturas(P);

    AgregarPrevia(P, 2, 5);

    assert(EsPreviaDirecta(P, 2, 5) == TRUE);
    assert(EsPreviaDirecta(P, 5, 2) == FALSE);
}

void TestPreviasInmediatasDe()
{
    Previaturas P;
    CrearPreviaturas(P);

    AgregarPrevia(P, 0, 2);
    AgregarPrevia(P, 1, 2);

    int pre[MAX_ASIGNATURAS];
    int cantPre = 0;
    PreviasInmediatasDe(P, 2, pre, cantPre);

    assert(cantPre == 2);
    assert(ContieneValor(pre, cantPre, 0) == TRUE);
    assert(ContieneValor(pre, cantPre, 1) == TRUE);
}

void TestPreviasDe()
{
    Previaturas P;
    CrearPreviaturas(P);

    // Cadena: 0 es previa de 1, 1 es previa de 2
    AgregarPrevia(P, 0, 1);
    AgregarPrevia(P, 1, 2);

    int previas[MAX_ASIGNATURAS];
    int cantPrevias = 0;
    PreviasDe(P, 2, previas, cantPrevias);

    assert(cantPrevias == 2);
    assert(ContieneValor(previas, cantPrevias, 0) == TRUE);
    assert(ContieneValor(previas, cantPrevias, 1) == TRUE);
}

void TestPrevias()
{
    TestCrearPreviaturas();
    TestAgregarPrevia();
    TestEsPreviaDirecta();
    TestPreviasInmediatasDe();
    TestPreviasDe();
}
