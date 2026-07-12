#ifndef ACADEMIA_H
#define ACADEMIA_H

#include "Alumnos.h"
#include "Asignaturas.h"
#include "Previas.h"

// ============================================================
// TAD Academia
// ------------------------------------------------------------
// Producto Cartesiano (registro) que agrupa los datos
// de la academia junto con la lista de alumnos inscriptos.
//
// Estructura elegida: struct. Justificacion: una academia posee
// un conjunto fijo de atributos (nombre, direccion, etc.), no
// representa una coleccion.
// ============================================================

typedef struct {
    Alumnos alumnos;
    Asignaturas asignaturas;
    Previaturas previas;
} Academia;

void CrearAcademia(Academia &A);
// Precondicion: A es una academia valida y alumno es un alumno valido.
// El alumno queda inscripto en la academia si no estaba inscripto previamente.
void InscribirAlumnoAcademia(Academia &A, Alumno &alumno);



Boolean TienePreviasInmediatasAprobadas(Academia &A, Alumno alumno, int numeroAsignatura);


void RegistrarCursoAcademia(Academia &A, long int cedula,
                                          int numeroAsignatura,
                                          Fecha fechaFinalizacion,
                                          int calificacion);


#endif // ACADEMIA_H