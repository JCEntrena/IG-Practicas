// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 2  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica2.hpp"
#include <string>
#include <stdio.h>

unsigned objeto_activo_2 = 0 ; // Objeto activo

// ---------------------------------------------------------------------
// Declaraciones de estructuras de datos...

std::vector<MallaInd> figuras;

// ---------------------------------------------------------------------
// Función para implementar en la práctica para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// inicializado OpenGL.

void P2_Inicializar( int argc, char *argv[] ){
   // Para convertir char* en unsigned int
   int n = atoi(argv[3]);

   if (n < 3)
      n = 3;

   if (argc < 2){
      figuras.push_back(MallaPLY("../plys/beethoven.ply"));
      figuras.push_back(MallaRevol("../plys/peon.ply", 3));
   }

   else if (argc < 3){
      figuras.push_back(MallaPLY(argv[1]));
      figuras.push_back(MallaRevol("../plys/peon.ply", 3));
   }
   if (argc >= 4){
      figuras.push_back(MallaPLY(argv[1]));
      figuras.push_back(MallaRevol(argv[2], n));
   }

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

bool P2_FGE_PulsarTeclaNormal(unsigned char tecla){

 	if (toupper(tecla) == 'O'){
	  	objeto_activo_2 = (objeto_activo_2+1)%figuras.size();
      return true;
	}

	return false;
}

// ---------------------------------------------------------------------
// Función para dibujar los objetos, implementada en MallaInd.

void P2_DibujarObjetos(unsigned modo){
   figuras.at(objeto_activo_2).visualizar(modo);
}
