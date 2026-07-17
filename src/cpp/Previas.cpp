#include "Previas.h"

void CrearPreviaturas(Previaturas &P)
{
    CrearGrafo(P);
}

Boolean AgregarPrevia(Previaturas &P, int u, int v)
{

    if (u == v)
        return FALSE;

    if (ExisteCamino(P, v, u))
        return FALSE;

    AgregarArista(P, u, v);
    return TRUE;
}

void PreviasInmediatasDe(Previaturas P, int v, int pre[], int &cantPre)
{
    PreviasInmediatas(P, v, pre, cantPre);
}

void PreviasDe(Previaturas P, int v, int previas[], int &cantPrevias)
{
    TodasLasPrevias(P, v, previas, cantPrevias);
}