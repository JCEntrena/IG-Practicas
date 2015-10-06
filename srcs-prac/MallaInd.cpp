#include<MallaInd.hpp> 

void MallaInd::visualizar(unsigned modo_vis){
    
    glEnableClientState(GL_VERTEX_ARRAY); // Habilitar array de vértices. 
    glVertexPointer(3, GL_FLOAT, 0, vertices); 
    glDrawElements(GL_POINTS, indices.size()*3, GL_UNSIGNED_INT, indices); 
    glDisableClientState(GL_VERTEX_ARRAY); 

}

