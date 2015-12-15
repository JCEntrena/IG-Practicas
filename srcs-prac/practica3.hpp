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
#include "matrices-tr.hpp"

void P3_Inicializar( int argc, char *argv[] ) ;
bool P3_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P3_DibujarObjetos( unsigned modo ) ;

// -----------------------------------------------
// Clases para los objetos de nuestro diseño.

// Clase Cubo. Lee un cubo a partir de un PLY. Será el objeto que utilicemos para modelar todo nuestro diseño.
class Cubo : public NodoGrafoEscena{
   public:
      Cubo(){
         MallaPLY *cubo = new MallaPLY("../plys/cube.ply");
         agregar(cubo);
      }
};

class Brazo : public NodoGrafoEscena{
   public:
      Brazo(){
         agregar(MAT_Escalado(0.6, 1.25, 0.5));
         agregar(new Cubo());
      }
};

class BrazoDerecho : public NodoGrafoEscena{
   public:
      BrazoDerecho(){
         agregar(MAT_Traslacion(1.55, 2.25, 0.0));
         agregar(MAT_Rotacion(0, 0, 0, 1));
         agregar(new Brazo());
      }
      void rotar(bool sentido_horario){

      }
};

class BrazoIzquierdo : public NodoGrafoEscena{
   public:
      BrazoIzquierdo(){
         agregar(MAT_Traslacion(-0.65, 2.25, 0.0));
         agregar(MAT_Rotacion(0, 0, 0, 1));
         agregar(new Brazo());
      }
};

class PiernaIzquierda : public NodoGrafoEscena{
   public:
      PiernaIzquierda(){
         agregar(MAT_Escalado(0.6, 1.45, 0.5));
         agregar(MAT_Rotacion(0, 0, 0, 1));
         agregar(new Cubo());
      }

};

class Cabeza : public NodoGrafoEscena{
   public:
       Cabeza(){
          agregar(MAT_Traslacion(0.25, 4.05, -0.25));
          agregar(new Cubo());
       }
};

class Tronco : public NodoGrafoEscena{
   public:
      Tronco(){
         agregar(MAT_Escalado(1.5, 2.5, 1.5));
         agregar(MAT_Traslacion(0.0, 1.5, -0.5));
         agregar(new Cubo());
      }
};

class Caja : public NodoGrafoEscena{
   private:
      int desplazamiento;
   public:
      Caja(){
         desplazamiento = 0;
         agregar(MAT_Traslacion(-0.2, 0.0, 0.6));
         agregar(MAT_Traslacion(0.0, 0.0, 0.0));
         agregar(new Cubo());
      }
      void desplazar_adelante(){
         if (desplazamiento < 10){
            desplazamiento++;
            entradas[2] = MAT_Traslacion(0.0, 0.0, desplazamiento);
         }
      }
      void desplazar_atras(){
         if (desplazamiento > 0){
            desplazamiento--;
            entradas[2] = (MAT_Traslacion(0.0, 0.0, desplazamiento));
         }
      }
};

#endif
