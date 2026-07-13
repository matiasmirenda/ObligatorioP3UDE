#ifndef LISTA_H
#define LISTA_H

#include "Curso.h"

typedef struct nodoL
{
    Curso info;
    nodoL *sig;
} NodoLista;

typedef struct
{
    NodoLista *prim;
    NodoLista *ult;
} Lista;

// Crea una lista vacía.
void Crear(Lista &l);

// Determina si la lista está vacía.
Boolean EsVacia(Lista l);

// Devuelve la cantidad de elementos de la lista.
int Largo(Lista l);

// Agrega un elemento al final de la lista.
void InsBack(Lista &l, Curso c);

// Devuelve el último elemento de la lista.
// Precondición: La lista no esta vacia
Curso Ultimo(Lista l);

// Devuelve el elemento que ocupa la posición k
// Precondición: k es mayor a 1 y menor al largo de la lista
Curso KEsimo(Lista l, int k);

#endif