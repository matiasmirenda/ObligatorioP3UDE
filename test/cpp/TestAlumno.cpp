#include "../../src/include/Alumno.h"
#include "../../src/include/String.h"
#include "../../src/include/Boolean.h"
#include "../include/TestAlumno.h"

#include <cassert>

// NOTA: estos tests usan Curso.h / Escolaridad.h PLACEHOLDER.
// Cuando implementes los modulos reales, revisa que los campos
// de Curso (numeroAsignatura, aprobado, nota) sigan existiendo
// con esos nombres, o ajusta estos tests.

void TestCrearAlumno()
{
    Alumno A;
    String nombre = (char *)"Carolina";
    String apellido = (char *)"Perez";
    String telefono = (char *)"099123456";

    CrearAlumno(A, 12345678, nombre, apellido, telefono);

    assert(DarCedula(A) == 12345678);
    assert(CantidadCursosAlumno(A) == 0);
    assert(CantidadCursosAprobadosAlumno(A) == 0);
}

void TestDarDatosAlumno()
{
    Alumno A;
    String nombre = (char *)"Matias";
    String apellido = (char *)"Mirenda";
    String telefono = (char *)"098765432";

    CrearAlumno(A, 87654321, nombre, apellido, telefono);

    String nombreObtenido, apellidoObtenido, telefonoObtenido;
    strcrear(nombreObtenido);
    strcrear(apellidoObtenido);
    strcrear(telefonoObtenido);

    DarNombre(A, nombreObtenido);
    DarApellido(A, apellidoObtenido);
    DarTelefono(A, telefonoObtenido);

    assert(streq(nombreObtenido, nombre) == TRUE);
    assert(streq(apellidoObtenido, apellido) == TRUE);
    assert(streq(telefonoObtenido, telefono) == TRUE);

    strdestruir(nombreObtenido);
    strdestruir(apellidoObtenido);
    strdestruir(telefonoObtenido);
}

void TestAgregarCursoAlumno()
{
    Alumno A;
    String nombre = (char *)"Juan";
    String apellido = (char *)"Gomez";
    String telefono = (char *)"091111111";

    CrearAlumno(A, 11111111, nombre, apellido, telefono);

    Curso c;
    c.numeroAsignatura = 1;
    c.aprobado = TRUE;
    c.nota = 8;

    AgregarCursoAlumno(A, c);

    assert(CantidadCursosAlumno(A) == 1);
    assert(CantidadCursosAprobadosAlumno(A) == 1);
}

void TestTieneAsignaturaAprobadaAlumno()
{
    Alumno A;
    String nombre = (char *)"Ana";
    String apellido = (char *)"Lopez";
    String telefono = (char *)"092222222";

    CrearAlumno(A, 22222222, nombre, apellido, telefono);

    Curso aprobado;
    aprobado.numeroAsignatura = 5;
    aprobado.aprobado = TRUE;
    aprobado.nota = 9;

    Curso noAprobado;
    noAprobado.numeroAsignatura = 6;
    noAprobado.aprobado = FALSE;
    noAprobado.nota = 2;

    AgregarCursoAlumno(A, aprobado);
    AgregarCursoAlumno(A, noAprobado);

    assert(TieneAsignaturaAprobadaAlumno(A, 5) == TRUE);
    assert(TieneAsignaturaAprobadaAlumno(A, 6) == FALSE);
    assert(CantidadCursosAlumno(A) == 2);
    assert(CantidadCursosAprobadosAlumno(A) == 1);
}
