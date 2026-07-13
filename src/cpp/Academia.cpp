#include "Academia.h"
#include "Alumnos.h"
#include "Asignaturas.h"
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

// Punto 3 — InscribirAlumnoAcademia: chequea ExisteAlumno por cédula antes de InscribirAlumno.

void InscribirAlumnoAcademia(Academia &A, Alumno &alumno)
{
    if (!ExisteAlumno(A.alumnos, DarCedula(alumno)))
        InscribirAlumno(A.alumnos, alumno);
    else
        printf("El alumno con cedula %ld ya se encuentra inscripto en la academia.\n", DarCedula(alumno));
}

// Punto 4 — RegistrarCursoAcademia: chequea ExisteAlumno, ExisteAsignatura, que no esté ya aprobada,
// que tenga aprobadas las previas inmediatas y que la fecha no sea anterior a la del último curso,
// antes de agregar el curso con AgregarCursoAlumno y persistir con ModificarAlumno.

Boolean TienePreviasInmediatasAprobadas(Academia &A, Alumno alumno, int numeroAsignatura)
{
    int pre[MAX_ASIGNATURAS];
    int cantPre = 0;
    PreviasInmediatasDe(A.previaturas, numeroAsignatura, pre, cantPre);

    Boolean todasAprobadas = TRUE;
    int i = 0;
    while (i < cantPre && todasAprobadas)
    {
        if (!TieneAsignaturaAprobadaAlumno(alumno, pre[i]))
            todasAprobadas = FALSE;
        i++;
    }
    return todasAprobadas;
}

void RegistrarCursoAcademia(Academia &ac, long int cedula,
                            int numeroAsignatura,
                            Fecha fechaFinalizacion,
                            int calificacion)
{

    if (!ExisteAlumno(ac.alumnos, cedula))
    {
        printf("El alumno con cedula %ld no se encuentra inscripto en la academia.\n", cedula);
    }
    else if (!ExisteAsignatura(ac.asignaturas, numeroAsignatura))
    {
        printf("La asignatura con numero %d no se encuentra en la academia.\n", numeroAsignatura);
    }
    else
    {
        Alumno alumno = ObtenerAlumno(ac.alumnos, cedula);

        if (TieneAsignaturaAprobadaAlumno(alumno, numeroAsignatura))
        {
            printf("El alumno con cedula %ld ya tiene aprobada la asignatura %d.\n", cedula, numeroAsignatura);
        }
        else if (!TienePreviasInmediatasAprobadas(ac, alumno, numeroAsignatura))
        {
            printf("El alumno con cedula %ld no tiene aprobadas todas las previas inmediatas de la asignatura %d.\n", cedula, numeroAsignatura);
        }
        else
        {
            Escolaridad esc = DarEscolaridad(alumno);
            Boolean fechaValida = TRUE;

            if (!EsVacia(esc))
            {
                Curso ultimo = Ultimo(esc);
                Fecha fechaUltimoCurso = DarFechaFinalizacionCurso(ultimo);

                if (EsFechaMayor(fechaUltimoCurso, fechaFinalizacion))
                    fechaValida = FALSE;
            }

            if (!fechaValida)
            {
                printf("La fecha de finalizacion es anterior a la del ultimo curso registrado para el alumno con cedula %ld.\n", cedula);
            }
            else
            {
                Curso nuevoCurso;
                nuevoCurso.numeroAsignatura = numeroAsignatura;
                nuevoCurso.fechaFinalizacion = fechaFinalizacion;
                nuevoCurso.calificacion = calificacion;

                AgregarCursoAlumno(alumno, nuevoCurso);
                ModificarAlumno(ac.alumnos, alumno);

                printf("Curso registrado exitosamente para el alumno con cedula %ld.\n", cedula);
            }
        }
    }
}

// Requerimiento 5
void ListarAsignaturasAcademia(Academia academia)
{
    int cantAsignaturas = CantidadAsignaturas(academia.asignaturas);
    if (cantAsignaturas == 0)
    {
        printf("No hay asignaturas registradas\n");
    }
    else
    {

        ListarAsignaturas(academia.asignaturas);
        printf("\n \n Total de asignaturas: %d\n", cantAsignaturas);
    }
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

    if (ExisteAlumno(academia.alumnos, cedula) == FALSE)
    {
        printf("No existe una alumno con el documento ingresado");
    }
    else
    {
        MostrarAlumno(academia.alumnos, cedula);
    }
}

// Requerimiento 8
void MostrarEscolaridadAcademia(
    Academia academia,
    long int cedula)
{
    // TODO: implementar listado de escolaridad.
}
