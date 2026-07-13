#ifndef GRAFO_H
#define GRAFO_H

#include "Boolean.h"

// ============================================================
// TAD Grafo
// ------------------------------------------------------------
// Representa el grafo de previaturas entre asignaturas de la
// carrera. Es un grafo DIRIGIDO y ACICLICO (DAG):
//   - Vertices: asignaturas, identificadas por su numero
//               (0 .. MAX_ASIGNATURAS-1).
//   - Aristas: dada la arista (u, v), significa que la
//              asignatura u es previa DIRECTA de la
//              asignatura v.
//
// Estructura elegida: matriz de adyacencia de enteros.
// Justificacion: la cantidad de asignaturas esta acotada
// (maximo 30), por lo que la matriz ocupa poca memoria.
// Ademas, se indica que el regimen de previaturas es estricto
// y la cantidad de previaturas es elevada, por lo que interesa
// poder consultar en O(1) si existe una previatura directa
// entre dos asignaturas (HayArista), operacion que se usa
// frecuentemente (por ejemplo, al chequear previas inmediatas
// aprobadas al registrar un curso).
// Al no ser un multigrafo (a lo sumo una previatura directa
// entre dos asignaturas dadas), cada celda vale 1 si existe la
// arista, o 0 si no existe.
// ============================================================

const int MAX_ASIGNATURAS = 30;

typedef int Grafo[MAX_ASIGNATURAS][MAX_ASIGNATURAS];

// Precondicion: -No hay precondiciones sobre el grafo, ya que se crea vacio.
void CrearGrafo(Grafo &G);

// Precondicion: 0 <= u < MAX_ASIGNATURAS, 0 <= v < MAX_ASIGNATURAS,
//               u != v (no se admiten lazos, ya que una asignatura
//               no puede ser previa de si misma).
void AgregarArista(Grafo &G, int u, int v);

// Precondicion: 0 <= origen < MAX_ASIGNATURAS,
//               0 <= destino < MAX_ASIGNATURAS
Boolean ExisteCamino(Grafo G, int origen, int destino);

// Precondicion: 0 <= v < MAX_ASIGNATURAS
void PreviasInmediatas(Grafo G, int v, int pre[], int &cantPre);

// Precondicion: 0 <= u < MAX_ASIGNATURAS, 0 <= v < MAX_ASIGNATURAS
Boolean HayArista(Grafo G, int u, int v);

// Precondicion: 0 <= v < MAX_ASIGNATURAS
void TodasLasPrevias(Grafo G, int v, int previas[], int &cantPrevias);

#endif
