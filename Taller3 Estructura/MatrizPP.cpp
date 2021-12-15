
#include "MatrizPP.h"

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


//void MatrizPP::imprimir()
//{
	/*
	for (int i=1; i<=filas; i++)
	{
		string fila;
		NodoMpp*aux = AROW[i].getLeft();
		int espaciosVacios = columnas - aux->getColumna();//Obtiene la distancia entre auxliar....
		while (true)
		{
			for (int j=0; j<espaciosVacios; j++)
			{

				fila = "x " + fila;
			}
			if (aux->getColumna() == 0) break;

			//____________________________________
			stringstream s;
			if (aux->getCliente()->getFila())
			{
				s << "o ";
			}//____________________________________
			

			fila = s.str() + fila;
			espaciosVacios = aux->getColumna() - aux->getLeft()->getColumna() - 1;
			aux = aux->getLeft();
		}
		cout << fila << endl;
	}
	*/
	//}


void MatrizPP::imprimirSala()
{
	for (int i = 1; i < filas + 1; i++)
	{
		NodoMpp* nodoAux = &AROW[i];
		while (nodoAux->getLeft()->getColumna() != 0) {
			if (nodoAux->getColumna() != 0) {
				for (int j = 1; j < (nodoAux->getColumna() - nodoAux->getLeft()->getColumna()); j++) {
					cout << "H";
				}
			}
			else {
				for (int j = 0; j < (columnas - nodoAux->getLeft()->getColumna()); j++) {
					cout << "H";
				}
			}
			cout << "O";
			nodoAux = nodoAux->getLeft();
		}


		if (nodoAux->getLeft()->getColumna() == 0) {
			for (int j = 1; j < (nodoAux->getColumna()); j++) {
				cout << "I";
			}
		}

	}
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

int MatrizPP::recorrerSala()
{
	int cantActual = 0;
	int cantTotal = 0;
	for (int i = 1; i < filas+1 ; i++)
	{
		NodoMpp* nodoAux = &AROW[i];
		while (nodoAux->getLeft()->getColumna() != 0) {
			if (nodoAux->getColumna() != 0) {
				for (int j = 1; j < (nodoAux->getColumna() - nodoAux->getLeft()->getColumna()); j++) {
					cantTotal++;
				}
			}
			else {
				for (int j = 0; j < (columnas - nodoAux->getLeft()->getColumna()); j++) {
					cantTotal++;
				}
			}
			cantActual++;
			nodoAux = nodoAux->getLeft();
		}
	

		if (nodoAux->getLeft()->getColumna() == 0) {
			for (int j = 1; j < (nodoAux->getColumna()); j++) {
				cantTotal++;
			}
		}

	}
	return cantActual;
}

 void MatrizPP::agregaMpp(Cliente* cliente, int fila, int columna)
{
	 if (columna < 5 && fila % 4 != 0 && (fila + columna) % 2 == 0 || columna > 26 && fila % 4 != 0 && (fila + columna) % 2 == 0 || columna > 7 && columna < 24 && fila % 4 != 0 && (fila + columna) % 2 != 0)
	 {
		 NodoMpp* nodoMpp = new NodoMpp(cliente, fila, columna);
		 NodoMpp* aux = &AROW[fila];
		 while (aux->getLeft()->getColumna() > 0 && aux->getLeft()->getColumna() > columna)
		 {
			 if (aux->getLeft()->getColumna() == columna) {  // ya esta ocupado
				 return;
			 }
			 aux = aux->getLeft();
		 }
		 nodoMpp->setLeft(aux->getLeft());
		 aux->setLeft(nodoMpp);

		 NodoMpp* aux2 = &ACOL[columna];
		 while (aux2->getUp()->getFila() > 0 && aux2->getUp()->getFila() > fila)
		 {
			 aux2 = aux2->getUp();
		 }
		 nodoMpp->setLeft(aux2->getUp());
		 aux2->setUp(nodoMpp);
	 }
}

 void MatrizPP::vaciarSala()
 {
	 for (int i = 1; i < filas; i++) {
		 NodoMpp* nodoAux = AROW[i].getLeft();
		 NodoMpp* nodoAux2 = new NodoMpp();
		 while (nodoAux->getColumna() != 0) {
			 nodoAux2 = nodoAux->getLeft();
			 nodoAux->~NodoMpp();
			 nodoAux = nodoAux2;
		 }
	 }
 }

 bool MatrizPP::estaVacia()
 {
	 int cantSala = recorrerSala();
	 if (cantSala == 0) { //si no hay nada en la sala retorna verdadero
		 return true;
	 }
	 else
		 return false; 
 }


