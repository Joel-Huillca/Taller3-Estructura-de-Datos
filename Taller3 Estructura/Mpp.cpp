
#include "Mpp.h"

#include <iostream>
#include <string>
using namespace std;
MatrizPP::MatrizPP()
{
	this->filas = 0;
	this->columnas = 0;
	this->AROW = nullptr;
	this->ACOL = nullptr;
}

MatrizPP::MatrizPP(int filas, int columnas)
{
	this->filas = filas;
	this->columnas = columnas;
	this->AROW = new NodoMpp[filas + 1];
	this->ACOL = new NodoMpp[columnas + 1];
}

MatrizPP::~MatrizPP()
{
}

void MatrizPP::imprimir()
{
	/*
	for (int i=1; i<=filas; i++) 
	{
		string fila;
		NodoMpp*aux = AROW[i].getLeft();
		int espaciosVacios = columnas - aux->getColumna();
		while (true)
		{
			for (int j=0; j<espaciosVacios; j++)
			{

				fila = "x " + fila;
			}
			if (aux->getColumna() == 0) break;

			stringstream s;
			
			if (aux->getCliente()->getFila())
			{
				s << "o ";
			}

			fila = s.str() + fila;
			espaciosVacios = aux->getColumna() - aux->getLeft()->getColumna() - 1;
			aux = aux->getLeft();
		}
		cout << fila << endl;
	}
	*/
}



int MatrizPP::getFilas()
{
	return this->filas;
}

int MatrizPP::getColumnas()
{
	return this->columnas;
}

NodoMpp* MatrizPP::getAROW()
{
	return AROW;
}

NodoMpp* MatrizPP::getACOL()
{
	return ACOL;
}

