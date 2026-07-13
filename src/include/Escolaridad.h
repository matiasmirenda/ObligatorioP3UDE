#ifndef ESCOLARIDAD_H
#define ESCOLARIDAD_H

#include "Lista.h"

const int NOTA_APROBACION = 6;

typedef struct Escolaridad
{
    Lista cursos;
} Escolaridad;

// Crea una escolaridad vacía
void Crear(Escolaridad &e);

// Devuelce true si la escolaridad esta vacía, FALSE en caso contrario
Boolean EsVacia(Escolaridad e);

// Devuelve la cantidad de cursos registrados en la escolaridad
int Largo(Escolaridad e);

// Agrega un nuevo curso al final de la escolaridad
// Precondición 1: La escolaridad esta vacia y c es un curso exitente, o se cumple la precondición 2
// Precondición 2: c es un curso existente y su fecha de finaliación es igual o posterior a la del ultimo curso en la escolaridad
void InsBack(Escolaridad &e, Curso c);

// Devuelve el ultimo curso
// Precondición: La escolaridad no esta vacia
Curso Ultimo(Escolaridad e);

// Devuelve el curso que ocupa la posición k en orden cronológico
// Precondición: k es mayor a 0 y menor al largo de la escolaridad
Curso KEsimo(Escolaridad e, int k);

// Devuelve TRUE si la asignatura fue aproba (calificación >= NOTA_APROBACION) o FASLE en caso contrario
// Precondición: existe la asignatura
Boolean AsignaturaAprobada(Escolaridad e, int numAsignatura);

// Devuelve la cantidad de cursos aprobados (calificacion >= NOTA_APROBACION) registrados en la escolaridad.
int CantidadAprobados(Escolaridad e);

// Devuelve la cantidad de cursos registrados en la escolaridad.
int CantidadCursosEscolaridad(Escolaridad e);

// Muestra una escolaridad por pantalla
void MostrarEscolaridad(Escolaridad e, Asignaturas asignaturas);

#endif