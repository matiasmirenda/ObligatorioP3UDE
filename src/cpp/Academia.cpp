#include "Academia.h"
#include "Alumnos.h"
#include "Asignaturas.h"

void CrearAcademia(Academia &A)
{
    CrearAlumnos(A.alumnos);
    CrearAsignaturas(A.asignaturas);
    CrearPreviaturas(A.previas);
}

//Punto 3 — InscribirAlumnoAcademia: chequea ExisteAlumno por cédula antes de InscribirAlumno.

void InscribirAlumnoAcademia(Academia &A, Alumno &alumno)
{
    if (!ExisteAlumno(A.alumnos, DarCedula(alumno)))
        InscribirAlumno(A.alumnos, alumno);
    else
        printf("El alumno con cedula %ld ya se encuentra inscripto en la academia.\n", DarCedula(alumno));
}

//Punto 4 — RegistrarCursoAcademia: chequea ExisteAlumno, ExisteAsignatura, que no esté ya aprobada, 
//que tenga aprobadas las previas inmediatas y que la fecha no sea anterior a la del último curso, 
//antes de agregar el curso con AgregarCursoAlumno y persistir con ModificarAlumno.

Boolean TienePreviasInmediatasAprobadas(Academia &A, Alumno alumno, int numeroAsignatura)
{
    int pre[MAX_ASIGNATURAS];
    int cantPre = 0;
    PreviasInmediatasDe(A.previas, numeroAsignatura, pre, cantPre);

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
       printf("El alumno con cedula %ld no se encuentra inscripto en la academia.\n",cedula);
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
                printf("La fecha de finalización es anterior a la del último curso registrado para el alumno con cedula %ld.\n", cedula);
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