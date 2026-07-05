#ifndef FECHA_H
#define FECHA_H

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

Fecha CrearFecha(int dia, int mes, int anio);

bool EsBisiesto(Fecha f);

#endif