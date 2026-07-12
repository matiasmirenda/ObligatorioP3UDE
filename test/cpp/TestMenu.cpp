#include "../../src/include/Menu.h"
#include "../include/TestMenu.h"

#include <assert.h>
#include <stdio.h>

static void PrepararEntradaMenu(
    const char nombreArchivo[],
    const char contenido[])
{
    FILE *archivo =
        fopen(
            nombreArchivo,
            "w");

    assert(archivo != NULL);

    fprintf(
        archivo,
        "%s",
        contenido);

    fclose(archivo);

    FILE *entrada =
        freopen(
            nombreArchivo,
            "r",
            stdin);

    assert(entrada != NULL);
}

void TestOpcionRegistrarAsignatura()
{
    Academia academia;

    CrearAcademia(academia);

    PrepararEntradaMenu(
        "build/entrada_asignatura_menu.txt",
        "Programacion III\n"
        "96\n"
        "0\n");

    OpcionRegistrarAsignatura(
        academia);

    assert(
        CantidadAsignaturas(
            academia.asignaturas) == 1);

    assert(
        ExisteAsignatura(
            academia.asignaturas,
            0) == TRUE);

    Asignatura asignatura =
        ObtenerAsignatura(
            academia.asignaturas,
            0);

    assert(
        DarNumeroAsignatura(
            asignatura) == 0);

    assert(
        streq(
            DarNombreAsignatura(asignatura),
            (char *)"Programacion III") == TRUE);

    assert(
        DarCantidadHorasAsignatura(asignatura) ==
        96);

    assert(
        EsAsignaturaOptativa(asignatura) ==
        FALSE);
}

void TestOpcionRegistrarPreviatura()
{
    Academia academia;
    Asignatura primera;
    Asignatura segunda;

    CrearAcademia(academia);

    strcrear(primera.nombre);

    strcop(
        primera.nombre,
        (char *)"Introduccion");

    primera.cantidadHoras = 40;
    primera.esOptativa = FALSE;

    strcrear(segunda.nombre);

    strcop(
        segunda.nombre,
        (char *)"Diseno I");

    segunda.cantidadHoras = 60;
    segunda.esOptativa = FALSE;

    RegistrarNuevaAsignatura(
        academia,
        primera);

    RegistrarNuevaAsignatura(
        academia,
        segunda);

    PrepararEntradaMenu(
        "build/entrada_previatura_menu.txt",
        "0\n"
        "1\n");

    OpcionRegistrarPreviatura(
        academia);

    assert(
        EsPreviaDirecta(
            academia.previaturas,
            0,
            1) == TRUE);
}

void TestOpcionListarPrevias()
{
    Academia academia;
    Asignatura primera;
    Asignatura segunda;

    CrearAcademia(academia);

    strcrear(primera.nombre);

    strcop(
        primera.nombre,
        (char *)"Introduccion");

    primera.cantidadHoras = 40;
    primera.esOptativa = FALSE;

    strcrear(segunda.nombre);

    strcop(
        segunda.nombre,
        (char *)"Diseno I");

    segunda.cantidadHoras = 60;
    segunda.esOptativa = FALSE;

    RegistrarNuevaAsignatura(
        academia,
        primera);

    RegistrarNuevaAsignatura(
        academia,
        segunda);

    RegistrarPreviatura(
        academia,
        0,
        1);

    PrepararEntradaMenu(
        "build/entrada_listar_previas_menu.txt",
        "1\n");

    OpcionListarPrevias(
        academia);

    assert(
        EsPreviaDirecta(
            academia.previaturas,
            0,
            1) == TRUE);
}

void TestMostrarMenu()
{
    MostrarMenu();
}

void TestEjecutarMenuSalir()
{
    Academia academia;

    CrearAcademia(academia);

    PrepararEntradaMenu(
        "build/entrada_menu_salir.txt",
        "0\n");

    EjecutarMenu(academia);
}

void TestEjecutarMenuOpcionInvalida()
{
    Academia academia;

    CrearAcademia(academia);

    PrepararEntradaMenu(
        "build/entrada_menu_invalida.txt",
        "99\n"
        "0\n");

    EjecutarMenu(academia);
}

void TestMenu()
{
    TestMostrarMenu();
    TestOpcionRegistrarAsignatura();
    TestOpcionRegistrarPreviatura();
    TestOpcionListarPrevias();
    TestEjecutarMenuSalir();
    TestEjecutarMenuOpcionInvalida();
}
