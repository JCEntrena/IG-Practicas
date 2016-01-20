#ifndef TEXTURA
#define TEXTURA

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include <string>

using namespace std;

// Clase Textura.
class Textura{
   public:
      GLuint id_text;            // identificador de la textura
      jpg::Imagen * img;         // puntero a imagen con los texels
      unsigned mgct;             // modo de gen. cc.tt. (0 = desactivado, 1 = objeto, 2 = camara)
      float cs[4], ct[4];        // coeficientes para generación de coords. de textura

      void activar();            // activa textura en el cauce fijo de OpenGL
      Textura(const string & archivoJPG);  // crea un textura a partir de un archivo
};
