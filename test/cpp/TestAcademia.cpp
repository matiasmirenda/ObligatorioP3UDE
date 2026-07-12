#include "../../src/include/Academia.h"
#include "../include/TestAcademia.h"

#include <assert.h>

static void CrearAsignaturaAcademiaTest(
    Asignatura &asignatura,
    String nombre,
    int cantidadHoras,
    Boolean esOptativa)
{
    strcrear(asignatura.nombre);
    strcop(asignatura.nombre, nombre);

    asignatura.cantidadHoras = cantidadHoras;
    asignatura.esOptativa = esOptativa;
}

void TestCrearAcademia()
{
    Academia academia;

    CrearAcademia(academia);

    assert(
        CantidadAsignaturas(
            academia.asignaturas) == 0);

    assert(
        ExisteAsignatura(
            academia.asignaturas,
            0) == FALSE);
}

void TestAcademiaRegistrarPrimeraAsignatura()
{
    Academia academia;
    Asignatura asignatura;
    Asignatura obtenida;

    CrearAcademia(academia);

    CrearAsignaturaAcademiaTest(
        asignatura,
        (char *)"Programacion III",
        96,
        FALSE);

    EstadoOperacion estado =
        RegistrarNuevaAsignatura(
            academia,
            asignatura);

    assert(estado == OK);

    assert(
        CantidadAsignaturas(
            academia.asignaturas) == 1);

    assert(
        ExisteAsignatura(
            academia.asignaturas,
            0) == TRUE);

    obtenida =
        ObtenerAsignatura(
            academia.asignaturas,
            0);

    assert(
        DarNumeroAsignatura(
            obtenida) == 0);

    assert(
        streq(
            DarNombreAsignatura(obtenida),
            (char *)"Programacion III") == TRUE);

    assert(
        DarCantidadHorasAsignatura(obtenida) ==
        96);

    assert(
        EsAsignaturaOptativa(obtenida) ==
        FALSE);
}

void TestAcademiaRegistrarAsignaturasConNumerosConsecutivos()
{
    Academia academia;
    Asignatura primera;
    Asignatura segunda;
    Asignatura obtenidaPrimera;
    Asignatura obtenidaSegunda;

    CrearAcademia(academia);

    CrearAsignaturaAcademiaTest(
        primera,
        (char *)"Programacion III",
        96,
        FALSE);

    CrearAsignaturaAcademiaTest(
        segunda,
        (char *)"Base de Datos",
        80,
        TRUE);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            primera) == OK);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            segunda) == OK);

    assert(
        CantidadAsignaturas(
            academia.asignaturas) == 2);

    obtenidaPrimera =
        ObtenerAsignatura(
            academia.asignaturas,
            0);

    obtenidaSegunda =
        ObtenerAsignatura(
            academia.asignaturas,
            1);

    assert(
        DarNumeroAsignatura(
            obtenidaPrimera) == 0);

    assert(
        DarNumeroAsignatura(
            obtenidaSegunda) == 1);
}

void TestAcademiaRegistrarAsignaturaSuperaMaximo()
{
    Academia academia;

    CrearAcademia(academia);

    for (int i = 0;
         i < MAX_ASIGNATURAS;
         i++)
    {
        Asignatura asignatura;

        CrearAsignaturaAcademiaTest(
            asignatura,
            (char *)"Asignatura",
            40,
            FALSE);

        assert(
            RegistrarNuevaAsignatura(
                academia,
                asignatura) == OK);
    }

    assert(
        CantidadAsignaturas(
            academia.asignaturas) ==
        MAX_ASIGNATURAS);

    Asignatura extra;

    CrearAsignaturaAcademiaTest(
        extra,
        (char *)"Asignatura extra",
        50,
        TRUE);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            extra) ==
        MAXIMO_ASIGNATURAS_ALCANZADO);

    assert(
        CantidadAsignaturas(
            academia.asignaturas) ==
        MAX_ASIGNATURAS);
}

void TestAcademiaRegistrarPreviaturaCorrecta()
{
    Academia academia;
    Asignatura primera;
    Asignatura segunda;

    CrearAcademia(academia);

    CrearAsignaturaAcademiaTest(
        primera,
        (char *)"Introduccion",
        50,
        FALSE);

    CrearAsignaturaAcademiaTest(
        segunda,
        (char *)"Diseno I",
        80,
        FALSE);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            primera) == OK);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            segunda) == OK);

    EstadoOperacion estado =
        RegistrarPreviatura(
            academia,
            0,
            1);

    assert(estado == OK);

    assert(
        EsPreviaDirecta(
            academia.previaturas,
            0,
            1) == TRUE);
}

void TestAcademiaRegistrarPreviaturaPrimeraNoExiste()
{
    Academia academia;
    Asignatura asignatura;

    CrearAcademia(academia);

    CrearAsignaturaAcademiaTest(
        asignatura,
        (char *)"Asignatura",
        50,
        FALSE);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            asignatura) == OK);

    assert(
        RegistrarPreviatura(
            academia,
            8,
            0) ==
        ASIGNATURA1_NO_EXISTE);
}

void TestAcademiaRegistrarPreviaturaSegundaNoExiste()
{
    Academia academia;
    Asignatura asignatura;

    CrearAcademia(academia);

    CrearAsignaturaAcademiaTest(
        asignatura,
        (char *)"Asignatura",
        50,
        FALSE);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            asignatura) == OK);

    assert(
        RegistrarPreviatura(
            academia,
            0,
            8) ==
        ASIGNATURA2_NO_EXISTE);
}

void TestAcademiaRegistrarPreviaturaMismaAsignatura()
{
    Academia academia;
    Asignatura asignatura;

    CrearAcademia(academia);

    CrearAsignaturaAcademiaTest(
        asignatura,
        (char *)"Asignatura",
        50,
        FALSE);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            asignatura) == OK);

    assert(
        RegistrarPreviatura(
            academia,
            0,
            0) ==
        MISMA_ASIGNATURA);
}

void TestAcademiaRegistrarPreviaturaGeneraCiclo()
{
    Academia academia;
    Asignatura primera;
    Asignatura segunda;
    Asignatura tercera;

    CrearAcademia(academia);

    CrearAsignaturaAcademiaTest(
        primera,
        (char *)"A",
        40,
        FALSE);

    CrearAsignaturaAcademiaTest(
        segunda,
        (char *)"B",
        40,
        FALSE);

    CrearAsignaturaAcademiaTest(
        tercera,
        (char *)"C",
        40,
        FALSE);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            primera) == OK);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            segunda) == OK);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            tercera) == OK);

    assert(
        RegistrarPreviatura(
            academia,
            0,
            1) == OK);

    assert(
        RegistrarPreviatura(
            academia,
            1,
            2) == OK);

    assert(
        RegistrarPreviatura(
            academia,
            2,
            0) ==
        PREVIATURA_GENERA_CICLO);

    assert(
        EsPreviaDirecta(
            academia.previaturas,
            2,
            0) == FALSE);
}

void TestAcademiaListarPreviasAsignaturaNoExiste()
{
    Academia academia;

    CrearAcademia(academia);

    /*
     * Debe mostrar el mensaje:
     * "La asignatura no existe."
     */
    ListarPreviasAcademia(
        academia,
        10);
}

void TestAcademiaListarPreviasAsignaturaSinPrevias()
{
    Academia academia;
    Asignatura asignatura;

    CrearAcademia(academia);

    CrearAsignaturaAcademiaTest(
        asignatura,
        (char *)"Introduccion",
        50,
        FALSE);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            asignatura) == OK);

    /*
     * La asignatura 0 existe,
     * pero no tiene asignaturas previas.
     */
    ListarPreviasAcademia(
        academia,
        0);
}

void TestAcademiaListarPreviasAsignaturaConPrevias()
{
    Academia academia;
    Asignatura primera;
    Asignatura segunda;
    Asignatura tercera;

    CrearAcademia(academia);

    CrearAsignaturaAcademiaTest(
        primera,
        (char *)"Introduccion",
        40,
        FALSE);

    CrearAsignaturaAcademiaTest(
        segunda,
        (char *)"Diseno I",
        60,
        FALSE);

    CrearAsignaturaAcademiaTest(
        tercera,
        (char *)"Diseno II",
        80,
        FALSE);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            primera) == OK);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            segunda) == OK);

    assert(
        RegistrarNuevaAsignatura(
            academia,
            tercera) == OK);

    assert(
        RegistrarPreviatura(
            academia,
            0,
            1) == OK);

    assert(
        RegistrarPreviatura(
            academia,
            1,
            2) == OK);

    /*
     * Debe listar:
     *
     * 1 - Diseno I
     * 0 - Introduccion
     *
     * El orden puede variar.
     */
    ListarPreviasAcademia(
        academia,
        2);

    int previas[MAX_ASIGNATURAS - 1];
    int cantPrevias;

    PreviasDe(
        academia.previaturas,
        2,
        previas,
        cantPrevias);

    assert(cantPrevias == 2);

    Boolean estaPrimera = FALSE;
    Boolean estaSegunda = FALSE;

    for (int i = 0; i < cantPrevias; i++)
    {
        if (previas[i] == 0)
            estaPrimera = TRUE;

        if (previas[i] == 1)
            estaSegunda = TRUE;
    }

    assert(estaPrimera == TRUE);
    assert(estaSegunda == TRUE);
}

void TestAcademia()
{
    TestCrearAcademia();

    TestAcademiaRegistrarPrimeraAsignatura();

    TestAcademiaRegistrarAsignaturasConNumerosConsecutivos();

    TestAcademiaRegistrarAsignaturaSuperaMaximo();

    TestAcademiaRegistrarPreviaturaCorrecta();

    TestAcademiaRegistrarPreviaturaPrimeraNoExiste();

    TestAcademiaRegistrarPreviaturaSegundaNoExiste();

    TestAcademiaRegistrarPreviaturaMismaAsignatura();

    TestAcademiaRegistrarPreviaturaGeneraCiclo();

    TestAcademiaListarPreviasAsignaturaNoExiste();

    TestAcademiaListarPreviasAsignaturaSinPrevias();

    TestAcademiaListarPreviasAsignaturaConPrevias();
}
