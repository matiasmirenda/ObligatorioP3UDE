#ifndef ASIGNATURAS_H_INCLUDED
#define ASIGNATURAS_H_INCLUDED

#include "Mapeo.h"

typedef struct
{
    Mapeo datos;
    int cantidad;
} Asignaturas;

// Crea una colección vacía de asignaturas.
void CrearAsignaturas(Asignaturas &asignaturas);

// Devuelve TRUE si existe una asignatura con el número indicado.
Boolean ExisteAsignatura(Asignaturas asignaturas, int numero);

// Precondición:
// - La asignatura fue creada correctamente.
// - asignaturas.cantidad < TAMANIO
// Registra una nueva asignatura asignándole automáticamente el
// siguiente número disponible.
void RegistrarAsignatura(Asignaturas &asignaturas, Asignatura a);

// Precondición: ExisteAsignatura(asignaturas, numero)
// Devuelve la asignatura correspondiente al número indicado.
Asignatura ObtenerAsignatura(Asignaturas asignaturas, int numero);

// Devuelve la cantidad de asignaturas registradas.
int CantidadAsignaturas(Asignaturas asignaturas);

#endif