#include "../../src/include/Asignaturas.h"
#include "../include/TestAsignaturas.h"

#include <assert.h>

void TestAsignaturas()
{
    Asignaturas asignaturas;
    Asignatura a;
    Asignatura obtenida;

    CrearAsignaturas(asignaturas);

    assert(CantidadAsignaturas(asignaturas) == 0);
    assert(ExisteAsignatura(asignaturas, 0) == FALSE);

    a.cantidadHoras = 96;
    a.esOptativa = FALSE;

    RegistrarAsignatura(asignaturas, a);

    assert(CantidadAsignaturas(asignaturas) == 1);
    assert(ExisteAsignatura(asignaturas, 0) == TRUE);
    assert(ExisteAsignatura(asignaturas, 1) == FALSE);

    obtenida = ObtenerAsignatura(asignaturas, 0);

    assert(DarCantidadHorasAsignatura(obtenida) == 96);
    assert(EsAsignaturaOptativa(obtenida) == FALSE);
}