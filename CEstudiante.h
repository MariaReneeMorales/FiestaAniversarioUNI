#pragma once

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class CEstudiante {
public:
  int carnet;
  string nombre;
  string asistencia;

  // Constructor y destructor.
  CEstudiante();
  ~CEstudiante();

  // Constructor personalizado.
  CEstudiante(int, string, string);
}; // La definición de la clase termina con ;.
