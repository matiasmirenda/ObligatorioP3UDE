#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED

#include "String.h"

typedef struct
{
    String nombre;
    int cantidadHoras;
    int numero;
    Boolean esOptativa;
} Asignatura;

// Lee por teclado los datos de una asignatura y la crea.
void CargarAsignatura(Asignatura &a);

// Devuelve el nombre de la asignatura.
String DarNombreAsignatura(Asignatura a);

// Devuelve el numero de la asignatura.
int DarNumeroAsignatura(Asignatura a);

// Devuelve la cantidad de horas de la asignatura.
int DarCantidadHorasAsignatura(Asignatura a);

// Devuelve TRUE si la asignatura es optativa.
Boolean EsAsignaturaOptativa(Asignatura a);

// Asigna un numero de asignatura a la misma.
void AsignarNumeroAsignatura(
    Asignatura &a,
    int numero);
#endif