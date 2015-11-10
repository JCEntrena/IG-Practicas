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

   // Sin argumentos
   if (argc < 2){
      figuras.push_back(MallaPLY("../plys/beethoven.ply"));
      figuras.push_back(MallaRevol("../plys/peon.ply", 3));
      figuras.push_back(MallaBarrido("../plys/peon.ply", 1, 1, 1, 3));
   }
   // Se proporciona un PLY
   else if (argc == 2){
      figuras.push_back(MallaPLY(argv[1]));
      figuras.push_back(MallaRevol("../plys/peon.ply", 3));
      figuras.push_back(MallaBarrido("../plys/peon.ply", 1, 1, 1, 3));
   }
   // Se da un PLY y una MallaRevol y el número de perfiles.
   else if (argc == 4){
      int n1 = atoi(argv[3]);
      figuras.push_back(MallaPLY(argv[1]));
      figuras.push_back(MallaRevol(argv[2], n1));
      figuras.push_back(MallaBarrido("../plys/peon.ply", 1, 1, 1, 3));
   }
   // Se dan un PLY, una MallaRevol con número de perfiles y una MallaBarrido con vector de desplazamiento y número de desplazamientos.
   else if (argc == 9){
      int n1 = atoi(argv[3]);
      int n2 = atoi(argv[8]);
      int x = atoi(argv[5]), y = atoi(argv[6]), z = atoi(argv[7]);

      figuras.push_back(MallaPLY(argv[1]));
      figuras.push_back(MallaRevol(argv[2], n1));
      figuras.push_back(MallaBarrido(argv[4], x, y, z, n2));
   }
   else{
      std::cout << "El número de argumentos introducido no es correcto.\n";
      exit(-1);
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
