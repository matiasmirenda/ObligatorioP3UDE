#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED

#include "Fecha.h"
#include "Asignaturas.h"

typedef struct
{
    int numeroAsignatura;
    Fecha fechaFinalizacion;
    int calificacion;
} Curso;

// Carga por teclado los datos de un curso
void CargarCurso(Curso &c);

// Devuelve el número de asignatura del curso
int DarNumeroAsignaturaCurso(Curso c);

// Devuelve la fecha de finalización del curso
Fecha DarFechaFinalizacionCurso(Curso c);

// Devuelve la calificación final del curso
int DarCalificacionCurso(Curso c);

// Devuelve TRUE si el curso está aprobado O FALSE en caso contrario
Boolean CursoAprobado(Curso c);

// Muestra un curso por pantalla
// Precondición: el curso existe
void MostrarCurso(Curso c, Asignaturas asignaturas);

#endif