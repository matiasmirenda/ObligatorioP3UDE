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
    AsignarNumeroAsignatura(a, CantidadAsignaturas(asignaturas));
    Insertar(asignaturas.datos, a);
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

void ListarAsignaturas(Asignaturas asignaturas)
{
    if (asignaturas.cantidad == 0)
    {
        printf("No hay asignaturas registradas");
    }
    else
    {
        ListarAsignaturasMapeo(asignaturas.datos, asignaturas.cantidad);
    }
}