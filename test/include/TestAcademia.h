#ifndef TESTACADEMIA_H
#define TESTACADEMIA_H

void TestInscribirAlumnoAcademia();
void TestRegistrarCursoAcademia_AlumnoNoExiste();
void TestRegistrarCursoAcademia_AsignaturaNoExiste();
void TestRegistrarCursoAcademia_Exitoso();
void TestRegistrarCursoAcademia_YaAprobada();
void TestRegistrarCursoAcademia_PreviasNoAprobadas();
void TestRegistrarCursoAcademia_FechaAnterior();
void TestCrearAcademia();

void TestAcademiaRegistrarPrimeraAsignatura();

void TestAcademiaRegistrarAsignaturasConNumerosConsecutivos();

void TestAcademiaRegistrarAsignaturaSuperaMaximo();

void TestAcademiaRegistrarPreviaturaCorrecta();

void TestAcademiaRegistrarPreviaturaPrimeraNoExiste();

void TestAcademiaRegistrarPreviaturaSegundaNoExiste();

void TestAcademiaRegistrarPreviaturaMismaAsignatura();

void TestAcademiaRegistrarPreviaturaGeneraCiclo();

void TestAcademiaListarPreviasAsignaturaNoExiste();

void TestAcademiaListarPreviasAsignaturaSinPrevias();

void TestAcademiaListarPreviasAsignaturaConPrevias();

void TestAcademia();

#endif