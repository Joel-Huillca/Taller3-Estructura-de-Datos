#pragma once
#include "Cliente.h"
class NodoMpp
{
private:
	NodoMpp* left;
	NodoMpp* up;
	int fila;
	int columna;
	Cliente* cliente;
public:

	NodoMpp();

	NodoMpp(Cliente* cliente,int fila, int columna);
	

	NodoMpp* getLeft();
	NodoMpp* getUp();
	int getFila();
	int getColumna();
	Cliente* getCliente();

	void setLeft(NodoMpp* nodo);
	void setUp(NodoMpp* nodo);
	void setFila(int fila);
	void setColumna(int columna);

	~NodoMpp();
};

