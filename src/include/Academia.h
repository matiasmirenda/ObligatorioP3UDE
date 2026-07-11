#ifndef ACADEMIA_H
#define ACADEMIA_H

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
// Inicializa una academia vacía, sin asignaturas,
// sin alumnos y sin previaturas.
void CrearAcademia(Academia &academia);

// Registra una nueva asignatura en la academia.
// El número de asignatura se asigna automáticamente.
// Retorna el estado de la operación.
EstadoOperacion RegistrarNuevaAsignatura(
    Academia &academia,
    Asignatura asignatura);

// Registra una previatura directa entre dos asignaturas.
// numeroPrevia será previa de numeroAsignatura.
// Retorna el estado de la operación.
EstadoOperacion RegistrarPreviatura(
    Academia &academia,
    int numeroPrevia,
    int numeroAsignatura);

// Inscribe un nuevo alumno en la academia,
// verificando previamente que no exista otro con
// la misma cédula.
// Retorna el estado de la operación.
EstadoOperacion InscribirNuevoAlumno(
    Academia &academia,
    Alumno alumno);

// Registra un curso en la escolaridad de un alumno,
// verificando todas las restricciones del sistema.
// Retorna el estado de la operación.
EstadoOperacion RegistrarCursoAcademia(
    Academia &academia,
    long int cedula,
    int numeroAsignatura,
    Fecha fechaFinalizacion,
    int calificacion);

// Lista por pantalla todas las asignaturas
// registradas en la academia ordenadas por número.
void ListarAsignaturasAcademia(
    Academia academia);

// Lista todas las asignaturas previas de la
// asignatura indicada.
void ListarPreviasAcademia(
    Academia academia,
    int numeroAsignatura);

// Muestra por pantalla los datos básicos del alumno,
// la cantidad total de cursos registrados y la cantidad
// de cursos aprobados.
void MostrarDatosAlumnoAcademia(
    Academia academia,
    long int cedula);

// Muestra por pantalla la escolaridad completa del
// alumno ordenada cronológicamente.
void MostrarEscolaridadAcademia(
    Academia academia,
    long int cedula);
#endif