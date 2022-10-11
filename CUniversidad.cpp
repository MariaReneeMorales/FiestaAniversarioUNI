#include "CUniversidad.h"

// Construcutor.
CUniversidad::CUniversidad() {}

// Destructor.
CUniversidad::~CUniversidad() {}

// Métodos.
void CUniversidad::registrarEstudiante(CEstudiante estudiante) {
  // Inserta el objeto al final de la lista.
  listaEstudiantes.push_back(estudiante);
}

CEstudiante CUniversidad::buscarCarnet(int carnet) {
  // Declaremos un objeto vacio de tipo CEstudiante.
  // Se coloca -1 para decir si fue encontrado o no en el registro.
  CEstudiante estudiante(-1, " ", " ");

  list<CEstudiante>::iterator it;
  for (it = listaEstudiantes.begin(); it != listaEstudiantes.end(); ++it) {
    if ((*it).carnet == carnet) {
      // Este es el número del carnet que se va a confirmar.
      estudiante = (*it);
      break;
    }
  }
  return estudiante;
} 

void CUniversidad::confirmarAsistencia(CEstudiante estudiante) {
  list<CEstudiante>::iterator it;
  for (it = listaEstudiantes.begin(); it != listaEstudiantes.end(); ++it) {
    if ((*it).carnet == estudiante.carnet) {
      // Este es el número de carnet del registro a confirmar.
      *it = estudiante;
      break;
    }
  }
}
