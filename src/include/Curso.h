#ifndef CURSO_H
#define CURSO_H
#include "Fecha.h"

typedef struct
{
    int asignatura;
    Fecha fechaFin;
    int nota;

} Curso;

// Devuelve el numero de la asignatura
int ObtenerNumAsignatura(Curso c);

// Devuelve la nota de la asignatura
int ObtenerCalificacion(Curso c);

#endif