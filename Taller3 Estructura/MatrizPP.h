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

	void agregaMpp(Cliente* cliente, int fila, int columna);

	bool estaVacia();

	int recorrerMatriz();

	void vaciarMatriz();

	int getFilas();
	int getColumnas();
	NodoMpp* getAROW();
	NodoMpp* getACOL();
	


};

