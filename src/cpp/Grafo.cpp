#include "Grafo.h"

void CrearGrafo(Grafo &G)
{
    for (int i = 0; i < MAX_ASIGNATURAS; i++)
        for (int j = 0; j < MAX_ASIGNATURAS; j++)
            G[i][j] = 0;
}

void AgregarArista(Grafo &G, int u, int v)
{
    G[u][v] = 1;
}

Boolean HayArista(Grafo G, int u, int v){
    Boolean hay = FALSE;

    if (G[u][v] == 1)
        hay = TRUE;

    return hay;
}

// Operacion auxiliar: recorrida DFS a partir de "actual", marcando
// visitados, hasta encontrar "destino" o agotar el grafo.
void DFS_Camino(Grafo G, int actual, int destino, Boolean visitado[MAX_ASIGNATURAS])
{
    visitado[actual] = TRUE;
    int j = 0;
    while (j < MAX_ASIGNATURAS && !visitado[destino])
    {
        if (G[actual][j] && !visitado[j])
            DFS_Camino(G, j, destino, visitado);
        j++;
    }
}

Boolean ExisteCamino(Grafo G, int origen, int destino)
{
    Boolean visitado[MAX_ASIGNATURAS];
    for (int i = 0; i < MAX_ASIGNATURAS; i++)
        visitado[i] = FALSE;

    
    visitado[origen] = TRUE;
    int j = 0;
    while (j < MAX_ASIGNATURAS && !visitado[destino])
    {
        if (G[origen][j] && !visitado[j])
            DFS_Camino(G, j, destino, visitado);
        j++;
    }
    return visitado[destino];
}

void PreviasInmediatas(Grafo G, int v, int pre[], int &cantPre){
    cantPre = 0;
    for (int u = 0; u < MAX_ASIGNATURAS; u++)
    {
        if (G[u][v])
        {
            pre[cantPre] = u;
            cantPre++;
        }
    }
}

// Operacion auxiliar: recorrida DFS "hacia atras" (sobre el grafo
// transpuesto) a partir de "actual", acumulando en previas[] todos
// los vertices desde los que se puede llegar a "actual".
 void DFS_Previas(Grafo G, int actual, Boolean visitado[MAX_ASIGNATURAS],
                        int previas[], int &cantPrevias)
{
    for (int w = 0; w < MAX_ASIGNATURAS; w++)
    {
        if (G[w][actual] && !visitado[w])
        {
            visitado[w] = TRUE;
            previas[cantPrevias] = w;
            cantPrevias++;
            DFS_Previas(G, w, visitado, previas, cantPrevias);
        }
    }
}

void TodasLasPrevias(Grafo G, int v, int previas[], int &cantPrevias)
{
    Boolean visitado[MAX_ASIGNATURAS];
    for (int i = 0; i < MAX_ASIGNATURAS; i++)
        visitado[i] = FALSE;

    cantPrevias = 0;
    DFS_Previas(G, v, visitado, previas, cantPrevias);
}
