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
}