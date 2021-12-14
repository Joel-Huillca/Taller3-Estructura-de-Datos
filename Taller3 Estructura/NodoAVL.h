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
	NodoAVL();
	NodoAVL(Cliente* cliente);


	Cliente* getCliente();
	NodoAVL* getHijoIzq();
	NodoAVL* getHijoDer();
	NodoAVL* getPadre();

	void setCliente(Cliente* cliente);
	void setHijoIzq(NodoAVL* hijoIzq );
	void setHijoDer(NodoAVL* hijoDer);
	void setPadre(NodoAVL* padre);
};



