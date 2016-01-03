#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include <vector>
#include "file_ply_stl.hpp"

#ifndef MALLAIND
#define MALLAIND

// Clase para mallas indexadas o mallas TVT
class MallaInd : public Objeto3D{
protected:
    std::vector<Tupla3f> vertices;
    std::vector<Tupla3i> indices;
    std::vector<Tupla3f> normal_caras;
    std::vector<Tupla3f> normal_vertices; 

public:
    virtual void visualizar(unsigned modo_vis);
    void calcularNormales();
};

// Clase para mallas indexadas obtenidas de un PLY.
class MallaPLY : public MallaInd{
   public:
   // Constructor
   // Recibe como parámetro el nombre del archivo PLY a leer.
   MallaPLY(const char* nombre_archivo);
};


// Clase para mallas indexadas obtenidas de un PLY.
// Generadas por revolución.
class MallaRevol : public MallaInd{
   public:
   // Constructor.
   // Recibe como parámetros:
   // - El nombre del archivo PLY.
   // - El número de copias del perfil.
   MallaRevol(const char* nombre_archivo, unsigned nperfiles);
};

// Clase para mallas indexadas obtenidas de un PLY.
// Generadas por barrido, dado un contorno cerrado y un vector de traslación.
class MallaBarrido : public MallaInd{
   public:
   // Constructor
   // Recibe como parámetros:
   // - El nombre del archivo PLY.
   // - Tres flotantes, indicando el vector (x,y,z) de desplazamiento.
   // - El número de copias por barrido.
   MallaBarrido(const char* nombre_archivo, float x, float y, float z, unsigned nperfiles);
};

#endif
