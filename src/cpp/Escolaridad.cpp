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
    int i = 1, largo = Largo(e.cursos);

    while (i <= largo && !encontrada)
    {
        Curso c = KEsimo(e.cursos, i);
        if (DarNumeroAsignaturaCurso(c) == numAsignatura &&
            DarCalificacionCurso(c) >= NOTA_APROBACION)
            encontrada = TRUE;
        i++;
    }
    return encontrada;
}

int CantidadAprobados(Escolaridad e)
{
    int cant = 0, i;
    int largo = Largo(e.cursos);

    for (i = 1; i <= largo; i++)
    {
        Curso c = KEsimo(e.cursos, i);
        if (DarCalificacionCurso(c) >= NOTA_APROBACION)
            cant++;
    }
    return cant;
}

int CantidadCursosEscolaridad(Escolaridad e)
{
    return Largo(e.cursos);
}

void MostrarEscolaridad(Escolaridad e, Asignaturas asignaturas)
{
    int k, largo = CantidadCursosEscolaridad(e);
    printf("\n  ESCOLARIDAD DEL ALUMNO");
    printf("\n--------------------------");

    for (k = 1; k <= largo; k++)
    {
        MostrarCurso(KEsimo(e, k), asignaturas);
    }
}
