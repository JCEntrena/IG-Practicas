// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4 (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica4.hpp"
#include <string>
#include <stdio.h>

using namespace std;

unsigned objeto_activo_4 = 0 ; // Objeto activo
unsigned p4_grado_libertad_activo = 0; // Grado de libertad activo
unsigned grados_libertad_4 = 2; // Ángulos alpha y beta de la fuente de luz direccional

// ---------------------------------------------------------------------
// Declaraciones de estructuras de datos...


// ---------------------------------------------------------------------
// Función para implementar en la práctica para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// inicializado OpenGL.

void P4_Inicializar( int argc, char *argv[] ){

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
void aumenta_4(){
   switch (p4_grado_libertad_activo){

      default: break;
   }

}

// Función para aumentar el grado de libertad activo. Se llama al pulsar "<"
void disminuye_4(){
   switch (p4_grado_libertad_activo){

      default: break;
   }

}


bool P4_FGE_PulsarTeclaNormal(unsigned char tecla){

   switch (toupper(tecla)){
      case 'G' :
         p4_grado_libertad_activo = (p4_grado_libertad_activo+1)%grados_libertad_4;
         switch(p4_grado_libertad_activo){

            default: break;
         }
	      return true;
      case '<' :
         disminuye_4();
         return true;
      case '>' :
         aumenta_4();
         return true;
      default :
	     return false;
   }
}

// ---------------------------------------------------------------------
// Función para dibujar los objetos, implementada en MallaInd.

void P4_DibujarObjetos(contextovis modo){

}
