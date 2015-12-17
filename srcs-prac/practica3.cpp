// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica3.hpp"
#include <string>
#include <stdio.h>

using namespace std;

unsigned objeto_activo_3 = 0 ; // Objeto activo
unsigned p3_grado_libertad_activo = 0; // Grado de libertad activo
unsigned grados_libertad = 3;

// ---------------------------------------------------------------------
// Declaraciones de estructuras de datos...

Figura* figur;

// ---------------------------------------------------------------------
// Función para implementar en la práctica para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// inicializado OpenGL.

void P3_Inicializar( int argc, char *argv[] ){
   figur = new Figura();
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar
//    entre objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)


// Función para aumentar el grado de libertad activo. Se llama al pulsar ">"
void aumenta(){
   switch (p3_grado_libertad_activo){
      case 0:  // Mover los brazos.
         figur->RotaBrazos(true);
         break;
      case 1:  // Mover la pierna izquierda.
         figur->RotaPiernaI(true);
         break;
      case 2:  // Mover la caja.
         figur->MueveCaja(true);
         break;
      default: break;
   }

}

// Función para aumentar el grado de libertad activo. Se llama al pulsar "<"
void disminuye(){
   switch (p3_grado_libertad_activo){
      case 0:
         figur->RotaBrazos(false);
         break;
      case 1:
         figur->RotaPiernaI(false);
         break;
      case 2:
         figur->MueveCaja(false);
         break;
      default: break;
   }

}


bool P3_FGE_PulsarTeclaNormal(unsigned char tecla){

   switch (toupper(tecla)){
      //case 'O' :
         //return true;
      case 'G' :
         p3_grado_libertad_activo = (p3_grado_libertad_activo+1)%grados_libertad;
         switch(p3_grado_libertad_activo){
            case 0:
               cout << "Grado de libertad 1: Rotación de los brazos." << endl;
               break;
            case 1:
               cout << "Grado de libertad 2: Rotación de la pierna izquierda." << endl;
               break;
            case 2:
               cout << "Grado de libertad 3: Movimiento de la caja." << endl;
               break;
            default: break;
         }
	      return true;
      case '<' :
         disminuye();
         return true;
      case '>' :
         aumenta();
         return true;
      default :
	     return false;
   }
}

// ---------------------------------------------------------------------
// Función para dibujar los objetos, implementada en MallaInd.

void P3_DibujarObjetos(unsigned modo){
   figur->visualizar(modo);
}
