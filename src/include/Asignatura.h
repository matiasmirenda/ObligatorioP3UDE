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

// Lee por teclado los datos de una asignatura y la crea
// Precondición: todos los datos se ingresan de forma correcta
void CargarAsignatura(Asignatura &a);

// Devuelve el nombre de la asignatura
String DarNombreAsignatura(Asignatura a);

// Devuelve el numero de la asignatura
int DarNumeroAsignatura(Asignatura a);

// Devuelve la cantidad de horas de la asignatura
int DarCantidadHorasAsignatura(Asignatura a);

// Devuelve TRUE si la asignatura es optativa o FALSE en caso contrario
Boolean EsAsignaturaOptativa(Asignatura a);

// Asigna un numero a una asignatura
void AsignarNumeroAsignatura(
    Asignatura &a,
    int numero);

// Despliega por pantalla una asignatura
void MostrarAsignatura(Asignatura a);

#endif