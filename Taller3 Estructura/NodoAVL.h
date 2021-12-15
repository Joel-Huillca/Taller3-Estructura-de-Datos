#pragma once
#include "Cliente.h"
#include <iostream>
#include <string>
using namespace std;
class NodoAVL
{
private:

	Cliente* cliente;
	NodoAVL* hijoIzq;
	NodoAVL* hijoDer;
	NodoAVL* padre;
	
public:
	/*Constructor vacio de la clase NodoAVL*/
	NodoAVL();
	/*Cosntructor de la clase NodoAVL
	@param cliente - dato de tipo cliente del nodo*/
	NodoAVL(Cliente* cliente);

	/*Gets de la clase NodoAVL*/
	Cliente*& getCliente();
	NodoAVL*& getHijoIzq();
	NodoAVL*& getHijoDer();
	NodoAVL*& getPadre();
	/*Sets de la clase NodoAVL*/
	void setCliente(Cliente* cliente);
	void setHijoIzq(NodoAVL* hijoIzq );
	void setHijoDer(NodoAVL* hijoDer);
	void setPadre(NodoAVL* padre);
};



