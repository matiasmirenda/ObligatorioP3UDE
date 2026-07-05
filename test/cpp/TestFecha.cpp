#include "../../src/include/Fecha.h"
#include "../include/TestFecha.h"

#include <cassert>

void TestCrearFecha()
{
    Fecha f = CrearFecha(1, 7, 2026);

    assert(f.dia == 1);
    assert(f.mes == 7);
    assert(f.anio == 2026);
}

void TestEsBisiesto()
{
    Fecha f = CrearFecha(1, 1, 2024);

    assert(EsBisiesto(f));
}