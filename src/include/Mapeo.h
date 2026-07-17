#ifndef MAPEO_H
#define MAPEO_H

#include "Asignatura.h"

const int TAM = 30;

typedef struct
{
    Boolean existe;
    Asignatura info;
} Celda;

typedef struct
{
    Celda celdas[TAM];
} Mapeo;

// Crea un mapeo vacío
void Crear(Mapeo &m);

// Determina si existe una asignatura registrada en la posición pos.
// Precondición: pos mayor que 0 y menor a TAM
Boolean Pertenece(Mapeo m, int pos);

// Registra la asignatura e en la siguiente posicion libre del mapeo.
void Insertar(Mapeo &m, Asignatura e, int pos);

// Devuelve la asignatura registrada en la posición pos.
// Precondición: en pos existe una asignatura registrada
Asignatura Obtener(Mapeo m, int pos);

// Lista todos los elementos existentes en el mapeo
void ListarAsignaturasMapeo(Mapeo m, int cant);

#endif