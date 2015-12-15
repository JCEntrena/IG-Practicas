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

unsigned objeto_activo_3 = 0 ; // Objeto activo
unsigned p3_grado_libertad_activo = 0; // Grado de libertad activo
unsigned grados_libertad = 3;

// ---------------------------------------------------------------------
// Declaraciones de estructuras de datos...

std::vector<MallaInd> figur;

// ---------------------------------------------------------------------
// Función para implementar en la práctica para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// inicializado OpenGL.

void P3_Inicializar( int argc, char *argv[] ){

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

bool P3_FGE_PulsarTeclaNormal(unsigned char tecla){

   switch (toupper(tecla)){
      case 'O' :
	  	   objeto_activo_3 = (objeto_activo_3+1)%figur.size();
         return true;
      case 'G' :
         p3_grado_libertad_activo = (p3_grado_libertad_activo+1)%grados_libertad;
	      return true;
      case '<' :
         // ...
         return true;
      case '>' :
         // ...
         return true;
      default :
	     return false;
   }
}

// ---------------------------------------------------------------------
// Función para dibujar los objetos, implementada en MallaInd.

void P3_DibujarObjetos(unsigned modo){
   //figur.at(objeto_activo_3).visualizar(modo);
}
