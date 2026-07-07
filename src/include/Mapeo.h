#ifndef MAPEO_H_INCLUDED
#define MAPEO_H_INCLUDED

#include "Boolean.h"
#include "Asignatura.h"

const int TAMANIO = 30;

typedef Asignatura T;

typedef struct
{
    Boolean existe;
    T info;
} Celda;

typedef Celda Mapeo[TAMANIO];

// Crea un mapeo vacío.
void Crear(Mapeo &m);

// Devuelve TRUE si existe un elemento en la posición indicada.
Boolean Pertenece(Mapeo m, int pos);

// Inserta un elemento en la posición indicada.
// Precondición: !Pertenece(m, pos)
void Insertar(Mapeo &m, T e, int pos);

// Devuelve el elemento almacenado en la posición indicada.
// Precondición: Pertenece(m, pos)
T Obtener(Mapeo m, int pos);

// Elimina el elemento almacenado en la posición indicada.
// Precondición: Pertenece(m, pos)
void Eliminar(Mapeo &m, int pos);

#endif