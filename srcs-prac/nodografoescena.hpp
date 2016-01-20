// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (declaraciones públicas)
// ** Archivos de la clase NodoGrafoEscena, derivada de Objeto3D,
// ** para la creación de objetos jerárquicos.
// **
// *********************************************************************

#ifndef NODO
#define NODO

#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "matrizg.hpp"
#include "Material.hpp"
#include <vector>

using namespace std;

// ---------------------------------------------------
// Estructura de entrada del nodo del grafo de escena.
struct EntradaNGE{
   unsigned char tipoE;  // 0 = objeto. 1 = transformación (matriz). 2 = material.
   union{
      Objeto3D * objeto; // Puntero a un objeto.
      Matriz4f * matriz; // Puntero a una matriz 4x4, que representa una transformación.
      Material * material;    // Puntero a un objeto de la clase Material.
   };

   // Constructores
   EntradaNGE(Objeto3D * pObjeto); // Copia puntero.
   EntradaNGE(const Matriz4f & pMatriz); // Crea copia de matriz.
};

// Clase NodoGrafoEscena
class NodoGrafoEscena : public Objeto3D{
   protected:
      vector<EntradaNGE> entradas;
   public:
      // Método de visualizado.
      virtual void visualizar(unsigned cv);
      // Añadir una entrada genérica.
      void agregar(EntradaNGE * entrada);
      // Construir una entrada y añadirla.
      void agregar(Objeto3D * pObjeto);
      void agregar(const Matriz4f & pMatriz);
      void agregar(Material * material);

};

#endif
