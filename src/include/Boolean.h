#ifndef BOOLEAN_H
#define BOOLEAN_H
#include <stdio.h>

typedef enum
{
    FALSE,
    TRUE
} Boolean;

// Cargar valor boolean desde teclado
void Cargar(Boolean &b);

// Mostrar valor booleano en pantalla
void Desplegar(Boolean b);

#endif