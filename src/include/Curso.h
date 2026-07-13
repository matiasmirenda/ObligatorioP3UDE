#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED

#include "Boolean.h"
#include "Fecha.h"

typedef struct
{
    int numeroAsignatura;
    Fecha fechaFinalizacion;
    int calificacion;
} Curso;

// Carga por teclado los datos de un curso.
void CargarCurso(Curso &c);

// Devuelve el número de asignatura del curso.
int DarNumeroAsignaturaCurso(Curso c);

// Devuelve la fecha de finalización del curso.
Fecha DarFechaFinalizacionCurso(Curso c);

// Devuelve la calificación final del curso.
int DarCalificacionCurso(Curso c);

// Devuelve TRUE si el curso está aprobado.
Boolean CursoAprobado(Curso c);

// Muestra un curso por pantalla
void MostrarCurso(Curso c);

#endif