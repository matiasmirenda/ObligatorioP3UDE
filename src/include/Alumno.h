#ifndef ALUMNO_H
#define ALUMNO_H

#include "Escolaridad.h"
#include "String.h"

// ============================================================
// TAD Alumno
// ------------------------------------------------------------
// Producto Cartesiano (registro) que agrupa los datos
// personales del alumno junto con su escolaridad.
//
// Estructura elegida: struct. Justificacion: un alumno posee
// un conjunto fijo de atributos (cedula, nombre, apellido,
// telefono, escolaridad), no representa una coleccion.
//
// Los campos de texto usan el TAD String del proyecto (modulo
// aparte), en vez de char* o std::string.
//
// Este modulo interactua con la Escolaridad del alumno
// unicamente a traves de las primitivas declaradas en
// Escolaridad.h, sin acceder a su representacion interna.
// ============================================================

typedef struct
{
    long int cedula;
    String nombre;
    String apellido;
    String telefono;
    Escolaridad escolaridad;
} Alumno;

// El alumno queda inicializado con los datos personales indicados y con su escolaridad vacia.
void CargarAlumno(Alumno &A);

// Retorna la cedula del alumno.
long int DarCedula(Alumno A);

// Retorna el nombre del alumno.
void DarNombre(Alumno A, String &nombre);

// Retorna el apellido del alumno.
void DarApellido(Alumno A, String &apellido);

// Retorna el telefono del alumno.
void DarTelefono(Alumno A, String &telefono);

// Retorna la escolaridad del alumno, para ser consultada mediante las primitivas propias del modulo Escolaridad.
Escolaridad DarEscolaridad(Alumno A);

// Precondicion: c es un curso valido a agregar en la
//               escolaridad de A (las validaciones del
//               requerimiento -asignatura registrada, previas
//               aprobadas, fecha valida, etc.- son
//               responsabilidad de quien invoca esta
//               operacion, es decir, del modulo Academia).
void AgregarCursoAlumno(Alumno &A, Curso c);

// Retorna la cantidad total de cursos registrados en la escolaridad del alumno.
int CantidadCursosAlumno(Alumno A);

// Retorna la cantidad de cursos aprobados en la escolaridad del alumno.
int CantidadCursosAprobadosAlumno(Alumno A);

// Retorna true si A tiene aprobada la asignatura numeroAsignatura.
Boolean TieneAsignaturaAprobadaAlumno(Alumno A, int numeroAsignatura);

// Muestra un alumno por pantalla
void MostrarAlumnoEspecifico(Alumno a);

#endif