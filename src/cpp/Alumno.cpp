#include "Alumno.h"
#include "String.h"

void CargarAlumno(Alumno &A)
{
    printf("Nombre: ");
    fflush(stdin);
    strcrear(A.nombre);
    scan(A.nombre);

    printf("Apellido: ");
    fflush(stdin);
    strcrear(A.apellido);
    scan(A.apellido);

    printf("Telefono: ");
    fflush(stdin);
    strcrear(A.telefono);
    scan(A.telefono);

    printf("Cedula: ");
    scanf("%ld", &A.cedula);

    Crear(A.escolaridad);
}
long int DarCedula(Alumno A)
{
    return A.cedula;
}

Escolaridad DarEscolaridad(Alumno A)
{
    return A.escolaridad;
}

void AgregarCursoAlumno(Alumno &A, Curso c)
{
    InsBack(A.escolaridad, c);
}

int CantidadCursosAlumno(Alumno A)
{
    return CantidadCursosEscolaridad(A.escolaridad);
}

int CantidadCursosAprobadosAlumno(Alumno A)
{
    return CantidadAprobados(A.escolaridad);
}

Boolean TieneAsignaturaAprobadaAlumno(Alumno A, int numeroAsignatura)
{
    return AsignaturaAprobada(A.escolaridad, numeroAsignatura);
}

void MostrarAlumnoEspecifico(Alumno a)
{
    printf("\n  DATOS DEL ALUMNO\n");
    printf("---------------------\n");
    printf("Cedula: %ld \n", a.cedula);
    printf("Nombre: ");
    print(a.nombre);
    printf("\nApellido: ");
    print(a.apellido);
    printf("\nTelefono: ");
    print(a.telefono);
    printf("\nCursos en escolaridad: %d", CantidadCursosAlumno(a));
    printf("\nCursos aprobados: %d", CantidadCursosAprobadosAlumno(a));
}

void MostrarEscolaridadEspecifica(Alumno a, Asignaturas asignaturas)
{
    MostrarEscolaridad(a.escolaridad, asignaturas);
}