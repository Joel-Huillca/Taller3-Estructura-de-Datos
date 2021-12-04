#pragma once
class NodoMpp
{
private:
	NodoMpp* left;
	NodoMpp* up;
	int fila;
	int columna;
	char tipo;
public:

	NodoMpp();

	NodoMpp(int fila, int columna);//  ?

	NodoMpp(int fila, int columna, char tipo);

	

	NodoMpp* getLeft();
	NodoMpp* getUp();
	int getFila();
	int getColumna();
	char getTipo();

	void setLeft(NodoMpp* nodo);
	void setUp(NodoMpp* nodo);
	void setFila(int fila);
	void setColumna(int columna);

	~NodoMpp();
};

