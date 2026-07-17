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
    EstadoOperacion estado = OK;

    if (CantidadAsignaturas(academia.asignaturas) >= MAX_ASIGNATURAS)
    {
        estado = MAXIMO_ASIGNATURAS_ALCANZADO;
    }
    else
    {

        RegistrarAsignatura(academia.asignaturas, asignatura);
    }

    return estado;
}

EstadoOperacion RegistrarPreviatura(
    Academia &academia,
    int numeroPrevia,
    int numeroAsignatura)
{
    EstadoOperacion estado = OK;

    if (!ExisteAsignatura(academia.asignaturas, numeroPrevia))
    {
        estado = ASIGNATURA1_NO_EXISTE;
    }
    else if (!ExisteAsignatura(academia.asignaturas, numeroAsignatura))
    {
        estado = ASIGNATURA2_NO_EXISTE;
    }
    else if (!AgregarPrevia(
                 academia.previaturas,
                 numeroPrevia,
                 numeroAsignatura))
    {
        estado = PREVIATURA_GENERA_CICLO;
    }

    return estado;
}

EstadoOperacion InscribirAlumnoAcademia(Academia &A, Alumno nuevoAlumno)
{
    EstadoOperacion estado = OK;

    if (!ExisteAlumno(A.alumnos, DarCedula(nuevoAlumno)))
    {
        InscribirAlumno(A.alumnos, nuevoAlumno);
    }
    else
        estado = ALUMNO_YA_EXISTE;

    return estado;
}

Boolean TienePreviasInmediatasAprobadas(Academia &A, Alumno alumno, int numeroAsignatura)
{
    int pre[MAX_ASIGNATURAS - 1];
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

EstadoOperacion RegistrarCursoAcademia(Academia &ac, long int cedula)
{
    EstadoOperacion estado = OK;

    if (!ExisteAlumno(ac.alumnos, cedula))
    {
        estado = ALUMNO_NO_EXISTE;
    }
    else
    {
        Curso nuevoCurso;
        CargarCurso(nuevoCurso);

        int numeroAsignatura = DarNumeroAsignaturaCurso(nuevoCurso);

        if (!ExisteAsignatura(ac.asignaturas, numeroAsignatura))
        {
            estado = ASIGNATURA2_NO_EXISTE;
        }
        else
        {
            Alumno alumno = ObtenerAlumno(ac.alumnos, cedula);

            if (TieneAsignaturaAprobadaAlumno(alumno, numeroAsignatura))
            {
                estado = ASIGNATURA_YA_APROBADA;
            }
            else if (!TienePreviasInmediatasAprobadas(ac, alumno, numeroAsignatura))
            {
                estado = PREVIAS_NO_APROBADAS;
            }
            else
            {
                Escolaridad esc = DarEscolaridad(alumno);

                if (!EsVacia(esc))
                {
                    Curso ultimo = Ultimo(esc);
                    Fecha fechaUltimoCurso = DarFechaFinalizacionCurso(ultimo);

                    if (!EsFechaMayor(fechaUltimoCurso, DarFechaFinalizacionCurso(nuevoCurso)))
                    {
                        estado = FECHA_ANTERIOR_ULTIMO_CURSO;
                    }
                    else
                    {
                        AgregarCursoAlumno(alumno, nuevoCurso);
                        ModificarAlumno(ac.alumnos, alumno);
                    }
                }
                else
                {
                    AgregarCursoAlumno(alumno, nuevoCurso);
                    ModificarAlumno(ac.alumnos, alumno);
                }
            }
        }
    }

    return estado;
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

    if (!ExisteAlumno(academia.alumnos, cedula))
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
    if (!ExisteAlumno(academia.alumnos, cedula))
    {
        printf("No existe un alumno con el documento ingresado");
    }
    else
    {
        MostrarEscolaridadAlumno(academia.alumnos, academia.asignaturas, cedula);
    }
}
