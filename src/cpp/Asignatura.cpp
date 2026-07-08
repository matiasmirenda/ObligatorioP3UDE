#include "../include/Asignatura.h"

void CargarAsignatura(Asignatura &a)
{

    printf("Nombre: ");
    strcrear(a.nombre);
    scan(a.nombre);

    printf("Cantidad de horas: ");
    scanf("%d", &a.cantidadHoras);

    int op;
    printf("Es optativa? (0 = No, 1 = Si): ");
    scanf("%d", &op);

    if (op == 0)
        a.esOptativa = FALSE;
    else
        a.esOptativa = TRUE;
}

String DarNombreAsignatura(Asignatura a)
{
    return a.nombre;
}

int DarCantidadHorasAsignatura(Asignatura a)
{
    return a.cantidadHoras;
}

Boolean EsAsignaturaOptativa(Asignatura a)
{
    return a.esOptativa;
}