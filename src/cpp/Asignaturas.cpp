#include "../include/Asignaturas.h"

void CrearAsignaturas(Asignaturas &asignaturas)
{
    Crear(asignaturas.datos);
    asignaturas.cantidad = 0;
}

Boolean ExisteAsignatura(Asignaturas asignaturas, int numero)
{
    Boolean existe = FALSE;

    if (numero >= 0 && numero < asignaturas.cantidad)
        existe = Pertenece(asignaturas.datos, numero);

    return existe;
}

void RegistrarAsignatura(Asignaturas &asignaturas, Asignatura a)
{
    Insertar(asignaturas.datos, a, asignaturas.cantidad);
    asignaturas.cantidad++;
}

Asignatura ObtenerAsignatura(Asignaturas asignaturas, int numero)
{
    return Obtener(asignaturas.datos, numero);
}

int CantidadAsignaturas(Asignaturas asignaturas)
{
    return asignaturas.cantidad;
}