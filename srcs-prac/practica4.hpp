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

// Clases para las fuentes de luz.
class FuenteLuz{
   public:
      Tupla4f posvec;      // posición
      Tupla4f colores[3];  // colores ambiental, difuso y especular
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
