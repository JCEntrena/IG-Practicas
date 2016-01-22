#include "Material.hpp"


// Activa un material en el cauce fijo.
void MaterialEstandar::activar(){

}

//Constructores para los materiales específicos de la práctica 4.
MaterialLata::MaterialLata(){
   color[0] = Tupla3f(0.85, 0.85, 0.85);     // Color blanco intenso.
   color[1] = Tupla3f(0.085, 0.085, 0.085);
   color[2] = Tupla3f(0.35, 0.35, 0.35);
   color[3] = Tupla3f(1.0, 1.0, 1.0);
   exponente = 4.5;

   text = new Textura("imgs/lata-coke.jpg");
}

MaterialTapasLata::MaterialTapasLata(){
   color[0] = Tupla3f(0.3, 0.3, 0.3);     // Color gris.
   color[1] = Tupla3f(0.03, 0.03, 0.03);
   color[2] = Tupla3f(0.3, 0.3, 0.3);
   color[3] = Tupla3f(1.0, 1.0, 1.0);
   exponente = 1.0;
}

MaterialPeonMadera::MaterialPeonMadera(){
   color[0] = Tupla3f(0.85, 0.85, 0.85);     // Color blanco intenso.
   color[1] = Tupla3f(0.085, 0.085, 0.085);
   color[2] = Tupla3f(0.3, 0.3, 0.3);
   color[3] = Tupla3f(0.7, 0.7, 0.7);
   exponente = 4.5;

   text = new Textura("imgs/text-madera.jpg");
}

MaterialPeonBlanco::MaterialPeonBlanco(){
   color[0] = Tupla3f(0.55, 0.55, 0.55);     // Color blanco.
   color[1] = Tupla3f(0.05, 0.05, 0.05);
   color[2] = Tupla3f(0.2, 0.2, 0.2);
   color[3] = Tupla3f(0.0, 0.0, 0.0);
   exponente = 4.5;
}

MaterialPeonNegro::MaterialPeonNegro(){
   color[0] = Tupla3f(0.0, 0.0, 0.0);     // Color negro.
   color[1] = Tupla3f(0.0, 0.0, 0.0);
   color[2] = Tupla3f(0.01, 0.01, 0.01);
   color[3] = Tupla3f(0.7, 0.7, 0.7);
   exponente = 4.5;
}
