// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (declaraciones públicas)
// **
// *********************************************************************

#ifndef IG_PRACTICA3_HPP
#define IG_PRACTICA3_HPP

#include "MallaInd.hpp"
#include "matrizg.hpp"
#include "nodografoescena.hpp"

void P3_Inicializar( int argc, char *argv[] ) ;
bool P3_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P3_DibujarObjetos( unsigned modo ) ;

// -----------------------------------------------
// Clases para los objetos de nuestro diseño.

// Clase Cubo. Lee un cubo a partir de un PLY. Será el objeto que utilicemos para modelar todo nuestro diseño.
class Cubo : public class NodoGrafoEscena{
   public:
      Cubo(){
         MallaPLY *cubo = new MallaPLY("../plys/beethoven.ply");
         this.agregar(cubo);
      }
}

class Brazo : public class NodoGrafoEscena{
   public:
      Brazo(){

      }

}

class Pierna : public class NodoGrafoEscena{
   public:
      Pierna(){

      }

}

class Cabeza : public class NodoGrafoEscena{
   public:
       Cabeza(){
          
       }
}

class Tronco : public class NodoGrafoEscena{
   public:
      Tronco(){

      }
}

#endif
