#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

#include "Hash.h"

typedef Hash Alumnos;

// Crea una colección vacía de alumnos
void CrearAlumnos(Alumnos &alumnos);

// Devuelve TRUE si existe un alumno con la cédula indicad o FALSE en caso contrario
Boolean ExisteAlumno(Alumnos alumnos, long int cedula);

// Registra un nuevo alumno en la colección
// Precondición: !ExisteAlumno(alumnos, a.cedula)
void InscribirAlumno(Alumnos &alumnos, Alumno a);

// Devuelve el alumno correspondiente a la cédula indicada
// Precondición: ExisteAlumno(alumnos, cedula)
Alumno ObtenerAlumno(Alumnos alumnos, long int cedula);

// Actualiza los datos de un alumno ya registrado
// Precondición: ExisteAlumno(alumnos, a.cedula)
void ModificarAlumno(Alumnos &alumnos, Alumno a);

// Muestra la info de un alumno especifico
// Precondición: el alumno existe
void MostrarAlumno(Alumnos alumnos, long int cedula);

// Muestra la escolaridad de un alumno especifico
// Precondición: el alumno existe
void MostrarEscolaridadAlumno(Alumnos alumnos, Asignaturas asignaturas, long int cedula);

#endif