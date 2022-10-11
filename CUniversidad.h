#pragma once

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

// Incluir las librerías para el uso de listas.
#include <iterator>
#include <list>

// Incluir el archivo de la clase CEmpleado.h
#include "CEstudiante.h"

using namespace std;

class CUniversidad {
public:
  // Atributos.
  list<CEstudiante> listaEstudiantes;

  // Constructor y destructor.
  CUniversidad();
  ~CUniversidad();

  // Métodos.
  void registrarEstudiante(CEstudiante);
  CEstudiante buscarCarnet(int);
  void confirmarAsistencia(CEstudiante);
};
