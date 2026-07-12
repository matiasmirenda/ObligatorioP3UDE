#include "../../src/include/Fecha.h"
#include "../include/TestFecha.h"

#include <cassert>

void TestEsMismaFecha()
{
    assert(EsMismaFecha({1, 7, 2026}, {1, 7, 2026}) == TRUE);  // iguales
    assert(EsMismaFecha({1, 7, 2026}, {2, 7, 2026}) == FALSE); // día diferente
    assert(EsMismaFecha({1, 7, 2026}, {1, 8, 2026}) == FALSE); // mes diferente
    assert(EsMismaFecha({1, 7, 2026}, {1, 7, 2027}) == FALSE); // año diferente
}

void TestEsFechaMayor()
{

    assert(EsFechaMayor({1, 1, 2026}, {1, 1, 2025}) == TRUE);  // Mayor por año
    assert(EsFechaMayor({1, 2, 2026}, {1, 1, 2026}) == TRUE);  // Mayor por mes
    assert(EsFechaMayor({2, 1, 2026}, {1, 1, 2026}) == TRUE);  // Mayor por día
    assert(EsFechaMayor({1, 1, 2026}, {1, 1, 2026}) == FALSE); // Fechas iguales
    assert(EsFechaMayor({1, 1, 2025}, {1, 1, 2026}) == FALSE); // Menor por año
    assert(EsFechaMayor({1, 1, 2026}, {1, 2, 2026}) == FALSE); // Menor por mes
    assert(EsFechaMayor({1, 1, 2026}, {2, 1, 2026}) == FALSE); // Menor por día
}

void TestEsFechaValida()
{
    // Fechas válidas
    assert(EsFechaValida({1, 1, 2026}) == TRUE);
    assert(EsFechaValida({31, 1, 2026}) == TRUE);
    assert(EsFechaValida({30, 4, 2026}) == TRUE);
    assert(EsFechaValida({28, 2, 2025}) == TRUE);
    assert(EsFechaValida({29, 2, 2024}) == TRUE);

    // Mes inválido
    assert(EsFechaValida({1, 0, 2026}) == FALSE);
    assert(EsFechaValida({1, 13, 2026}) == FALSE);

    // Día inválido
    assert(EsFechaValida({0, 1, 2026}) == FALSE);
    assert(EsFechaValida({32, 1, 2026}) == FALSE);
    assert(EsFechaValida({31, 4, 2026}) == FALSE);
    assert(EsFechaValida({29, 2, 2025}) == FALSE);
    assert(EsFechaValida({30, 2, 2024}) == FALSE);
}

void TestFecha()
{
    TestEsMismaFecha();
    TestEsFechaValida();
    TestEsFechaMayor();
}