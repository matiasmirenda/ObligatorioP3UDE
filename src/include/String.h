#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "Boolean.h"

const int MAX = 80;
typedef char *String;

// Crea un string vacio
void strcrear(String &s);

// Libera la memoria usada por el string
void strdestruir(String &s);

// Devuelve el largo del string s
int strlar(String s);

// Copia el contenido del string s2 en s1
void strcop(String &s1, String s2);

// Lee el string s desde teclado
void scan(String &s);

// Imprime el string s por pantalla
void print(String s);

// Determina si los strings s1 y s2 son iguales
Boolean streq(String s1, String s2);

#endif // STRING_H_INCLUDED
