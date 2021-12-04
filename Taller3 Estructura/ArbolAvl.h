#pragma once
#include "NodoAVL.h"
#include <iostream>
#include <string>
using namespace std;

class ArbolAvl
{

private:
	NodoAVL* raiz;


public:
	ArbolAvl();

	NodoAVL* getRaiz();

	void agregarCliente(Cliente* cliente);

	int cantClientes();
	int cantNodos(NodoAVL* cliente);

	~ArbolAvl();



};




