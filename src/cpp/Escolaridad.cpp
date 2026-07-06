#include "Escolaridad.h"

void Crear(Escolaridad &e)
{
    Crear(e.cursos);
}

Boolean EsVacia(Escolaridad e)
{
    return EsVacia(e.cursos);
}

int Largo(Escolaridad e)
{
    return Largo(e.cursos);
}

void InsBack(Escolaridad &e, Curso c)
{
    InsBack(e.cursos, c);
}

Curso Ultimo(Escolaridad e)
{
    return Ultimo(e.cursos);
}

Curso KEsimo(Escolaridad e, int k)
{
    return KEsimo(e.cursos, k);
}

Boolean AsignaturaAprobada(Escolaridad e, int numAsignatura)
{
    Boolean encontrada = FALSE;
    int i = 1;

    while (i <= Largo(e.cursos) && !encontrada)
    {
        Curso c = KEsimo(e.cursos, i);
        if (ObtenerNumAsignatura(c) == numAsignatura &&
            ObtenerCalificacion(c) >= NOTA_APROBACION)
            encontrada = TRUE;
        i++;
    }
    return encontrada;
}

int CantidadAprobados(Escolaridad e)
{
    int cant = 0, i;

    for (i = 1; i <= Largo(e.cursos); i++)
    {
        Curso c = KEsimo(e.cursos, i);
        if (ObtenerCalificacion(c) >= NOTA_APROBACION)
            cant++;
    }
    return cant;
}