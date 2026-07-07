#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include "Boolean.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

// Crea una fecha con los valores indicados.
Fecha CrearFecha(int dia, int mes, int anio);

// Carga una fecha ingresada por teclado.
void CargarFecha(Fecha &f);

// Devuelve TRUE si el año de la fecha es bisiesto.
Boolean EsBisiesto(Fecha f);

// Muestra una fecha por pantalla.
void DarFecha(Fecha f);

// Devuelve TRUE si ambas fechas son iguales.
Boolean EsMismaFecha(Fecha f1, Fecha f2);

// Devuelve TRUE si f1 es posterior a f2.
Boolean EsFechaMayor(Fecha f1, Fecha f2);

// Devuelve TRUE si la fecha es válida.
Boolean EsFechaValida(Fecha f);

#endif