#include "include/TestFecha.h"
#include "include/TestGrafo.h"
#include "include/TestPrevias.h"
#include "include/TestAlumno.h"
#include "include/TestAlumnos.h"
#include "include/TestAsignatura.h"
#include "include/TestAsignaturas.h"
#include "include/TestCurso.h"
#include "include/TestHash.h"
#include "include/TestMapeo.h"
#include "include/TestLista.h"
#include "include/TestEscolaridad.h"
#include "include/TestAcademia.h"


#include <cstdio>

int main()
{

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

    
    TestCargayDarDatosAlumno();
    TestAgregarCursoAlumno();
    TestTieneAsignaturaAprobadaAlumno();
    printf("OK - Tests de Alumno\n");

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

    TestInscribirAlumnoAcademia();
    TestRegistrarCursoAcademia_AlumnoNoExiste();
    TestRegistrarCursoAcademia_AsignaturaNoExiste();
    TestRegistrarCursoAcademia_Exitoso();
    TestRegistrarCursoAcademia_YaAprobada();
    TestRegistrarCursoAcademia_PreviasNoAprobadas();
    TestRegistrarCursoAcademia_FechaAnterior();

    printf("\n------------------------------------------");
    printf("\n   TODOS LOS TEST FINALIZARON CON EXITO");
    printf("\n------------------------------------------\n");

    return 0;
}