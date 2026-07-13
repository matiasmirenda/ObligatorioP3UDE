#ifndef PREVIAS_H
#define PREVIAS_H

#include "Grafo.h"

// ============================================================
// TAD Previaturas
// ------------------------------------------------------------
// Modela el regimen de previaturas estrictas entre asignaturas.
// Reutiliza el TAD generico Grafo (matriz de adyacencia) y le
// agrega las reglas propias del dominio:
//   - no se admiten lazos (una asignatura no puede ser previa
//     de si misma).
//   - no se admite formar ciclos de previaturas.
//
// Este modulo NO conoce la representacion interna de Grafo: se
// implementa exclusivamente en base a las primitivas declaradas
// en Grafo.h.
// ============================================================

typedef Grafo Previaturas;

// Precondicion: No hay precondiciones sobre P, ya que se crea vacio.
void CrearPreviaturas(Previaturas &P);

// Precondicion: 0 <= u < MAX_ASIGNATURAS, 0 <= v < MAX_ASIGNATURAS
// Si u == v/agregar la previatura (u, v) / si ya existe  un camino desde v hasta u entonces P no se modifica y
// se retorna false. En caso contrario, se agrega la previatura directa (u es previa de v) y seretorna true.

// Nota: esta operacion NO verifica que u y v correspondan a
// asignaturas efectivamente registradas en el sistema; esa
// verificacion es responsabilidad de quien invoca esta
// operacion (modulo Academia), consultando el modulo
// Asignaturas.
Boolean AgregarPrevia(Previaturas &P, int u, int v);

// Retorna true si u es previa directa de v en P.
Boolean EsPreviaDirecta(Previaturas P, int u, int v);

//  Pre[] y cantPre quedan con las previas INMEDIATAS de la asignatura v. Se usa para
// verificar que el alumno tenga aprobadas todas  sus previas inmediatas antes de cursar v.
void PreviasInmediatasDe(Previaturas P, int v, int pre[], int &cantPre);

// Previas[] y cantPrevias quedan con TODAS las
// previas de la asignatura v (inmediatas y noinmediatas). El orden en que se listan es irrelevante.
void PreviasDe(Previaturas P, int v, int previas[], int &cantPrevias);

#endif