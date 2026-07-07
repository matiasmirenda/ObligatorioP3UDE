#include "Lista.h"

void Crear(Lista &l)
{
    l.prim = NULL;
    l.ult = NULL;
}

Boolean EsVacia(Lista l)
{
    Boolean vacia = FALSE;
    if (l.prim == NULL)
    {
        vacia = TRUE;
    }
    return vacia;
}

int Largo(Lista l)
{

    int cont = 0;

    if (l.prim != NULL)
    {
        cont = 1;
        NodoLista *aux = l.prim;

        while (aux != l.ult)
        {
            aux = aux->sig;
            cont++;
        }
    }

    return cont;
}

void InsBack(Lista &l, Curso c)
{
    NodoLista *nuevo = new NodoLista;
    nuevo->info = c;
    nuevo->sig = NULL;

    if (l.ult == NULL)
    {
        l.prim = nuevo;
        l.ult = nuevo;
    }
    else
    {
        l.ult->sig = nuevo;
        l.ult = nuevo;
    }
}

Curso Ultimo(Lista l)
{
    return l.ult->info;
}

Curso KEsimo(Lista l, int k)
{
    NodoLista *aux = l.prim;
    int i = 1;
    while (i < k)
    {
        aux = aux->sig;
        i++;
    }

    return aux->info;
}