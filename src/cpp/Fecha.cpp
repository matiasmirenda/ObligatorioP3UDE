#include "../include/Fecha.h"

Fecha CrearFecha(int dia, int mes, int anio)
{
    Fecha f;
    f.dia = dia;
    f.mes = mes;
    f.anio = anio;
    return f;
}

bool EsBisiesto(Fecha f)
{
    return (f.anio % 4 == 0);
}