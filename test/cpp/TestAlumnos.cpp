#include "../../src/include/Alumnos.h"
#include "../include/TestAlumnos.h"

#include <assert.h>

void TestAlumnos()
{
    Alumnos alumnos;
    Alumno a;
    Alumno obtenido;

    CrearAlumnos(alumnos);

    a.cedula = 12345678;

    assert(ExisteAlumno(alumnos, 12345678) == FALSE);

    InscribirAlumno(alumnos, a);

    assert(ExisteAlumno(alumnos, 12345678) == TRUE);

    obtenido = ObtenerAlumno(alumnos, 12345678);

    assert(obtenido.cedula == 12345678);

    ModificarAlumno(alumnos, obtenido);

    assert(ExisteAlumno(alumnos, 12345678) == TRUE);
}