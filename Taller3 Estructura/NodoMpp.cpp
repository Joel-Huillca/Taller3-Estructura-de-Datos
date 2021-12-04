#include "NodoMpp.h"
NodoMpp::NodoMpp()
{
	this->left = this;
	this->up = this;
	this->fila = 0;
	this->columna = 0;
	this->tipo = ' ';
}
NodoMpp::NodoMpp(int fila, int columna)
{
}

NodoMpp::NodoMpp(int fila, int columna, char tipo)
{
	this->left = nullptr;
	this->up = nullptr;
	this->fila = fila;
	this->columna = columna;
	this->tipo = tipo;
}


NodoMpp* NodoMpp::getLeft()
{
	return this->left;
}

NodoMpp* NodoMpp::getUp()
{
	return this->up;
}

int NodoMpp::getFila()
{
	return this->fila;;
}

int NodoMpp::getColumna()
{
	return this->columna;
}

char NodoMpp::getTipo()
{
	return this->tipo;
}

void NodoMpp::setLeft(NodoMpp* nodo)
{
	this->left = nodo;
}

void NodoMpp::setUp(NodoMpp* nodo)
{
	this->up = nodo;
}

void NodoMpp::setFila(int fila)
{
	this->fila = fila;
}

void NodoMpp::setColumna(int columna)
{
	this->columna = columna;
}



NodoMpp::~NodoMpp()
{
	//delete cliente; // llamar al Nodo
}