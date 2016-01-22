#include "Textura.hpp"

using namespace std;

// Constructor. Crea una textura a partir de un archivo.
Textura::Textura(const string & archivoJPG){
   img = new jpg::Imagen(archivoJPG);
}

// Activa la textura.
void Textura::activar(){

   jpg::Imagen * pimg = NULL;

   pimg = new jpg::Imagen("nombre.jpg");

}
