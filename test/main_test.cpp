#include "include/TestFecha.h"
#include "include/TestAlumnos.h"
#include "include/TestAsignatura.h"
#include "include/TestAsignaturas.h"
#include "include/TestCurso.h"
#include "include/TestHash.h"
#include "include/TestMapeo.h"
#include "include/TestLista.h"
#include "include/TestEscolaridad.h"

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

    TestCrearMapeo();
    TestInsertarMapeo();
    TestPerteneceMapeo();
    TestObtenerMapeo();
    TestCantidadRegistradasMapeo();

    TestCrear();
    TestEsVacia();
    TestLargo();
    TestInsBack();
    TestUltimo();
    TestKEsimo();

    TestCrearEscolaridad();
    TestEsVaciaEscolaridad();
    TestLargoEscolaridad();
    TestInsBackEscolaridad();
    TestUltimoEscolaridad();
    TestKEsimoEscolaridad();
    TestAsignaturaAprobadaEscolaridad();
    TestCantidadAprobadosEscolaridad();

    printf("\n------------------------------------------");
    printf("\n   TODOS LOS TEST FINALIZARON CON EXITO");
    printf("\n------------------------------------------\n");

    return 0;
}