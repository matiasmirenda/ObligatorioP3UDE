#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

#include "Hash.h"

typedef Hash Alumnos;

// Crea una colección vacía de alumnos.
void CrearAlumnos(Alumnos &alumnos);

// Devuelve TRUE si existe un alumno con la cédula indicada.
Boolean ExisteAlumno(Alumnos alumnos, long int cedula);

// Precondición: !ExisteAlumno(alumnos, a.cedula)
// Registra un nuevo alumno en la colección.
void InscribirAlumno(Alumnos &alumnos, Alumno a);

// Precondición: ExisteAlumno(alumnos, cedula)
// Devuelve el alumno correspondiente a la cédula indicada.
Alumno ObtenerAlumno(Alumnos alumnos, long int cedula);

// Precondición: ExisteAlumno(alumnos, a.cedula)
// Actualiza los datos de un alumno ya registrado.
void ModificarAlumno(Alumnos &alumnos, Alumno a);

// Muestra la info de un alumno especifico
void MostrarAlumno(Alumnos alumnos, long int cedula);

// Muestra la escolaridad de un alumno especifico
void MostrarEscolaridadAlumno(Alumnos alumnos, long int cedula);

#endif