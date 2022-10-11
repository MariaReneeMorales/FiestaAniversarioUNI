#include "CEstudiante.h"

// Sintaxis para colocar métodos.
// Nombre de la clase :: Nombre del método.

// Constructor.
CEstudiante::CEstudiante() {}

// Constructor personalizado.
CEstudiante::CEstudiante(int carnet, string nombre, string asistencia) {
  // Llenando los atributos de la clase.
  this->carnet = carnet;
  this->nombre = nombre;
  this->asistencia = asistencia;
}

// Destructor.
CEstudiante::~CEstudiante() {}
