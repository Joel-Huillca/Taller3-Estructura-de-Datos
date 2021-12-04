#pragma once
#include "Cliente.h"
#include <iostream>
#include <string>
using namespace std;
class NodoAVL
{
private:
	NodoAVL* hijoIzq;
	NodoAVL* hijoDer;
	Cliente* cliente;
	int factorBalance;

public:
	NodoAVL();
	NodoAVL(Cliente* cliente);

	void agregar(Cliente* cliente);


	Cliente* getCliente();
	void setCliente(Cliente* cliente);


	NodoAVL* getHijoIzq();
	NodoAVL* getHijoDer();

	void preOrden();
	void inOrden();
	void postOrden();

};



