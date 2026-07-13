#include "../include/Alumnos.h"

void CrearAlumnos(Alumnos &alumnos)
{
    Crear(alumnos);
}

Boolean ExisteAlumno(Alumnos alumnos, long int cedula)
{
    return Pertenece(alumnos, cedula);
}

void InscribirAlumno(Alumnos &alumnos, Alumno a)
{
    Insertar(alumnos, a);
}

Alumno ObtenerAlumno(Alumnos alumnos, long int cedula)
{
    return Obtener(alumnos, cedula);
}

void ModificarAlumno(Alumnos &alumnos, Alumno a)
{
    Eliminar(alumnos, a.cedula);
    Insertar(alumnos, a);
}

void MostrarAlumno(Alumnos alumnos, long int cedula)
{

    MostrarAlumnoEspecifico(ObtenerAlumno(alumnos, cedula));
}
