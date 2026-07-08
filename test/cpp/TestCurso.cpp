#include "../../src/include/Curso.h"
#include "../include/TestCurso.h"

#include <assert.h>
#include <stdio.h>

void TestCurso()
{
    Curso c;

    FILE *archivo = fopen("build/input_curso.txt", "w");
    assert(archivo != NULL);

    fprintf(archivo, "3\n");
    fprintf(archivo, "10\n");
    fprintf(archivo, "7\n");
    fprintf(archivo, "2026\n");
    fprintf(archivo, "8\n");

    fclose(archivo);

    FILE *entrada = freopen("build/input_curso.txt", "r", stdin);
    assert(entrada != NULL);

    CargarCurso(c);

    assert(DarNumeroAsignaturaCurso(c) == 3);
    assert(DarCalificacionCurso(c) == 8);
    assert(CursoAprobado(c) == TRUE);

    Fecha f = DarFechaFinalizacionCurso(c);

    assert(f.dia == 10);
    assert(f.mes == 7);
    assert(f.anio == 2026);

    c.calificacion = 5;
    assert(CursoAprobado(c) == FALSE);
}