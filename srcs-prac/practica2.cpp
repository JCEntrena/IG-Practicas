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

unsigned objeto_activo_2 = 0 ; // Objeto activo

// ---------------------------------------------------------------------
// Declaraciones de estructuras de datos...

std::vector<MallaInd*> figuras;

MallaPLY* ply_1 = NULL;
MallaRevol* revol_1 = NULL;
figuras.push_back(ply_1);
figuras.push_back(revol_1);

// ---------------------------------------------------------------------
// Función para implementar en la práctica para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// inicializado OpenGL.

void P2_Inicializar( int argc, char *argv[] ){
   string a, b;
   int n = 3;

   if (argc < 2){
      figuras.at(0) = new MallaPLY("../plys/beethoven.ply");
      figuras.at(1) = new MallaRevol("../plys/peon.ply", 4);
   }

   else if (argc < 3){
      figuras.at(0) = new MallaPLY(argv[2]);
      figuras.at(1) = new MallaRevol("../plys/peon.ply", 4);
   }
   if (argc >= 4){
      figuras.at(0) = new MallaPLY(argv[2]);
      figuras.at(1) = new MallaRevol(argv[3], argv[4]);
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

  	&figuras[objeto_activo_2].visualizar(modo);
}
