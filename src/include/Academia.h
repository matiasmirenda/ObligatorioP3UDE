#ifndef ACADEMIA_H_INCLUDED
#define ACADEMIA_H_INCLUDED

#include "Asignaturas.h"
#include "Alumnos.h"
#include "Previas.h"
#include "EstadoOperacion.h"

typedef struct
{
    Asignaturas asignaturas;
    Alumnos alumnos;
    Previaturas previaturas;
} Academia;

// Inicializa una academia vacía, sin asignaturas, sin alumnos y sin previaturas.
void CrearAcademia(Academia &academia);

// Registra una nueva asignatura en la academia y retorna el estado de la operación
EstadoOperacion RegistrarNuevaAsignatura(
    Academia &academia,
    Asignatura asignatura);

// Registra una previatura directa entre dos asignaturas (numeroPrevia previa de numeroAsignatura) y retorna el estado de la operación
EstadoOperacion RegistrarPreviatura(
    Academia &academia,
    int numeroPrevia,
    int numeroAsignatura);

// Inscribe un alumno en la academia
EstadoOperacion InscribirAlumnoAcademia(Academia &A);

// Devuelve TRUE si el alumno indicado tiene aprobadas todas las previas de la asignatura indicada
Boolean TienePreviasInmediatasAprobadas(Academia &A, Alumno alumno, int numeroAsignatura);

// Registra un curso en la escolaridad de un alumno
EstadoOperacion RegistrarCursoAcademia(Academia &A, long int cedula);

// Lista por pantalla todas las asignaturas registradas en la academia, ordenadas por número de asignatura
void ListarAsignaturasAcademia(
    Academia academia);

// Lista todas las asignaturas previas de la asignatura indicada
void ListarPreviasAcademia(
    Academia academia,
    int numeroAsignatura);

// Muestra por pantalla los datos básicos del alumno, la cantidad total de cursos registrados y la cantidad de cursos aprobados
void MostrarDatosAlumnoAcademia(
    Academia academia,
    long int cedula);

// Muestra por pantalla la escolaridad completa del alumno, ordenada cronológicamente
void MostrarEscolaridadAcademia(
    Academia academia,
    long int cedula);

#endif
