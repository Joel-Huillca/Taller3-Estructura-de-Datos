#pragma once
#include "Cliente.h"
#include "Pelicula.h"
class NodoMpp
{
private:
	NodoMpp* left;
	NodoMpp* up;
	int fila;
	int columna;
	Cliente* cliente;
public:
	/*Constructor vacio de la clase NodoMpp*/
	NodoMpp();
	/*Constructor de la clase NodoMPP
	@param cliente - clase cliente que tiene el nodo
	@param fila - coordenada fila que tiene el nodo
	@param columna - coordenada columna que tiene el nodo*/
	NodoMpp(Cliente* cliente,int fila, int columna);
	
	/*Gets de la clase NodoMpp*/
	NodoMpp* getLeft();
	NodoMpp* getUp();
	int getFila();
	int getColumna();
	Cliente* getCliente();
	/*Sets de la clase NodoMpp*/
	void setLeft(NodoMpp* nodo);
	void setUp(NodoMpp* nodo);
	void setFila(int fila);
	void setColumna(int columna);
	/*Destructor de la clase NodoMpp*/
	~NodoMpp();
};

