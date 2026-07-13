#include "../include/Hash.h"

void Crear(Hash &hash)
{
    int i;

    for (i = 0; i < B; i++)
        hash[i] = NULL;
}

Boolean Pertenece(Hash hash, K clave)
{
    ListaHash aux = Buscar(hash, clave);
    Boolean pertenece = FALSE;

    if (aux != NULL)
        pertenece = TRUE;

    return pertenece;
}

void Insertar(Hash &hash, T e)
{
    K clave = DarClave(e);
    int cubeta = Hashing(clave);

    ListaHash nuevo = new NodoHash;
    nuevo->info = e;
    nuevo->sig = hash[cubeta];

    hash[cubeta] = nuevo;
}

T Obtener(Hash hash, K clave)
{
    ListaHash aux = Buscar(hash, clave);

    return aux->info;
}

void Eliminar(Hash &hash, K clave)
{
    int cubeta = Hashing(clave);
    ListaHash aux = hash[cubeta];

    if (DarClave(aux->info) == clave)
    {
        hash[cubeta] = aux->sig;
        delete aux;
    }
    else
    {
        while (DarClave(aux->sig->info) != clave)
            aux = aux->sig;

        ListaHash borrar = aux->sig;
        aux->sig = borrar->sig;
        delete borrar;
    }
}

// FUNCIONES PRIVADAS AUXILIARES
int Hashing(K clave)
{
    if (clave < 0)
        clave = -clave;

    return clave % B;
}

K DarClave(T e)
{
    return e.cedula;
}

ListaHash Buscar(Hash hash, K clave)
{
    int cubeta = Hashing(clave);
    ListaHash aux = hash[cubeta];

    while (aux != NULL && DarClave(aux->info) != clave)
        aux = aux->sig;

    return aux;
}