#include "EstadoOperacion.h"
#include <stdio.h>

void MostrarEstadoOperacion(EstadoOperacion estado)
{
    switch (estado)
    {
    case OK:
        printf("Operacion realizada correctamente.\n");
        break;

    case MAXIMO_ASIGNATURAS_ALCANZADO:
        printf("Error: se alcanzo el maximo de asignaturas.\n");
        break;

    case ASIGNATURA1_NO_EXISTE:
        printf("Error: la asignatura previa no existe.\n");
        break;

    case ASIGNATURA2_NO_EXISTE:
        printf("Error: la asignatura no existe.\n");
        break;
    case ALUMNO_YA_EXISTE:
        printf("Error: el alumno ya existe.\n");
        break;

    case ALUMNO_NO_EXISTE:
        printf("Error: el alumno no existe.\n");
        break;

    case MISMA_ASIGNATURA:
        printf("Error: una asignatura no puede ser previa de si misma.\n");
        break;

    case PREVIATURA_GENERA_CICLO:
        printf("Error: la previatura genera un ciclo.\n");
        break;

    case ASIGNATURA_YA_APROBADA:
        printf("Error: el alumno ya aprobo esa asignatura.\n");
        break;

    case PREVIAS_NO_APROBADAS:
        printf("Error: el alumno no tiene aprobadas todas las previas.\n");
        break;

    case FECHA_INVALIDA:
        printf("Error: la fecha es invalida.\n");
        break;

    case FECHA_ANTERIOR_ULTIMO_CURSO:
        printf("Error: la fecha es anterior al ultimo curso registrado.\n");
        break;

    case CALIFICACION_INVALIDA:
        printf("Error: la calificacion debe estar entre 0 y 12.\n");
        break;

    default:
        printf("Error desconocido.\n");
        break;
    }
}