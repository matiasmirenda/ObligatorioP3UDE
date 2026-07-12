#include "../../src/include/Grafo.h"
#include "../../src/include/Boolean.h"
#include "../include/TestGrafo.h"

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

void TestCrearGrafo()
{
    Grafo G;
    CrearGrafo(G);

    assert(HayArista(G, 0, 1) == FALSE);
    assert(HayArista(G, 5, 10) == FALSE);
}

void TestAgregarArista()
{
    Grafo G;
    CrearGrafo(G);

    AgregarArista(G, 0, 1);

    assert(HayArista(G, 0, 1) == TRUE);
    assert(HayArista(G, 1, 0) == FALSE);
}

void TestExisteCamino()
{
    Grafo G;
    CrearGrafo(G);

    // Cadena: 0 -> 1 -> 2
    AgregarArista(G, 0, 1);
    AgregarArista(G, 1, 2);

    assert(ExisteCamino(G, 0, 2) == TRUE);
    assert(ExisteCamino(G, 0, 1) == TRUE);
    assert(ExisteCamino(G, 2, 0) == FALSE);
    assert(ExisteCamino(G, 3, 4) == FALSE);
}

void TestPreviasInmediatas()
{
    Grafo G;
    CrearGrafo(G);

    // 0 y 1 son previas inmediatas de 2
    AgregarArista(G, 0, 2);
    AgregarArista(G, 1, 2);

    int pre[MAX_ASIGNATURAS];
    int cantPre = 0;
    PreviasInmediatas(G, 2, pre, cantPre);

    assert(cantPre == 2);
    assert(ContieneValor(pre, cantPre, 0) == TRUE);
    assert(ContieneValor(pre, cantPre, 1) == TRUE);
}

void TestTodasLasPrevias()
{
    Grafo G;
    CrearGrafo(G);

    // Cadena: 0 -> 1 -> 2 -> 3
    AgregarArista(G, 0, 1);
    AgregarArista(G, 1, 2);
    AgregarArista(G, 2, 3);

    int previas[MAX_ASIGNATURAS];
    int cantPrevias = 0;
    TodasLasPrevias(G, 3, previas, cantPrevias);

    assert(cantPrevias == 3);
    assert(ContieneValor(previas, cantPrevias, 0) == TRUE);
    assert(ContieneValor(previas, cantPrevias, 1) == TRUE);
    assert(ContieneValor(previas, cantPrevias, 2) == TRUE);
}

void TestGrafo()
{
    TestCrearGrafo();
    TestAgregarArista();
    TestExisteCamino();
    TestPreviasInmediatas();
    TestTodasLasPrevias();
}
