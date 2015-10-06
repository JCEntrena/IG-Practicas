#include <Objeto3D.hpp>
#include <tuplasg.hpp>
#include <vector>
 
// Clase para mallas indexadas o mallas TVT
class MallaInd : public Objeto3D{
protected:
    vector<Tupla3F> vertices; 
    vector<Tupla3i> indices;     

public:
    virtual void visualizar(unsigned modo_vis);
};
