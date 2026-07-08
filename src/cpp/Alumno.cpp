#include "Alumno.h"
#include "String.h"


void CrearAlumno(Alumno &A, long int cedula, String nombre, String apellido, String telefono){
     A.cedula = cedula;
    strcrear(A.nombre);
    strcrear(A.apellido);
    strcrear(A.telefono);
    strcop(A.nombre, nombre);
    strcop(A.apellido, apellido);
    strcop(A.telefono, telefono);
    CrearEscolaridad(A.escolaridad);
}

long int DarCedula(Alumno A) { 
    return A.cedula; 
}

void DarNombre(Alumno A, String &nombre) { 
    strcop(nombre, A.nombre); 
}
void DarApellido(Alumno A, String &apellido) { 
    strcop(apellido, A.apellido); 
}
void DarTelefono(Alumno A, String &telefono) { 
    strcop(telefono, A.telefono); 
}

Escolaridad DarEscolaridad(Alumno A) {
     return A.escolaridad; 
}

void AgregarCursoAlumno(Alumno &A, Curso c){
    AgregarCurso(A.escolaridad, c);
}

int CantidadCursosAlumno(Alumno A){
    return CantidadCursos(A.escolaridad);
}

int CantidadCursosAprobadosAlumno(Alumno A){
    return CantidadCursosAprobados(A.escolaridad);
}

Boolean TieneAsignaturaAprobadaAlumno(Alumno A, int numeroAsignatura){
    return TieneAsignaturaAprobada(A.escolaridad, numeroAsignatura);
}