// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (implementación)
// ** Implementación de la clase NodoGrafoEscena y el struct.
// **
// *********************************************************************

#include "nodografoescena.hpp"

// Constructores de EntradaNGE

// Constructor con un Objeto3D.
EntradaNGE::EntradaNGE(Objeto3D * pObjeto){
   tipoE = 0;
   objeto = pObjeto;
}

// Constructor con una matriz.
EntradaNGE::EntradaNGE(const Matriz4f & pMatriz){
   tipoE = 1;
   matriz = new Matriz4f(pMatriz);
}

EntradaNGE::EntradaNGE(Material * m){
   tipoE = 2;
   material = m;
}

// --------------------------------------------------------
// Clase NodoGrafoEscena

// Método de visualizado. Llama al método definido en Objeto3D.
void NodoGrafoEscena::visualizar(contextovis cv){
   // Cambiamos el modo de visualización a malla o sólido.
   if (cv.modo_nor != 1)
      cv.modo_nor = 2;

   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();

   // Recorre todas las entradas del array que hay en el nodo.
   int tamanio = entradas.size();
   for (unsigned i = 0; i < tamanio; i++){
      if (entradas[i].tipoE == 0)
         entradas[i].objeto->visualizar(cv);
      else if (entradas[i].tipoE == 1)
         glMultMatrixf(*(entradas[i].matriz));
      else
         entradas[i].material->activar(); 
   }

   glMatrixMode(GL_MODELVIEW);
   glPopMatrix();
}

void NodoGrafoEscena::agregar(EntradaNGE * entrada){
   entradas.push_back(*entrada);
}

void NodoGrafoEscena::agregar(Objeto3D * pObjeto){
   EntradaNGE nueva(pObjeto);
   entradas.push_back(nueva);
}

void NodoGrafoEscena::agregar(const Matriz4f & pMatriz){
   EntradaNGE nueva(pMatriz);
   entradas.push_back(nueva);
}

void NodoGrafoEscena::agregar(Material * material){
   EntradaNGE nueva(material);
   entradas.push_back(nueva);
}
