#ifndef MENU_H
#define MENU_H

#include "Academia.h"

void MostrarMenu();

void OpcionRegistrarAsignatura(Academia &academia);

void OpcionRegistrarPreviatura(Academia &academia);

void OpcionListarPrevias(Academia academia);

void EjecutarMenu(Academia &academia);

#endif