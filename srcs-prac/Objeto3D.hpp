#ifndef OBJETO3D_HPP
#define OBJETO3D_HPP

#include<string>
#include"aux.hpp"

// Estructura para el contexto de visualización.

struct contextovis{
   bool iluminacion;    // Modo iluminación o como normal.
   unsigned int modo_nor;   // Mantiene los modos de las prácticas 1-3
   unsigned int modo_ilu; // Modo de iluminación. 0 plano, 1 suave.

   contextovis(unsigned int i){
      iluminacion = false;
      modo_nor = i;
      modo_ilu = 0;
   }
   contextovis(bool activado, unsigned int nor, unsigned int ilum){
      iluminacion = activado;
      modo_nor = nor;
      modo_ilu = ilum; 
   }
};

// clase abstracta para objetos 3D visualizables con OpenGL
class Objeto3D{

protected:
    std::string nombre_obj; // nombre asignado al objeto
public:
    virtual void visualizar(contextovis modo_vis) = 0; // visualizar el objeto con OpenGL
    std::string nombre();  // devuelve el nombre del objeto

};
#endif
