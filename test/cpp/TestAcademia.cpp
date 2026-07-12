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

    AgregarPrevia(ac.previas, 0, 1); // 0 es previa de 1

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