#ifndef ASIGNATURAS_H_INCLUDED
#define ASIGNATURAS_H_INCLUDED

#include "Mapeo.h"

typedef struct
{
    Mapeo datos;
    int cantidad;
} Asignaturas;

// Crea una colección vacía de asignaturas
void CrearAsignaturas(Asignaturas &asignaturas);

// Devuelve TRUE si existe una asignatura con el número indicado o FALSE en caso contrario
Boolean ExisteAsignatura(Asignaturas asignaturas, int numero);

// Registra una nueva asignatura asignándole automáticamente el siguiente número disponible
// Precondición: La asignatura fue creada correctamente y hay espacio para agregarla (asignaturas.cantidad < TAMANIO)
void RegistrarAsignatura(Asignaturas &asignaturas, Asignatura a);

// Devuelve la asignatura correspondiente al número indicado
// Precondición: ExisteAsignatura(asignaturas, numero)
Asignatura ObtenerAsignatura(Asignaturas asignaturas, int numero);

// Devuelve la cantidad de asignaturas registradas
int CantidadAsignaturas(Asignaturas asignaturas);

// Lista todas las asignaturas
void ListarAsignaturas(Asignaturas asignaturas);

#endif