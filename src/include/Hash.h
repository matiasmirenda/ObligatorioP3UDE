#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "Alumno.h"

const int B = 101;

typedef long int K;
typedef Alumno T;

typedef struct nodoHash
{
    T info;
    nodoHash *sig;
} NodoHash;

typedef NodoHash *ListaHash;

typedef ListaHash Hash[B];

// Crea un hash vacío.
void Crear(Hash &h);

// Devuelve TRUE si existe un elemento con la clave indicada.
Boolean Pertenece(Hash h, K clave);

// Precondición: !Pertenece(h, DarClave(e))
// Inserta un elemento en el hash.
void Insertar(Hash &h, T e);

// Precondición: Pertenece(h, clave)
// Devuelve el elemento asociado a la clave indicada.
T Obtener(Hash h, K clave);

// Precondición: Pertenece(hash, clave)
// Elimina el elemento asociado a la clave indicada.
void Eliminar(Hash &hash, K clave);

#endif