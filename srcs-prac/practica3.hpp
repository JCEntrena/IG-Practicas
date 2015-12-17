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
      int rotacion;

      BrazoDerecho(){
         rotacion = 0;
         agregar(MAT_Traslacion(1.55, 2.25, 0.0));
         agregar(MAT_Rotacion(0, 0, 0, 0));
         agregar(new Brazo());
      }

      // Función de rotación del brazo. Rotará libremente con incrementos de 10º, partiendo desde 0º.
      void rotar(bool sentido_horario){
         // Si es en sentido horario:
         if (sentido_horario)
            rotacion--;
         // En otro caso, sentido antihorario.
         else
            rotacion++;

         entradas[1] = MAT_Rotacion((rotacion%36)*10, 1, 0, 0);
      }
};

class BrazoIzquierdo : public NodoGrafoEscena{
   public:
      int rotacion;

      BrazoIzquierdo(){
         rotacion = 0;
         agregar(MAT_Traslacion(-0.65, 2.25, 0.0));
         agregar(MAT_Rotacion(0, 0, 0, 0));
         agregar(new Brazo());
      }

      // Función de rotación del brazo. Rotará libremente con incrementos de 10º, partiendo desde 0º.
      void rotar(bool sentido_horario){
         // Si es en sentido horario:
         if (sentido_horario)
            rotacion--;
         // En otro caso, sentido antihorario.
         else
            rotacion++;

         entradas[1] = MAT_Rotacion((rotacion%36)*10, 1, 0, 0);
      }
};

class PiernaIzquierda : public NodoGrafoEscena{
   public:
      int rotacion;  // Ángulo de rotación.

      PiernaIzquierda(){
         rotacion = 0;
         agregar(MAT_Escalado(0.6, 1.45, 0.5));
         agregar(MAT_Rotacion(0, 0, 0, 0));
         agregar(new Cubo());
      }

      // Función de rotación. Permitimos que la pierna rote de -60º a 60º, partiendo desde 0º.
      // El incremento será de 10º tanto positivo como negativo.
      void rotar(bool sentido_horario){
         // Sentido horario.
         if (sentido_horario){
            if (rotacion > -6)
               rotacion--;
         }

         // En otro caso, sentido antihorario.
         else
            if (rotacion < 6)
               rotacion++;

         entradas[1] = MAT_Rotacion((rotacion%36)*10, 1, 0, 0);
      }

};

class PiernaDerecha : public NodoGrafoEscena{
   public:
      int rotacion;  // Ángulo de rotación.

      PiernaDerecha(){
         rotacion = 0;
         agregar(MAT_Traslacion(0.9, 0, 0));
         agregar(MAT_Rotacion(0, 0, 0, 0));
         agregar(new PiernaIzquierda());
      }

      // Función de rotación. Permitimos que la pierna rote de -60º a 60º, partiendo desde 0º.
      // El incremento será de 10º tanto positivo como negativo.
      void rotar(bool sentido_horario){
         // Sentido horario.
         if (sentido_horario)
            if (rotacion > -6)
               rotacion--;

         // En otro caso, sentido antihorario.
         else
            if (rotacion < 6)
               rotacion++;

         entradas[1] = MAT_Rotacion((rotacion%36)*10, 1, 0, 0);
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
         agregar(MAT_Traslacion(0.0, 1.5, -0.5));
         agregar(MAT_Escalado(1.5, 2.5, 1.5));
         agregar(new Cubo());
      }
};

class Caja : public NodoGrafoEscena{
   private:
      int desplazamiento;
   public:
      Caja(){
         desplazamiento = 0;           // Al principio la caja no está desplazada.
         agregar(MAT_Traslacion(-0.2, 0.0, 1.2));
         agregar(MAT_Traslacion(0.0, 0.0, 0.0));
         agregar(new Cubo());
      }

      // Función que desplaza la caja hacia adelante.
      // No permitimos que el número de desplazamientos sea mayor que 10.
      void desplazar_adelante(){
         if (desplazamiento < 10){
            desplazamiento++;
            entradas[1] = MAT_Traslacion(0.0, 0.0, desplazamiento/4.0);
         }
      }

      // Función que desplaza la caja hacia atrás. No permitimos desplazamientos negativos.
      void desplazar_atras(){
         if (desplazamiento > 0){
            desplazamiento--;
            entradas[1] = (MAT_Traslacion(0.0, 0.0, desplazamiento/4.0));
         }
      }
};

class Figura : public NodoGrafoEscena{
   private:
      Cabeza* cabeza;
      BrazoIzquierdo* bi;
      BrazoDerecho* bd;
      PiernaDerecha* pd;
      PiernaIzquierda* pi;
      Tronco* tr;
      Caja* cj;

   public:
      Figura(){
         tr = new Tronco(); agregar(tr);
         cabeza = new Cabeza(); agregar(cabeza);
         bi = new BrazoIzquierdo(); agregar(bi);
         bd = new BrazoDerecho(); agregar(bd);
         pd = new PiernaDerecha(); agregar(pd);
         pi = new PiernaIzquierda(); agregar(pi);
         cj = new Caja(); agregar(cj);
      }

      void RotaBrazos(bool sentido_horario){
         bi->rotar(sentido_horario);
         bd->rotar(sentido_horario);
      }

      void RotaPiernaI(bool sentido_horario){
         pi->rotar(sentido_horario);
      }

      void RotaPiernaD(bool sentido_horario){
         pd->rotar(sentido_horario);
      }

      void MueveCaja(bool adelante){
         if(adelante)
            cj->desplazar_adelante();
         else
            cj->desplazar_atras();
      }
};

#endif
