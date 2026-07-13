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

void InscribirAlumnoAcademia(Academia &A)
{
    Alumno nuevoAlumno;
    CargarAlumno(nuevoAlumno);

    if (!ExisteAlumno(A.alumnos, DarCedula(nuevoAlumno)))
        InscribirAlumno(A.alumnos, nuevoAlumno);
    else
        printf("El alumno con cedula %ld ya se encuentra inscripto en la academia.\n", DarCedula(nuevoAlumno));
}

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

void RegistrarCursoAcademia(Academia &ac, long int cedula)
{
    Curso nuevoCurso;
    CargarCurso(nuevoCurso);
    int numeroAsignatura = DarNumeroAsignaturaCurso(nuevoCurso);

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

                if (EsFechaMayor(fechaUltimoCurso, DarFechaFinalizacionCurso(nuevoCurso)))
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
                nuevoCurso.fechaFinalizacion = DarFechaFinalizacionCurso(nuevoCurso);
                nuevoCurso.calificacion = DarCalificacionCurso(nuevoCurso);

                AgregarCursoAlumno(alumno, nuevoCurso);
                ModificarAlumno(ac.alumnos, alumno);

                printf("Curso registrado exitosamente para el alumno con cedula %ld.\n", cedula);
            }
        }
    }
}

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

void MostrarDatosAlumnoAcademia(
    Academia academia,
    long int cedula)
{

    if (ExisteAlumno(academia.alumnos, cedula) == FALSE)
    {
        printf("No existe un alumno con el documento ingresado");
    }
    else
    {
        MostrarAlumno(academia.alumnos, cedula);
    }
}

void MostrarEscolaridadAcademia(
    Academia academia,
    long int cedula)
{
    if (ExisteAlumno(academia.alumnos, cedula) == FALSE)
    {
        printf("No existe un alumno con el documento ingresado");
    }
    else
    {
        MostrarEscolaridadAlumno(academia.alumnos, cedula);
    }
}
