#include "Mapeo.h"

void CopiarAsignatura(Asignatura origen, Asignatura &destino)
{
    strcrear(destino.nombre);
    strcop(destino.nombre, DarNombreAsignatura(origen));
    destino.numero = DarNumeroAsignatura(origen);
    destino.cantidadHoras = DarCantidadHorasAsignatura(origen);
    destino.esOptativa = EsAsignaturaOptativa(origen);
}

void Crear(Mapeo &m)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        m.celdas[i].existe = FALSE;
    }
}

Boolean Pertenece(Mapeo m, int pos)
{
    return m.celdas[pos].existe;
}

void Insertar(Mapeo &m, Asignatura e, int pos)
{
    m.celdas[pos].existe = TRUE;
    m.celdas[pos].info = e;
}

Asignatura Obtener(Mapeo m, int pos)
{
    Asignatura copia;
    CopiarAsignatura(m.celdas[pos].info, copia);
    return copia;
}

void ListarAsignaturasMapeo(Mapeo m, int cant)
{
    int i;
    for (i = 0; i < cant; i++)
    {
        MostrarAsignatura(m.celdas[i].info);
    }
}
