#ifndef GRAFO_H
#define GRAFO_H

#include "Boolean.h"

const int MAX_ASIGNATURAS = 30;

typedef int Grafo[MAX_ASIGNATURAS][MAX_ASIGNATURAS];

// Crea un grafo vacio
void CrearGrafo(Grafo &G);

// Agrega una previatura (arista) directa entre dos asignaturas (u y v)
// Precondición: u y v son dos asigaturas diferentes y existentes
void AgregarArista(Grafo &G, int u, int v);

// Determina si existe un camino entre origen y destino (si dos asignaturas son previas indirectas)
// Precondición: origen y destino son dos asigaturas diferentes y existentes
Boolean ExisteCamino(Grafo G, int origen, int destino);

// Permite obtener todas las previas inmediatas a v
// Precondición: v es una asigatura existente
void PreviasInmediatas(Grafo G, int v, int pre[], int &cantPre);

// Retorna TRUE si u es previa directa de v (hay una arista entre u y v) o FALSE en caso contrario
// Precondición: u y v son dos asigaturas existentes
Boolean HayArista(Grafo G, int u, int v);

// Devuelce todas las previas (inmediatas y no inmediatas) a v
// Precondición: v es una asigatura existente
void TodasLasPrevias(Grafo G, int v, int previas[], int &cantPrevias);

#endif
