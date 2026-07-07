#include "../include/Mapeo.h"

void Crear(Mapeo &m)
{
    int i;

    for (i = 0; i < TAMANIO; i++)
        m[i].existe = FALSE;
}

Boolean Pertenece(Mapeo m, int pos)
{
    return m[pos].existe;
}

void Insertar(Mapeo &m, T e, int pos)
{
    m[pos].existe = TRUE;
    m[pos].info = e;
}

T Obtener(Mapeo m, int pos)
{
    return m[pos].info;
}

void Eliminar(Mapeo &m, int pos)
{
    m[pos].existe = FALSE;
}