#include "Menu.h"
#include "EstadoOperacion.h"

#include <stdio.h>

void MostrarMenu()
{
    printf("\n");
    printf("=====================================\n");
    printf("          ACADEMIA DE MODA\n");
    printf("=====================================\n");
    printf("1. Registrar una nueva asignatura\n");
    printf("2. Agregar una previatura\n");
    printf("3. Inscribir un nuevo alumno\n");
    printf("4. Registrar un curso\n");
    printf("5. Listar todas las asignaturas\n");
    printf("6. Listar previas de una asignatura\n");
    printf("7. Mostrar datos de un alumno\n");
    printf("8. Mostrar escolaridad de un alumno\n");
    printf("0. Salir\n");
    printf("=====================================\n");
    printf("Ingrese una opcion: ");
}

void OpcionRegistrarAsignatura(Academia &academia)
{
    Asignatura asignatura;

    printf("\n--- Registrar asignatura ---\n");

    CargarAsignatura(asignatura);

    EstadoOperacion estado =
        RegistrarNuevaAsignatura(
            academia,
            asignatura);

    MostrarEstadoOperacion(estado);
}

void OpcionRegistrarPreviatura(Academia &academia)
{
    int numeroPrevia;
    int numeroAsignatura;

    printf("\n--- Registrar previatura ---\n");

    printf("Numero de la asignatura previa: ");
    scanf("%d", &numeroPrevia);

    printf("Numero de la asignatura: ");
    scanf("%d", &numeroAsignatura);

    EstadoOperacion estado =
        RegistrarPreviatura(
            academia,
            numeroPrevia,
            numeroAsignatura);

    MostrarEstadoOperacion(estado);
}

void OpcionListarAsignaturas(Academia academia)
{
    printf("\n--- Listar asignaturas ---\n");
    ListarAsignaturas(academia.asignaturas);
}

void OpcionListarPrevias(Academia academia)
{
    int numeroAsignatura;

    printf("\n--- Listar previas ---\n");

    printf("Numero de asignatura: ");
    scanf("%d", &numeroAsignatura);

    ListarPreviasAcademia(
        academia,
        numeroAsignatura);
}

void OpcionMostrarAlumno(Academia academia)
{
    long int ci;
    printf("\n--- Listar alumno ---\n");

    printf("Documento del alumno a listar: ");
    scanf("%ld", &ci);

    MostrarAlumno(academia.alumnos, ci);
}

void EjecutarMenu(Academia &academia)
{
    int opcion;

    do
    {
        printf("\n \n");
        MostrarMenu();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            OpcionRegistrarAsignatura(academia);
            break;

        case 2:
            OpcionRegistrarPreviatura(academia);
            break;

        case 3:
            // TODO
            break;

        case 4:
            // TODO
            break;

        case 5:
            OpcionListarAsignaturas(academia);
            break;

        case 6:
            OpcionListarPrevias(academia);
            break;

        case 7:
            OpcionMostrarAlumno(academia);
            break;

        case 8:
            // JOHA
            break;

        case 0:
            printf("\nFin del programa.\n");
            break;

        default:
            printf("\nOpcion invalida.\n");
            break;
        }

    } while (opcion != 0);
}