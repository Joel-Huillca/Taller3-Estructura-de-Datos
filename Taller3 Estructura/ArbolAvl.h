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

	void agregarCliente(Cliente* cliente);// Agregar de forma ABB		 xxx   |Solo como referencia|   xxx


	int calcularBalance(NodoAVL* nodoCliente); // ALV - Por completar


	int cantClientes();// ABB
	int cantNodos(NodoAVL* cliente);//ABB

	~ArbolAvl();



};




