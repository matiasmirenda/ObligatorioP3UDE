#include "include/TestAcademia.h"
#include "include/TestAlumno.h"
#include "include/TestAlumnos.h"
#include "include/TestAsignatura.h"
#include "include/TestAsignaturas.h"
#include "include/TestBoolean.h"
#include "include/TestCurso.h"
#include "include/TestEscolaridad.h"
#include "include/TestEstadoOperacion.h"
#include "include/TestFecha.h"
#include "include/TestGrafo.h"
#include "include/TestHash.h"
#include "include/TestLista.h"
#include "include/TestMapeo.h"
#include "include/TestMenu.h"
#include "include/TestPrevias.h"
#include "include/TestString.h"

#include <cstdio>

int main()
{
    TestGrafo();
    printf("OK - Tests de Grafo\n");

    TestPrevias();
    printf("OK - Tests de Previas\n");

    TestFecha();
    printf("OK - Tests de Fecha\n");

    TestLista();
    printf("OK - Tests de Lista\n");

    TestEscolaridad();
    printf("OK - Tests de Escolaridad\n");

    TestHash();
    printf("OK - Tests de Hash\n");

    TestAlumnos();
    printf("OK - Tests de Alumnos\n");

    TestMapeo();
    printf("OK - Tests de Mapeo\n");

    TestAsignaturas();
    printf("OK - Tests de Asignaturas\n");

    TestString();
    printf("OK - Tests de String\n");

    TestEstadoOperacion();
    printf("OK - Tests de EstadoOperacion\n");

    TestAcademia();
    printf("OK - Tests de Academia\n");

    /*
     * Estos usan freopen(stdin), por eso se dejan al final.
     */

    TestCurso();
    printf("OK - Tests de Curso\n");

    TestAsignatura();
    printf("OK - Tests de Asignatura\n");

    TestAlumno();
    printf("OK - Tests de Alumno\n");

    TestBoolean();
    printf("OK - Tests de Boolean\n");

    TestMenu();
    printf("OK - Tests de Menu\n");

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