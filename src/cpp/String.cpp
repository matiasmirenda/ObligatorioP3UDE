
#include "String.h"

void strcrear(String &s)
{
    s = new char[1];
    s[0] = '\0';
}

void strdestruir(String &s)
{
    delete[] s;
    s = NULL;
}

int strlar(String s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strcop(String &s1, String s2)
{
    int i = 0;
    int largo = strlar(s2) + 1;
    delete[] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void scan(String &s)
{
    String aux = new char[MAX];
    int i = 0;
    char c;
    scanf("%c", &c);
    while ((c != '\n' && i < MAX - 1))
    {
        aux[i] = c;
        i++;
        scanf("%c", &c);
    }
    aux[i] = '\0';
    strcop(s, aux);
    strdestruir(aux);
}

void print(String s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        printf("%c", s[i]);
        i++;
    }
}
