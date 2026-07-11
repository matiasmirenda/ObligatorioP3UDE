#include "Academia.h"
#include <stdio.h>

void CrearAcademia(Academia &academia)
{
    CrearAsignaturas(academia.asignaturas);
    CrearAlumnos(academia.alumnos);
    CrearPreviaturas(academia.previaturas);
}

// Requerimiento 1
EstadoOperacion RegistrarNuevaAsignatura(
    Academia &academia,
    Asignatura asignatura)
{
    EstadoOperacion estado;

    if (CantidadAsignaturas(academia.asignaturas) >= MAX_ASIGNATURAS)
    {
        estado = MAXIMO_ASIGNATURAS_ALCANZADO;
    }
    else
    {

        RegistrarAsignatura(academia.asignaturas, asignatura);
        estado = OK;
    }

    return estado;
}

// Requerimiento 2
EstadoOperacion RegistrarPreviatura(
    Academia &academia,
    int numeroPrevia,
    int numeroAsignatura)
{
    EstadoOperacion estado;

    if (!ExisteAsignatura(academia.asignaturas, numeroPrevia))
    {
        estado = ASIGNATURA1_NO_EXISTE;
    }
    else if (!ExisteAsignatura(academia.asignaturas, numeroAsignatura))
    {
        estado = ASIGNATURA2_NO_EXISTE;
    }
    else if (numeroPrevia == numeroAsignatura)
    {
        estado = MISMA_ASIGNATURA;
    }
    else if (!AgregarPrevia(
                 academia.previaturas,
                 numeroPrevia,
                 numeroAsignatura))
    {
        estado = PREVIATURA_GENERA_CICLO;
    }
    else
    {
        estado = OK;
    }

    return estado;
}

// Requerimiento 3
EstadoOperacion InscribirNuevoAlumno(
    Academia &academia,
    Alumno alumno)
{
    // TODO: implementar inscripción de alumno.
}

// Requerimiento 4
EstadoOperacion RegistrarCursoAcademia(
    Academia &academia,
    long int cedula,
    int numeroAsignatura,
    Fecha fechaFinalizacion,
    int calificacion)
{
    // TODO: implementar registro de curso.
}

// Requerimiento 5
void ListarAsignaturasAcademia(Academia academia)
{
    // TODO: implementar listado de asignaturas.
}

// Requerimiento 6
void ListarPreviasAcademia(
    Academia academia,
    int numeroAsignatura)
{
    if (!ExisteAsignatura(
            academia.asignaturas,
            numeroAsignatura))
    {
        printf("Asignatura no existe");
    }
    else
    {
        int previas[MAX_ASIGNATURAS - 1];
        int cantPrevias;

        PreviasDe(
            academia.previaturas,
            numeroAsignatura,
            previas,
            cantPrevias);

        if (cantPrevias == 0)
        {
            printf("La asignatura no tiene previas");
        }
        else
        {
            for (int i = 0; i < cantPrevias; i++)
            {
                int numeroPrevia = previas[i];

                Asignatura asignatura =
                    ObtenerAsignatura(
                        academia.asignaturas,
                        numeroPrevia);

                printf("%d - ", numeroPrevia);
                print(DarNombreAsignatura(asignatura));
                printf("\n");
            }
        }
    }
}

// Requerimiento 7
void MostrarDatosAlumnoAcademia(
    Academia academia,
    long int cedula)
{
    // TODO: implementar listado de datos del alumno.
}

// Requerimiento 8
void MostrarEscolaridadAcademia(
    Academia academia,
    long int cedula)
{
    // TODO: implementar listado de escolaridad.
}
