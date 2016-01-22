// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 4  (declaraciones públicas)
// **
// *********************************************************************

#ifndef IG_PRACTICA4_HPP
#define IG_PRACTICA4_HPP

#include "MallaInd.hpp"
#include "matrizg.hpp"
#include "nodografoescena.hpp"
#include "matrices-tr.hpp"
#include "figura.hpp"
#include <vector>

using namespace std;

void P4_Inicializar( int argc, char *argv[] ) ;
bool P4_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P4_DibujarObjetos( unsigned modo ) ;

// -----------------------------------------------
// Clases adicionales

// Clases para la escena.

class Peon : public NodoGrafoEscena{
   public:
      Peon(){
         MallaRevol * peon = new MallaRevol("../plys/peon.ply", 12);
         agregar(peon);
      }
};

class Escena : public NodoGrafoEscena{
   public:
      Peon *peon1, *peon2, *peon3;
      Escena(){
         peon1 = new Peon(); agregar(peon1);
         agregar(MAT_Traslacion(2.0, 0.0, 0.0));
         peon2 = new Peon(); agregar(peon2);
         agregar(MAT_Traslacion(2.0, 0.0, 0.0));
         peon3 = new Peon(); agregar(peon3);
      }

};

// Clases para las fuentes de luz.
class FuenteLuz{
   public:
      unsigned int numero_fuentes = 0;
      int id;
      Tupla4f posvec;      // posición
      Tupla3f colores[3];  // colores ambiental, difuso y especular
      float lon, lat;      // ángulos de rotación  (fuente direccional)
                           // longitud: alpha. latitud: beta

      void activar (int i);   // activa la fuente de luz, con número GL_LIGHT0+i
};

class FuenteDireccional : public FuenteLuz{
   public:
      FuenteDireccional(float alpha_ini, float beta_ini);
      void variarAngulo(unsigned angulo, float incremento){
         if (angulo == 0)              // Variamos alpha.
            lon += incremento;
         else if (angulo == 1)         // Variamos beta.
            lat += incremento;
      }
};

class FuentePosicional : public FuenteLuz{
   public:
      FuentePosicional(const Tupla3f & posicion);
};


// Colecciones de fuentes de luz.
class ColeccionFL{
   public:
      vector<FuenteLuz *> fuentes;        // fuentes de luz
      void activar();                     // activa las fuentes de luz, activando y configurando la iluminación antes
};


class ColeccionFuentesP4 : public ColeccionFL{
   public:
      ColeccionFuentesP4();
};

#endif
