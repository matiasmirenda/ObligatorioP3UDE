#include "Escolaridad.h"

// ============================================================
// PLACEHOLDER - Escolaridad.cpp
// ============================================================

void CrearEscolaridad(Escolaridad &E)
{
    E.cantidad = 0;
}

void AgregarCurso(Escolaridad &E, Curso c)
{
    E.cursos[E.cantidad] = c;
    E.cantidad++;
}

int CantidadCursos(Escolaridad E)
{
    return E.cantidad;
}

int CantidadCursosAprobados(Escolaridad E)
{
    int cant = 0;
    for (int i = 0; i < E.cantidad; i++)
        if (E.cursos[i].aprobado == TRUE)
            cant++;
    return cant;
}

Boolean TieneAsignaturaAprobada(Escolaridad E, int numeroAsignatura)
{
    Boolean tiene = FALSE;
    int i = 0;
    while (i < E.cantidad && !tiene)
    {
        if (E.cursos[i].numeroAsignatura == numeroAsignatura && E.cursos[i].aprobado == TRUE)
            tiene = TRUE;
        i++;
    }
    return tiene;
}