#pragma once
#include "NodoAVL.h"
#include "Cliente.h"

#include <fstream>
#include <sstream>

#include <iostream>
#include <string>
using namespace std;

class ArbolAvl
{

private:
	NodoAVL* raiz;

	//void insertNewNodeRec(NodoAVL*& actual, NodoAVL newNode);
	void insertNewNodeRec(NodoAVL*& actual, NodoAVL& newNode);
	int checkOrder(NodoAVL* newNode, int rut); //productCode } rut
	int height(NodoAVL* node);
	int calculateOrder(NodoAVL* node);
	void rotationRR(NodoAVL* actual);
	void rotationLL(NodoAVL* actual);
	void rotationRL(NodoAVL* actual);
	void rotationLR(NodoAVL* actual);
	void deleteNodeRec(NodoAVL*& node, int rut);//productCode } rut
	NodoAVL*& minimum(NodoAVL*& node, bool direction);
	Cliente* searchNodeRec(NodoAVL* node, int rut);//productCode } rut
	void printTreeRec(NodoAVL*& node);
	void deleteTreeRec(NodoAVL* actual);

public:
	ArbolAvl();
	~ArbolAvl();
	

	void insertNewNode(Cliente* cliente);
	void deleteNode(int rut);//productCode } rut
	Cliente* searchNode(int rut);//productCode } rut
	void printTree();
	void deleteTree();



};




