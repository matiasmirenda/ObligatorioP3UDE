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

// Inserta un elemento en el hash.
// Precondición: !Pertenece(h, DarClave(e))
void Insertar(Hash &h, T e);

// Devuelve el elemento asociado a la clave indicada.
// Precondición: Pertenece(h, clave)
T Obtener(Hash h, K clave);

// Elimina el elemento asociado a la clave indicada.
// Precondición: Pertenece(hash, clave)
void Eliminar(Hash &hash, K clave);

#endif