#include "Mapeo.h"

void Crear(Mapeo &m)
{
    int i;
    m.cantidad = 0;
    for (i = 0; i < TAM; i++)
    {
        m.celdas[i].existe = FALSE;
    }
}

Boolean Pertenece(Mapeo m, int pos)
{
    return m.celdas[pos].existe;
}

void Insertar(Mapeo &m, Asignatura e)
{
    m.celdas[m.cantidad].existe = TRUE;
    m.celdas[m.cantidad].info = e;

    m.cantidad++;
}

Asignatura Obtener(Mapeo m, int pos)
{
    return m.celdas[pos].info;
}

int CantidadRegistradas(Mapeo m)
{
    return m.cantidad;
}