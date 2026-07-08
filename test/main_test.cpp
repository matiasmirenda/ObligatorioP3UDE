#include "include/TestFecha.h"
#include "include/TestGrafo.h"
#include "include/TestPrevias.h"
#include "include/TestAlumno.h"

#include <cstdio>

int main()
{
    TestCrearFecha();
    TestEsBisiesto();
    printf("OK - Tests de Fecha\n");

    TestCrearGrafo();
    TestAgregarArista();
    TestExisteCamino();
    TestPreviasInmediatas();
    TestTodasLasPrevias();
    printf("OK - Tests de Grafo\n");

    TestCrearPreviaturas();
    TestAgregarPrevia();
    TestEsPreviaDirecta();
    TestPreviasInmediatasDe();
    TestPreviasDe();
    printf("OK - Tests de Previas\n");

    TestCrearAlumno();
    TestDarDatosAlumno();
    TestAgregarCursoAlumno();
    TestTieneAsignaturaAprobadaAlumno();
    printf("OK - Tests de Alumno\n");

    printf("\nTodos los tests pasaron correctamente.\n");

    return 0;
}