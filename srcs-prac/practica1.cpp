// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica1.hpp"
#include <vector>

unsigned objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos...

std::vector<MallaInd> fig; 


// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// inicializado OpenGL. 

void P1_Inicializar( int argc, char *argv[] )
{
   
    Cubo cubo(); 
    Tetraedro tetraedro();    
     
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar 
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
   // ........
   return false ;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P1_DibujarObjetos( unsigned modo ) 
{
  

}

//----------------------------------------------------------------------
// Constructores para el Cubo y el Tetraedro. 

Cubo::Cubo(){
    // Inclusión de los vértices. 
    vertices.push_back(Tupla3f(1,0,0)); 
    vertices.push_back(Tupla3f(1,1,0));
    vertices.push_back(Tupla3f(0,1,0));
    vertices.push_back(Tupla3f(0,0,0));
    vertices.push_back(Tupla3f(1,0,1));
    vertices.push_back(Tupla3f(1,1,1));
    vertices.push_back(Tupla3f(0,1,1));
    vertices.push_back(Tupla3f(0,0,1));

    // Inclusión de los índices 


}

Tetraedro::Tetraedro(){
    // Inclusión de los vértices. 
    vertices.push_back(Tupla3f(0,0,1)); 
    

}
