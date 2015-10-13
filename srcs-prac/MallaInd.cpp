#include "MallaInd.hpp"

void MallaInd::visualizar(unsigned modo_vis){
    
    glEnableClientState(GL_VERTEX_ARRAY); // Habilitar array de vértices. 
    glVertexPointer(3, GL_FLOAT, 0, &vertices.front());
        
    switch(modo_vis){
        case 0: // Puntos. 
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            glDrawElements(GL_TRIANGLES, indices.size()*3, GL_UNSIGNED_INT, &indices.front()); 
        break; 
        case 1: // Aristas.
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
            glDrawElements(GL_TRIANGLES, indices.size()*3, GL_UNSIGNED_INT, &indices.front()); 
        break;
        case 2: // Sólido.
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
            glDrawElements(GL_TRIANGLES, indices.size()*3, GL_UNSIGNED_INT, &indices.front()); 
        break;  
        case 3: // Ajedrez.
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
            for (int i = 0; i < indices.size(); i++){
                glColor3f(0,0,i%2); 
                glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &indices[i]); 
            }
        break;
        default: // Por defecto: Modo puntos. 
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            glDrawElements(GL_TRIANGLES, indices.size()*3, GL_UNSIGNED_INT, &indices.front()); 
        break; 
    }

    glDisableClientState(GL_VERTEX_ARRAY);
}

