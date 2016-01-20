#ifndef MATERIAL
#define MATERIAL

include "Texturas.hpp"

// Clases para materiales.
class Material{
   public:
      virtual void activar() = 0;
};

// Clase para material estándar, con datos públicos.
// Los modificaremos en los constructores de las clases derivadas. 
class MaterialEstandar : public Material{
   public:
      Textura * text;      // puntero a la textura (NULL en caso de no haber)
      Tupla4f color[4];    // colores: 0: emisión, 1: ambiental, 2: difuso, 3: especular
      float exponente;     // para la componente pseudo-especular

      virtual void activar();       // activa material en cauce fijo
                                    // si tiene textura se usa text
                                    // si no tiene textura se desactiva el uso de texturas
};
