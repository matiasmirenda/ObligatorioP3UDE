#include "Curso.h"
#include <stdio.h>

void CargarCurso(Curso &c)
{
    printf("Numero de asignatura: ");
    scanf("%d", &c.numeroAsignatura);

    printf("Fecha de finalizacion:\n");
    CargarFecha(c.fechaFinalizacion);

    while (!EsFechaValida(c.fechaFinalizacion))
    {
        printf("Ingrese una fecha valida: ");
        CargarFecha(c.fechaFinalizacion);
    }

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

    if (c.calificacion >= NOTA_APROBACION)
        aprobado = TRUE;

    return aprobado;
}

void MostrarCurso(Curso c, Asignaturas asignaturas)
{
    printf("\n\nFecha: ");
    DarFecha(DarFechaFinalizacionCurso(c));
    printf("\n Curso %d", c.numeroAsignatura);
    printf("\n Nombre: ");
    print(DarNombreAsignatura(ObtenerAsignatura(asignaturas, DarNumeroAsignaturaCurso(c))));
    printf("\n Calificacion: %d", DarCalificacionCurso(c));
    printf("\n Aprobada: ");
    Desplegar(CursoAprobado(c));
}