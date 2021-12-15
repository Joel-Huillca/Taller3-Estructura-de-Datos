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
	/*Constructor vacio de la clase MatrizPP*/
	MatrizPP();
	/*Constructor de la clase MatrizPP
	@param filas - numero de filas de la matriz
	@param columnas - numero de columnas de la matriz*/
	MatrizPP(int filas, int columnas);
	/*Destructor de la clase MatrizPP*/
	~MatrizPP();
	/*Metodo publico para imprimir la sala de cine*/
	void imprimirSala();
	/*Metodo publico para agregar un cliente a la sala de cine
	@param cliente - clase cliente que se agrega a la sala
	@param fila - coordenada fila del cliente ha agregar
	@param columna - coordenada columna del cliente ha agregar*/
	void agregaMpp(Cliente* cliente, int fila, int columna);
	/*Metoodo publico para ver si la sala esta vacia o no y retorna un booleano*/
	bool estaVacia();
	/*Metodo publico que recorre la sala y retorna un entero*/
	int recorrerSala();
	/*Metodo publico que vacia la sala de cine*/
	void vaciarSala();
	/*Gets de la clase MatrizPP*/
	int getFilas();
	int getColumnas();
	NodoMpp* getAROW();
	NodoMpp* getACOL();
};

