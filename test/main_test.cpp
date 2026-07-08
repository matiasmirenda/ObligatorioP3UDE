#include "include/TestFecha.h"
#include "include/TestAlumnos.h"
#include "include/TestAsignatura.h"
#include "include/TestAsignaturas.h"
#include "include/TestCurso.h"
#include "include/TestHash.h"

#include <stdio.h>

int main()
{
    TestAlumnos();
    TestAsignatura();
    TestAsignaturas();
    TestCurso();
    TestHash();
    TestEsMismaFecha();
    TestEsFechaValida();
    TestEsFechaMayor();

    printf("\n------------------------------------------");
    printf("\n   TODOS LOS TEST FINALIZARON CON EXITO");
    printf("\n------------------------------------------\n");
}