#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include "Boolean.h"

typedef struct
{
    int numero;
    int nombre;
    int cantHoras;
    Boolean optativa;
} Asignatura;

Asignatura ArmarAsignatura(int numero, int nombre, int cantHoras, bool optativa);
int ObtenerNumero(Asignatura a);
int ObtenerNombre(Asignatura a);
int ObtenerCantHoras(Asignatura a);
bool EsOptativa(Asignatura a);

#endif