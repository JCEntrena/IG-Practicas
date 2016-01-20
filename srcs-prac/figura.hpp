// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (declaraciones públicas)
// **
// *********************************************************************

#ifndef FIGURA
#define FIGURA

#include "MallaInd.hpp"
#include "matrizg.hpp"
#include "nodografoescena.hpp"
#include "matrices-tr.hpp"

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
         agregar(MAT_Traslacion(1.55, 2.75, 0.0));
         agregar(MAT_Traslacion(0.0, 0.95, 0.25));
         agregar(MAT_Rotacion(0, 1, 0, 0));
         agregar(MAT_Traslacion(0.0, -0.95, -0.25));
         agregar(new Brazo());
      }

      // Función de rotación del brazo. Rotará libremente con incrementos de 10º, partiendo desde 0º.
      void rotar(bool sentido_horario){
         // Si es en sentido horario:
         if (sentido_horario){
            if (rotacion > -9)
               rotacion--;
         }
         // En otro caso, sentido antihorario.
         else
            if (rotacion < 9)
               rotacion++;

         entradas[2] = MAT_Rotacion(rotacion*10, 1, 0, 0);
      }
};

class BrazoIzquierdo : public NodoGrafoEscena{
   public:
      int rotacion;

      BrazoIzquierdo(){
         rotacion = 0;
         agregar(MAT_Traslacion(-0.65, 2.75, 0.0));
         agregar(MAT_Traslacion(0.0, 0.95, 0.25));
         agregar(MAT_Rotacion(0, 1, 0, 0));
         agregar(MAT_Traslacion(0.0, -0.95, -0.25));
         agregar(new Brazo());
      }

      // Función de rotación del brazo. Rotará libremente con incrementos de 10º, partiendo desde 0º.
      void rotar(bool sentido_horario){
         // Si es en sentido horario:
         if (sentido_horario){
            if (rotacion > -9)
               rotacion--;
         }
         // En otro caso, sentido antihorario.
         else
            if (rotacion < 9)
               rotacion++;

         entradas[2] = MAT_Rotacion(rotacion*10, 1, 0, 0);
      }
};

class Pierna : public NodoGrafoEscena{
   public:
      Pierna(){
         MallaPLY *pie = new MallaPLY("../plys/pie.ply");
         agregar(pie);
         agregar(new Cubo());
      }
};

class PiernaIzquierda : public NodoGrafoEscena{
   public:
      int rotacion;  // Ángulo de rotación.

      PiernaIzquierda(){
         rotacion = 0;
         agregar(MAT_Traslacion(0.0, 2.0, 0.5));
         agregar(MAT_Rotacion(0, 1, 0, 0));
         agregar(MAT_Traslacion(0.0, -2.0, -0.5));
         agregar(MAT_Escalado(0.6, 1.90, 0.5));
         agregar(new Pierna());
      }

      // Función de rotación. Permitimos que la pierna rote en ambos sentido partiendo desde 0º.
      // El incremento será de 2.5º tanto positivo como negativo.
      void rotar(bool sentido_horario){
         // Sentido horario.
         if (sentido_horario){
            if (rotacion > -6)
               rotacion--;
         }

         // En otro caso, sentido antihorario.
         else
            if (rotacion < 10)
               rotacion++;

         entradas[1] = MAT_Rotacion(rotacion*2.5, 1, 0, 0);
      }

};

class PiernaDerecha : public NodoGrafoEscena{
   public:
      int rotacion;  // Ángulo de rotación.

      PiernaDerecha(){
         rotacion = 0;
         agregar(MAT_Traslacion(0.9, 0, 0));
         agregar(MAT_Traslacion(0.0, 2.0, 0.5));
         agregar(MAT_Rotacion(0, 1, 0, 0));
         agregar(MAT_Traslacion(0.0, -2.0, -0.5));
         agregar(new PiernaIzquierda());
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
            if (rotacion < 10)
               rotacion++;

         entradas[2] = MAT_Rotacion(rotacion*2.5, 1, 0, 0);
      }
};

class Cabeza : public NodoGrafoEscena{
   public:
      int rotacion;
       Cabeza(){
          rotacion = 0;
          agregar(MAT_Traslacion(0.25, 4.55, -0.25));
          agregar(MAT_Traslacion(0.5, 0, 0.5));
          agregar(MAT_Rotacion(0, 1, 0, 0));
          agregar(MAT_Traslacion(-0.5, 0, -0.5));
          agregar(new Cubo());
       }
       void negar(bool sentido_antihorario){
          if (sentido_antihorario){
             if (rotacion < 4)
               rotacion++;
          }
          else
            if (rotacion > -4)
               rotacion--;
         entradas[2] = MAT_Rotacion(rotacion*5, 0, 1, 0);
       }
};

class Tronco : public NodoGrafoEscena{
   public:
      Tronco(){
         agregar(MAT_Traslacion(0.0, 2.0, -0.5));
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
         agregar(MAT_Traslacion(-0.2, 0.0, 1.1));
         agregar(MAT_Traslacion(0.0, 0.0, 0.0));
         agregar(new Cubo());
      }

      // Función que desplaza la caja hacia adelante.
      // No permitimos que el número de desplazamientos sea mayor que 12.
      void desplazar_adelante(){
         if (desplazamiento < 12){
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
      Cabeza* cb;
      BrazoIzquierdo* bi;
      BrazoDerecho* bd;
      PiernaDerecha* pd;
      PiernaIzquierda* pi;
      Tronco* tr;
      Caja* cj;

   public:
      Figura(){
         tr = new Tronco(); agregar(tr);
         cb = new Cabeza(); agregar(cb);
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

      void Negar(bool sentido){
         cb->negar(sentido);
      }
};

#endif
