#ifndef ALUMNO_H
#define ALUMNO_H

#include "Escolaridad.h"
#include "String.h"

typedef struct
{
    long int cedula;
    String nombre;
    String apellido;
    String telefono;
    Escolaridad escolaridad;
} Alumno;

// El alumno queda inicializado con los datos personales indicados y con su escolaridad vacia
void CargarAlumno(Alumno &A);

// Retorna la cedula del alumno
long int DarCedula(Alumno A);

// Retorna el nombre del alumno
void DarNombre(Alumno A, String &nombre);

// Retorna el apellido del alumno
void DarApellido(Alumno A, String &apellido);

// Retorna el telefono del alumno
void DarTelefono(Alumno A, String &telefono);

// Retorna la escolaridad del alumno
Escolaridad DarEscolaridad(Alumno A);

// Agrega un curso a la escolaridad de un alumno
// Precondición 1: el alumno y la asignatura existen
// Precondición 2: el alumno tiene todas las previas a la asignatura aprobadas
// Precondición 3: el alumno no tiene la asignatura aprovada
void AgregarCursoAlumno(Alumno &A, Curso c);

// Retorna la cantidad total de cursos registrados en la escolaridad del alumno
int CantidadCursosAlumno(Alumno A);

// Retorna la cantidad de cursos aprobados en la escolaridad del alumno
int CantidadCursosAprobadosAlumno(Alumno A);

// Retorna true si A tiene aprobada la asignatura numeroAsignatura
// Precondición 1: el alumno y la asignatura existen
Boolean TieneAsignaturaAprobadaAlumno(Alumno A, int numeroAsignatura);

// Muestra un alumno por pantalla
// Precondición: el alumno existe
void MostrarAlumnoEspecifico(Alumno a);

// Muestra la escolaridad de un alumno por pan
// Precondición: el alumno existe
void MostrarEscolaridadEspecifica(Alumno a, Asignaturas asignaturas);

#endif