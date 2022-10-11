#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "CEstudiante.h"
#include "CUniversidad.h"

using namespace std;

// Variables globales.
CUniversidad universidad;

// Función para regitrar estudiantes.
void registrarEstudiante() {
  //Definición de variables locales. 
  string asistencia = "Pendiente";
  int carnet = 0;
  string nombre = " ";
  
  // Captura de datos.
  cout << "+----------------------------------+" << endl;
  cout << "| Opción 1: Registro de estudiante |" << endl;
  cout << "+----------------------------------+" << endl << endl;
  cout << " Ingrese los siguientes datos: " << endl << endl;
  cout << " Carnet: ";
  cin >> carnet;
  cout << " Nombre: ";
  cin >> nombre;
  cout << " Asistencia: " << asistencia << endl << endl;

  // Se instancia un objeto de tipo CEmpleado.
  CEstudiante estudiante(carnet, nombre, asistencia);

  // Se registra el empleado en la lista de empleados de la empresa.
  universidad.registrarEstudiante(estudiante);

  // Mensaje para confirmar el registro.
  cout << endl;
  cout << " ¡El estudiante fue registrado éxitosamente! " << endl;
  cout << endl << endl;
}

// Función para confirmar asistencia.
void confirmarAsistencia() {
  //Definición de variables locales. 
  string asistencia = " ";
  int carnet = 0;
  string nombre = " ";
  
  // Captura de datos.
  cout << "+--------------------------------+" << endl;
  cout << "| Opción 2: Confirmar asistencia |" << endl;
  cout << "+--------------------------------+" << endl << endl;
  cout << " Ingrese los siguientes datos: " << endl << endl;
  cout << " Carnet: ";
  cin >> carnet;

  //CEstudiante estudiante = universidad.confirmarAsistencia(carnet);
  CEstudiante estudiante = universidad.buscarCarnet(carnet);
  
  if (estudiante.carnet != -1) {
    // El registro fue encontrado.
    cout << endl;
    cout << " ¿Desea confirmar la asistencia? (Si/No/Pendiente): ";
    cin >> asistencia;

    // Con los nuevos datos instanciamos un nuevo objeto de tipo CEstudiante.
    carnet = estudiante.carnet;
    nombre = estudiante.nombre;

    CEstudiante estudiante(carnet, nombre, asistencia);

    universidad.confirmarAsistencia(estudiante);

    cout << endl << " Datos actualizados: " << endl << endl;
    cout << " Carnet: " << estudiante.carnet << endl;
    cout << " Nombre: " << estudiante.nombre << endl;
    cout << " Asistencia: " << estudiante.asistencia << endl << endl << endl;

    //Mensaje al usuario.
    cout << endl;
    cout << " ¡La asistencia se asigno correctamente! " << endl;
    cout << endl << endl;
  } else {
    // El regristro no fue encontrado.
    cout << endl << endl;
    cout << " El registro no fue encontrado. " << endl;
    cout << endl << endl;
  }
}

// Función para consultar reporte.
void consultarReporte() {
  // Captura de datos.
  cout << "+-----------------------------+" << endl;
  cout << "| Opción 3: Consultar reporte |" << endl;
  cout << "+-----------------------------+" << endl << endl;
  
  // Declaración de variable iterador.
  list<CEstudiante>::iterator it;

  // Ciclo.
  for (it = universidad.listaEstudiantes.begin(); it != universidad.listaEstudiantes.end();
       ++it) {
    cout << " Carnet: " << (*it).carnet << endl;
    cout << " Nombre: " << (*it).nombre << endl;
    cout << " Asistencia: " << (*it).asistencia << endl << endl;
  }
  cout << endl << endl << endl;
}

// Funcion principal.
int main() {
  // Definición de variables locales.
  int lnRespuesta = 0;

  // Ciclo + Menú de opciones.
  do {
    cout << endl << endl;
    cout << "  R E G I S T R O    D E    E S T U D I A N T E S " << endl;
    cout << "*-------------------------------------------------*" << endl;
    cout << "| 1. Registrar estudiante                         |" << endl;
    cout << "| 2. Confirmar asistencia                         |" << endl;
    cout << "| 3. Consultar reporte                            |" << endl;
    cout << "| 4. Salir                                        |" << endl;
    cout << "*-------------------------------------------------*" << endl << endl;
    cout << " ¿Qué operación desea realizar? (1 - 4): ";
    cin >> lnRespuesta;
    cout << endl << endl;

    // Condición.
    switch (lnRespuesta) {
    case 1:
      registrarEstudiante();
      break;

    case 2:
      confirmarAsistencia();
      break;

    case 3:
      consultarReporte();
      break;

    case 4:
      lnRespuesta = 4;
      break;

      default:
        cout << endl;
        cout << " La opción ingresada no es correcta, intente de nuevo... " << endl;
        cout << endl;
        break;
    }
  } while (lnRespuesta != 4);
  
  //Impresión de título.
  cout << " #=================================================================#" << endl;
  cout << " | G R A C I A S   P O R   U S A R   N U E S T R O   S I S T E M A |" << endl;
  cout << " #=================================================================#" << endl;
  
  return 0;
}
