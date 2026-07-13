#ifndef PREVIAS_H
#define PREVIAS_H

#include "Grafo.h"

typedef Grafo Previaturas;

// Crea el grafo de previaturas
void CrearPreviaturas(Previaturas &P);

// Agrega una previatura directa entre dos asignaturas y devuelve TRUE. En caso de que esta accion genere un ciclo, no se agrega y devuelve FALSE
// Precondición: u y v son dos asigaturas diferentes y existentes
Boolean AgregarPrevia(Previaturas &P, int u, int v);

// Retorna TRUE si u es previa directa de v o FALSE en caso contrario
// Precondición: u y v son dos asigaturas existentes
Boolean EsPreviaDirecta(Previaturas P, int u, int v);

// Permite verificar que el alumno tenga aprobadas todas las previas inmediatas a v antes de cursarla
// Precondición: v es una asigatura existente
void PreviasInmediatasDe(Previaturas P, int v, int pre[], int &cantPre);

// Permite verificar todas las previas (inmediatas y no inmediatas) a v
// Precondición: v es una asigatura existente
void PreviasDe(Previaturas P, int v, int previas[], int &cantPrevias);

#endif