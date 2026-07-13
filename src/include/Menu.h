#ifndef MENU_H
#define MENU_H

#include "Academia.h"

void MostrarMenu();

void OpcionRegistrarAsignatura(Academia &academia);

void OpcionRegistrarPreviatura(Academia &academia);

void OpcionInscribirAlumno(Academia &academia);

void OpcionRegistrarCursoEscolaridad(Academia &academia);

void OpcionListarAsignaturas(Academia academia);

void OpcionListarPrevias(Academia academia);

void OpcionMostrarAlumno(Academia academia);

void OpcionMostrarEscolaridad(Academia academia);

void EjecutarMenu(Academia &academia);

#endif