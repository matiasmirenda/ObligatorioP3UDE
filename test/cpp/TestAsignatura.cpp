#include "../../src/include/Asignatura.h"
#include "../include/TestAsignatura.h"

#include <assert.h>
#include <stdio.h>

void TestAsignatura()
{
    Asignatura a;

    FILE *archivo = fopen("build/input_asignatura.txt", "w");
    assert(archivo != NULL);

    fprintf(archivo, "Programacion III\n");
    fprintf(archivo, "96\n");
    fprintf(archivo, "0\n");

    fclose(archivo);

    FILE *entrada = freopen("build/input_asignatura.txt", "r", stdin);
    assert(entrada != NULL);

    CargarAsignatura(a);

    assert(DarCantidadHorasAsignatura(a) == 96);
    assert(EsAsignaturaOptativa(a) == FALSE);

    assert(streq(DarNombreAsignatura(a), "Programacion III"));

    fclose(entrada);

    Asignatura b;

    FILE *archivo2 = fopen("build/input_asignatura_2.txt", "w");
    assert(archivo2 != NULL);

    fprintf(archivo2, "Disenio Textil\n");
    fprintf(archivo2, "80\n");
    fprintf(archivo2, "1\n");

    fclose(archivo2);

    FILE *entrada2 = freopen("build/input_asignatura_2.txt", "r", stdin);
    assert(entrada2 != NULL);

    CargarAsignatura(b);

    assert(DarCantidadHorasAsignatura(b) == 80);
    assert(EsAsignaturaOptativa(b) == TRUE);
}