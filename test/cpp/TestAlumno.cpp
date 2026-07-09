#include "../../src/include/Alumno.h"
#include "../../src/include/String.h"
#include "../../src/include/Boolean.h"
#include "../include/TestAlumno.h"

#include <cassert>
#include <cstdio>





void TestCargayDarDatosAlumno()
{
    Alumno A;

    FILE *archivo = fopen("build/input_alumno.txt", "w");
    assert(archivo != NULL);

    
    fprintf(archivo, "Carolina\n");
    fprintf(archivo, "Perez\n");
    fprintf(archivo, "099123456\n");
    fprintf(archivo, "12345678\n");

    fclose(archivo);

    FILE *entrada = freopen("build/input_alumno.txt", "r", stdin);
    assert(entrada != NULL);

    CargarAlumno(A);
    long int ci = 12345678;
    printf("cedula %ld\n", DarCedula(A));
    assert(DarCedula(A) == ci);
    assert(CantidadCursosAlumno(A) == 0);
    assert(CantidadCursosAprobadosAlumno(A) == 0);

    String nombreObtenido, apellidoObtenido, telefonoObtenido;
    strcrear(nombreObtenido);
    strcrear(apellidoObtenido);
    strcrear(telefonoObtenido);

    DarNombre(A, nombreObtenido);
    DarApellido(A, apellidoObtenido);
    DarTelefono(A, telefonoObtenido);

    assert(streq(nombreObtenido, (char *)"Carolina") == TRUE);
    assert(streq(apellidoObtenido, (char *)"Perez") == TRUE);
    assert(streq(telefonoObtenido, (char *)"099123456") == TRUE);

    strdestruir(nombreObtenido);
    strdestruir(apellidoObtenido);
    strdestruir(telefonoObtenido);

    Alumno B;

    FILE *archivo2 = fopen("build/input_alumno_2.txt", "w");
    assert(archivo2 != NULL);

   
    fprintf(archivo2, "Matias\n");
    fprintf(archivo2, "Mirenda\n");
    fprintf(archivo2, "098765432\n");
     fprintf(archivo2, "87654321\n");

    fclose(archivo2);

    FILE *entrada2 = freopen("build/input_alumno_2.txt", "r", stdin);
    assert(entrada2 != NULL);

    CargarAlumno(B);

    assert(DarCedula(B) == 87654321);

    String nombreObtenido2;
    strcrear(nombreObtenido2);
    DarNombre(B, nombreObtenido2);
    assert(streq(nombreObtenido2, (char *)"Matias") == TRUE);
    strdestruir(nombreObtenido2);
}

void TestAgregarCursoAlumno()
{
    Alumno A;
    String nombre = (char *)"Juan";
    String apellido = (char *)"Gomez";
    String telefono = (char *)"091111111";
    Crear(A.escolaridad);  

    A.nombre = nombre;
    A.apellido = apellido;
    A.telefono = telefono;

    Curso c;
    c.numeroAsignatura = 1;
    c.fechaFinalizacion = {2023, 5, 15};
    c.calificacion = 8;

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
    A.nombre = nombre;
    A.apellido = apellido;
    A.telefono = telefono;
    Crear(A.escolaridad);  

    Curso aprobado;
    aprobado.numeroAsignatura = 5;
    aprobado.fechaFinalizacion = {2023, 5, 15};
    aprobado.calificacion = 9;

    Curso noAprobado;
    noAprobado.numeroAsignatura = 6;
    noAprobado.fechaFinalizacion = {2023, 5, 15};
    noAprobado.calificacion = 2;

    AgregarCursoAlumno(A, aprobado);
    AgregarCursoAlumno(A, noAprobado);

    assert(TieneAsignaturaAprobadaAlumno(A, 5) == TRUE);
    assert(TieneAsignaturaAprobadaAlumno(A, 6) == FALSE);
    printf("cantidad cursos %d\n", CantidadCursosAlumno(A));
    assert(CantidadCursosAlumno(A) == 2);
    assert(CantidadCursosAprobadosAlumno(A) == 1);
}