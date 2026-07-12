#include "../../src/include/Academia.h"
#include "../../src/include/Alumno.h"
#include "../../src/include/Asignatura.h"
#include "../../src/include/String.h"
#include "../../src/include/Boolean.h"
#include "../include/TestAcademia.h"

#include <cassert>

// Operacion auxiliar de test: arma un Alumno "a mano" (sin pasar
// por CargarAlumno, que pide datos por teclado), dejando su
// escolaridad correctamente inicializada.
Alumno CrearAlumnoDeTest(long int cedula, String nombre, String apellido, String telefono)
{
    Alumno a;
    a.cedula = cedula;
    a.nombre = nombre;
    a.apellido = apellido;
    a.telefono = telefono;
    Crear(a.escolaridad);
    return a;
}

// Operacion auxiliar de test: arma una Asignatura "a mano".
Asignatura CrearAsignaturaDeTest(String nombre, int cantidadHoras, Boolean esOptativa)
{
    Asignatura a;
    a.nombre = nombre;
    a.cantidadHoras = cantidadHoras;
    a.esOptativa = esOptativa;
    return a;
}

// ------------------------------------------------------------
// Punto 3: InscribirAlumnoAcademia
// ------------------------------------------------------------
void TestInscribirAlumnoAcademia()
{
    Academia ac;
    CrearAcademia(ac);

    Alumno original = CrearAlumnoDeTest(11111111, (char *)"Juan", (char *)"Perez", (char *)"099111111");
    InscribirAlumnoAcademia(ac, original);

    assert(ExisteAlumno(ac.alumnos, 11111111) == TRUE);

    // Intento de duplicado: misma cedula, datos distintos.
    Alumno duplicado = CrearAlumnoDeTest(11111111, (char *)"Pedro", (char *)"Gomez", (char *)"099222222");
    InscribirAlumnoAcademia(ac, duplicado);

    // El duplicado NO debe haber pisado los datos originales.
    Alumno guardado = ObtenerAlumno(ac.alumnos, 11111111);
    String nombreGuardado;
    strcrear(nombreGuardado);
    DarNombre(guardado, nombreGuardado);
    assert(streq(nombreGuardado, (char *)"Juan") == TRUE);
    strdestruir(nombreGuardado);
}

// ------------------------------------------------------------
// Punto 4: RegistrarCursoAcademia
// ------------------------------------------------------------

void TestRegistrarCursoAcademia_AlumnoNoExiste()
{
    Academia ac;
    CrearAcademia(ac);

    Fecha f = {1, 1, 2023};

    // No hay ningun alumno inscripto: solo verificamos que no explota.
    RegistrarCursoAcademia(ac, 99999999, 0, f, 8);

    assert(ExisteAlumno(ac.alumnos, 99999999) == FALSE);
}

void TestRegistrarCursoAcademia_AsignaturaNoExiste()
{
    Academia ac;
    CrearAcademia(ac);

    Alumno alumno = CrearAlumnoDeTest(22222222, (char *)"Ana", (char *)"Lopez", (char *)"099333333");
    InscribirAlumnoAcademia(ac, alumno);

    Fecha f = {1, 1, 2023};

    // No se registro ninguna asignatura todavia.
    RegistrarCursoAcademia(ac, 22222222, 0, f, 8);

    Alumno guardado = ObtenerAlumno(ac.alumnos, 22222222);
    assert(CantidadCursosAlumno(guardado) == 0);
}

void TestRegistrarCursoAcademia_Exitoso()
{
    Academia ac;
    CrearAcademia(ac);

    Asignatura progI = CrearAsignaturaDeTest((char *)"Programacion I", 96, FALSE);
    RegistrarAsignatura(ac.asignaturas, progI); // queda registrada con numero 0

    Alumno alumno = CrearAlumnoDeTest(33333333, (char *)"Matias", (char *)"Mirenda", (char *)"099444444");
    InscribirAlumnoAcademia(ac, alumno);

    Fecha f = {15, 5, 2023};
    RegistrarCursoAcademia(ac, 33333333, 0, f, 8);

    Alumno guardado = ObtenerAlumno(ac.alumnos, 33333333);
    assert(CantidadCursosAlumno(guardado) == 1);
    assert(TieneAsignaturaAprobadaAlumno(guardado, 0) == TRUE);
}

void TestRegistrarCursoAcademia_YaAprobada()
{
    Academia ac;
    CrearAcademia(ac);

    Asignatura progI = CrearAsignaturaDeTest((char *)"Programacion I", 96, FALSE);
    RegistrarAsignatura(ac.asignaturas, progI); // numero 0

    Alumno alumno = CrearAlumnoDeTest(44444444, (char *)"Carolina", (char *)"Gutierrez", (char *)"099555555");
    InscribirAlumnoAcademia(ac, alumno);

    Fecha f1 = {15, 5, 2023};
    RegistrarCursoAcademia(ac, 44444444, 0, f1, 8); // primera vez: exitosa

    Fecha f2 = {20, 6, 2023};
    RegistrarCursoAcademia(ac, 44444444, 0, f2, 9); // segunda vez: debe rechazarse

    Alumno guardado = ObtenerAlumno(ac.alumnos, 44444444);
    assert(CantidadCursosAlumno(guardado) == 1); // no se agrego el segundo intento
}

void TestRegistrarCursoAcademia_PreviasNoAprobadas()
{
    Academia ac;
    CrearAcademia(ac);

    Asignatura progI = CrearAsignaturaDeTest((char *)"Programacion I", 96, FALSE);
    Asignatura progII = CrearAsignaturaDeTest((char *)"Programacion II", 96, FALSE);
    RegistrarAsignatura(ac.asignaturas, progI);  // numero 0
    RegistrarAsignatura(ac.asignaturas, progII); // numero 1

    AgregarPrevia(ac.previaturas, 0, 1); // 0 es previa de 1

    Alumno alumno = CrearAlumnoDeTest(55555555, (char *)"Sofia", (char *)"Diaz", (char *)"099666666");
    InscribirAlumnoAcademia(ac, alumno);

    Fecha f = {1, 3, 2023};
    // Intenta cursar la 1 sin tener aprobada la 0 (su previa inmediata).
    RegistrarCursoAcademia(ac, 55555555, 1, f, 8);

    Alumno guardado = ObtenerAlumno(ac.alumnos, 55555555);
    assert(CantidadCursosAlumno(guardado) == 0);
}

void TestRegistrarCursoAcademia_FechaAnterior()
{
    Academia ac;
    CrearAcademia(ac);

    Asignatura progI = CrearAsignaturaDeTest((char *)"Programacion I", 96, FALSE);
    Asignatura progII = CrearAsignaturaDeTest((char *)"Programacion II", 96, FALSE);
    RegistrarAsignatura(ac.asignaturas, progI);  // numero 0
    RegistrarAsignatura(ac.asignaturas, progII); // numero 1
    // Sin previas entre ellas, para aislar el chequeo de fecha.

    Alumno alumno = CrearAlumnoDeTest(66666666, (char *)"Lucia", (char *)"Fernandez", (char *)"099777777");
    InscribirAlumnoAcademia(ac, alumno);

    Fecha primeraFecha = {15, 5, 2023};
    RegistrarCursoAcademia(ac, 66666666, 0, primeraFecha, 8);

    Fecha fechaAnterior = {10, 3, 2023}; // anterior a la primera
    RegistrarCursoAcademia(ac, 66666666, 1, fechaAnterior, 8);

    Alumno guardado = ObtenerAlumno(ac.alumnos, 66666666);
    assert(CantidadCursosAlumno(guardado) == 1); // el segundo intento no se agrego
}


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
