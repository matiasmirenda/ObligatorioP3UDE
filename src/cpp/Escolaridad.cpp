#include "Escolaridad.h"

void Crear(Escolaridad &e)
{
    Crear(e.cursos);
}

Boolean EsVacia(Escolaridad e)
{
    return EsVacia(e.cursos);
}

void InsBack(Escolaridad &e, Curso c)
{
    InsBack(e.cursos, c);
}

Curso Ultimo(Escolaridad e)
{
    return Ultimo(e.cursos);
}

Boolean AsignaturaAprobada(Escolaridad e, int numAsignatura)
{
    NodoLista *aux = e.cursos.prim;
    Boolean encontrada = FALSE;

    while (aux != NULL && !encontrada)
    {
        Curso c = aux->info;

        if (DarNumeroAsignaturaCurso(c) == numAsignatura &&
            CursoAprobado(c))
        {
            encontrada = TRUE;
        }

        aux = aux->sig;
    }

    return encontrada;
}

int CantidadAprobados(Escolaridad e)
{
    int cant = 0;

    NodoLista *aux = e.cursos.prim;

    while (aux != NULL)
    {
        if (CursoAprobado(aux->info))
            cant++;

        aux = aux->sig;
    }

    return cant;
}

int CantidadCursosEscolaridad(Escolaridad e)
{
    return Largo(e.cursos);
}

void MostrarEscolaridad(Escolaridad e, Asignaturas asignaturas)
{
    printf("\n  ESCOLARIDAD DEL ALUMNO");
    printf("\n--------------------------");

    NodoLista *aux = e.cursos.prim;

    while (aux != NULL)
    {
        MostrarCurso(aux->info, asignaturas);
        aux = aux->sig;
    }
}