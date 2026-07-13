#include "Menu.h"
#include "EstadoOperacion.h"

#include <stdio.h>

void MostrarMenu()
{
    printf("\n");
    printf("=====================================\n");
    printf("          ACADEMIA DE MODA\n");
    printf("=====================================\n");
    printf("1. Registrar una nueva asignatura\n"); // OK
    printf("2. Agregar una previatura\n");         // OK
    printf("3. Inscribir un nuevo alumno\n");
    printf("4. Registrar un curso\n");
    printf("5. Listar todas las asignaturas\n");     // OK
    printf("6. Listar previas de una asignatura\n"); // OK
    printf("7. Mostrar datos de un alumno\n");
    printf("8. Mostrar escolaridad de un alumno\n");
    printf("0. Salir\n");
    printf("=====================================\n");
    printf("Ingrese una opcion: ");
}

void OpcionRegistrarAsignatura(Academia &academia) // Op. 1
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

void OpcionRegistrarPreviatura(Academia &academia) // Op. 2
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

void OpcionListarAsignaturas(Academia academia) // Op. 5
{
    printf("\n--- Listar asignaturas ---\n");
    ListarAsignaturas(academia.asignaturas);
}

void OpcionListarPrevias(Academia academia) // Op. 6
{
    int numeroAsignatura;

    printf("\n--- Listar previas ---\n");

    printf("Numero de asignatura: ");
    scanf("%d", &numeroAsignatura);

    ListarPreviasAcademia(
        academia,
        numeroAsignatura);
}

void EjecutarMenu(Academia &academia)
{
    int opcion;

    do
    {
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
            // TODO
            break;

        case 6:
            OpcionListarPrevias(academia);
            break;

        case 7:
            // TODO
            break;

        case 8:
            // TODO
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