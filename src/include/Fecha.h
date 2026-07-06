#ifndef FECHA_H
#define FECHA_H
#include "Boolean.h"

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

// ‼️TODO: Cambiar bool por Boolean cuando este el módlo

// Carga una fecha inresada por teclado
void CargarFecha(Fecha &f);

// Muestra por pantalla una fecha
void DarFecha(Fecha f);

// Devuelve TRUE si ambas fechas son iguales o FALSE en caso contrario
bool EsMismaFecha(Fecha f1, Fecha f2);

// Devuelve TRUE si la fecha f1 es mayor que la fecha f2 o FALSE en caso contrario
bool EsFechaMayor(Fecha f1, Fecha f2);

// Devuelve TRUE si la fecha ingresada es válida o FALSE en caso contrario
bool EsFechaValida(Fecha f1);

#endif