#include "MallaInd.hpp"

// Implementación de la función para la visualización de objetos.
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

// Constructor para las mallas indexadas a partir de un archivo PLY
MallaPLY::MallaPLY(const char* nombre_archivo){
   // Estructuras auxiliares para la lectura.
   std::vector<float> vertex_aux;
   std::vector<int> index_aux;
   // Lectura
   ply::read(nombre_archivo, vertex_aux, index_aux);

   // Creamos los vectores de Tuplas a partir de lo obtenido.
   for (int i = 0; i < vertex_aux.size(); i = i+3)
      vertices.push_back(Tupla3f(vertex_aux.at(i), vertex_aux.at(i+1), vertex_aux.at(i+2)));

   for (int i = 0; i < index_aux.size(); i = i+3)
      indices.push_back(Tupla3i(index_aux.at(i), index_aux.at(i+1), index_aux.at(i+2)));
}

// Constructor para las mallas indexadas a partir de la revolución de una polilínea.
MallaRevol::MallaRevol(const char* nombre_archivo, unsigned nperfiles){
   // Definición del ángulo.
   const double PI = 3.1415926536;
   double angle = 2*PI/nperfiles;
   // Seno y coseno del ángulo, para la rotación.
   // Nuestra rotación será sobre el eje y, luego las nuevas coordenadas serán:
   // x ---> x cos(angle) - z sen(angle)
   // y ---> y
   // z ---> x sen (angle) + z cos(angle)
   double seno = sin(angle), coseno = cos(angle);

   // Estructura auxiliar para la lectura.
   std::vector<float> vertex_aux;
   // Lectura
   ply::read_vertices(nombre_archivo, vertex_aux);

   // Creamos los vectores de Tuplas a partir de lo obtenido.
   for (int i = 0; i < vertex_aux.size(); i = i+3){
      vertices.push_back(Tupla3f(vertex_aux.at(i), vertex_aux.at(i+1), vertex_aux.at(i+2)));
   }

   int num_vertices = vertices.size();
   // Puntos de las bases superior e inferior.
   float top = vertices.front()(1);
   float bottom = vertices.back()(1);

   // Añadimos el resto de vértices a cada vector.
   for(int i = 1; i < nperfiles; i++){
      for (int j = 0; j < num_vertices; j++){
         float x = vertices.at(vertices.size() - num_vertices)(0),
               y = vertices.at(vertices.size() - num_vertices)(1),
               z = vertices.at(vertices.size() - num_vertices)(2);
         // Creamos un nuevo punto a partir del primero.
         vertices.push_back(Tupla3f(x*coseno - z*seno, y, x*seno + z*coseno));
      }
   }

   //Añadimos las dos proyecciones para las tapas.
   vertices.push_back(Tupla3f(0, top, 0));
   int index_top = vertices.size() - 1;
   vertices.push_back(Tupla3f(0, bottom, 0));
   int index_bottom = vertices.size() - 1;

   // Añadimos los índices.
   for (int i = 0; i < nperfiles; i++){
      for (int j = 0; j < num_vertices - 1; j++){
         // Triangulo de puntos (0, 1, n)
         indices.push_back(Tupla3i((j+i*num_vertices)%(nperfiles*num_vertices),
                                   (j+i*num_vertices+1)%(nperfiles*num_vertices),
                                   ((i+1)*num_vertices+j)%(nperfiles*num_vertices)));
         // Triángulo de puntos (1, n, n+1)
         indices.push_back(Tupla3i((j+i*num_vertices+1)%(nperfiles*num_vertices),
                                   ((i+1)*num_vertices+j)%(nperfiles*num_vertices),
                                   ((i+1)*num_vertices+j+1)%(nperfiles*num_vertices)));
      }
   }

   // Índices para las tapas.
   for (int i = 0; i < nperfiles; i++){
      // Para la tapa superior (top)
      indices.push_back(Tupla3i(i*num_vertices,
                                ((i+1)*num_vertices)%(nperfiles*num_vertices),
                                index_top));
      // Para la tapa inferior (bottom)
      indices.push_back(Tupla3i((i+1)*num_vertices-1,
                                ((i+2)*num_vertices-1)%(nperfiles*num_vertices),
                                index_bottom));
   }

}
