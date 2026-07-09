#ifndef ESCOLARIDAD_H
#define ESCOLARIDAD_H
#include "Boolean.h"
#include "Curso.h"
#include "Lista.h"

const int NOTA_APROBACION = 6;

typedef struct Escolaridad
{
    Lista cursos;
} Escolaridad;

// Crea una escolaridad vacía.
void Crear(Escolaridad &e);

// Determina si la escolaridad no tiene cursos registrados.
Boolean EsVacia(Escolaridad e);

// Devuelve la cantidad de cursos registrados en la escolaridad.
int Largo(Escolaridad e);

// Agrega un nuevo curso al final de la escolaridad.
// Precondición: La escolaridad esta vacia o la fecha de c es posterior o igual a la fecha de Ultimo(e)
void InsBack(Escolaridad &e, Curso c);

// Devuelve el ultimo curso
// Precondición: La escolaridad no esta vacia
Curso Ultimo(Escolaridad e);

// Devuelve el curso que ocupa la posición k en orden cronológico
Curso KEsimo(Escolaridad e, int k);

// Devuelve TRUE si la asignatura fue aproba (calificación >= NOTA_APROBACION) o FASLE en caso contrario
Boolean AsignaturaAprobada(Escolaridad e, int numAsignatura);

// Devuelve la cantidad de cursos aprobados (calificacion >= NOTA_APROBACION) registrados en la escolaridad.
int CantidadAprobados(Escolaridad e);

// Devuelve la cantidad de cursos registrados en la escolaridad.
int CantidadCursosEscolaridad(Escolaridad e);

#endif