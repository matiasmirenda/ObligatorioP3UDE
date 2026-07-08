#ifndef ESCOLARIDAD_H
#define ESCOLARIDAD_H

#include "Boolean.h"
#include "Curso.h"

// ============================================================
// PLACEHOLDER - Escolaridad.h
// ============================================================

const int MAX_CURSOS = 50;

typedef struct {
    Curso cursos[MAX_CURSOS];
    int cantidad;
} Escolaridad;

void CrearEscolaridad(Escolaridad &E);
void AgregarCurso(Escolaridad &E, Curso c);
int CantidadCursos(Escolaridad E);
int CantidadCursosAprobados(Escolaridad E);
Boolean TieneAsignaturaAprobada(Escolaridad E, int numeroAsignatura);

#endif