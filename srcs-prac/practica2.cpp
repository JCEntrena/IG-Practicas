// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 2  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica2.hpp"

unsigned objeto_activo = 0 ; // Objeto activo

// ---------------------------------------------------------------------
// Declaraciones de estructuras de datos...

std::vector<MallaInd> fig; 


// ---------------------------------------------------------------------
// Función para implementar en la práctica para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// inicializado OpenGL. 

void P2_Inicializar( int argc, char *argv[] ){
     
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

 	if (toupper(tecla) == 'C'){
	  	objeto_activo = (objeto_activo+1)%fig.size();
      return true;  
	}

	return false; 
}


// ---------------------------------------------------------------------
// Función para dibujar los objetos, implementada en MallaInd. 

void P2_DibujarObjetos(unsigned modo){

  	fig[objeto_activo].visualizar(modo); 

}

