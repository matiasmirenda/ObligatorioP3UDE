#include "../include/Curso.h"
#include <stdio.h>

void CargarCurso(Curso &c)
{
    printf("Numero de asignatura: ");
    scanf("%d", &c.numeroAsignatura);

    printf("Fecha de finalizacion:\n");
    CargarFecha(c.fechaFinalizacion);

    printf("Calificacion final: ");
    scanf("%d", &c.calificacion);
}

int DarNumeroAsignaturaCurso(Curso c)
{
    return c.numeroAsignatura;
}

Fecha DarFechaFinalizacionCurso(Curso c)
{
    return c.fechaFinalizacion;
}

int DarCalificacionCurso(Curso c)
{
    return c.calificacion;
}

Boolean CursoAprobado(Curso c)
{
    Boolean aprobado = FALSE;

    if (c.calificacion >= 6)
        aprobado = TRUE;

    return aprobado;
}

int numeroAsignatura;
Fecha fechaFinalizacion;
int calificacion;

void MostrarCurso(Curso c)
{
    printf("\n  Curso %d\n", c.numeroAsignatura);
    printf("\nFecha: ");
    DarFecha(c.fechaFinalizacion);
    printf("\n Calificacion: %d", c.calificacion);
}