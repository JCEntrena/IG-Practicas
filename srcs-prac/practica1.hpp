// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (declaraciones públicas)
// **
// *********************************************************************

#ifndef IG_PRACTICA1_HPP
#define IG_PRACTICA1_HPP

#include "MallaInd.hpp"

void P1_Inicializar( int argc, char *argv[] ) ;
bool P1_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P1_DibujarObjetos( unsigned int modo ) ;


class Cubo1 : public MallaInd{

public:
    Cubo1();  // crea las tablas del cubo, y le da nombre.

};


class Tetraedro : public MallaInd{

public:
    Tetraedro() ;  // crea las tablas del tetraedro, y le da nombre.

};

#endif
