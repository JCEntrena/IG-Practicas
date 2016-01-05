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
#include <vector>

using namespace std;

void P4_Inicializar( int argc, char *argv[] ) ;
bool P4_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P4_DibujarObjetos( unsigned modo ) ;

// -----------------------------------------------
// Clases adicionales

// Clase Textura.
class Textura{
   public:
      GLuint id_text;            // identificador de la textura
      jpg::Imagen * img;         // puntero a imagen con los texels
      unsigned mgct;             // modo de gen. cc.tt. (0 = desactivado, 1 = objeto, 2 = camara)
      float cs[4], ct[4];        // coeficientes para generación de coords. de textura

      void activar();            // activa textura en el cauce fijo de OpenGL
      Textura(const std::string & archivoJPG);  // crea un textura a partir de un archivo
};

// Clases para materiales.
class Material{
   public:
      virtual void activar() = 0;
};

class MaterialEstandar : public Material{
   public:
      Textura * text;      // puntero a la textura (NULL en caso de no haber)
      Tupla4f color[4];    // colores: 0: emisión, 1: ambiental, 2: difuso, 3: especular
      float exponente;     // para la componente pseudo-especular

      virtual void activar();       // activa material en cauce fijo
                                    // si tiene textura se usa text
                                    // si no tiene textura se desactiva el uso de texturas
};

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
}


class ColeccionFuentesP4 : public ColeccionFL{
   public:
      ColeccionFuentesP4();
};




#endif
