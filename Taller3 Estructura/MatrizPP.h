#pragma once
#include "NodoMpp.h";


class MatrizPP
{
private:
	int filas;
	int columnas;
	NodoMpp* AROW;
	NodoMpp* ACOL;
public:

	MatrizPP();

	MatrizPP(int filas, int columnas);

	~MatrizPP();

	void imprimir();

	int getFilas();
	int getColumnas();
	NodoMpp* getAROW();
	NodoMpp* getACOL();
	

	void agregaMpp(Cliente* cliente,int fila,int columna);

};

