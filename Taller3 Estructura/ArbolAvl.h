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

	/*Metodo que hace un llamado a dos m�todos, uno de inserci�n recursivo y otro el cual revisa el orden del �rbol AVL
	@param actual - actual nodo del arbol avl
	@param newNode - nuevo nodo a insertar del arbol avl*/
	void insertNewNodeRec(NodoAVL*& actual, NodoAVL& newNode);
	/*Este m�todo verifica el orden de cada nodo dentro del �rbol. En el caso que el FB  de un nodo en espec�fico genere un overflow,
	@param newNode - nuevo nodo del arbol avl
	@param rut - dato del nodo tipo rut*/
	int checkOrder(NodoAVL* newNode, int rut);
	/*Este m�todo mide la altura del �rbol AVL recibiendo por par�metro un nodo
	@param node - nodo del arbol avl*/
	int height(NodoAVL* node);
	/*Este m�todo calcula el FB del �rbol AVL recibiendo por par�metro un nodo
	@param node - nodo del arbol avl*/
	int calculateOrder(NodoAVL* node);
	/*Este m�todo es llamado por el m�todo checkOrder en caso de haber ocurrido un overflow.
	Su funci�n es hacer una rotaci�n RR del nodo afectado recibiendo por par�metro el nodo actual
	@param actual - nodo actual del arbol avl*/
	void rotationRR(NodoAVL* actual);
	/*Este m�todo es llamado por el m�todo checkOrder en caso de haber ocurrido un overflow.
	Su funci�n es hacer una rotaci�n LL del nodo afectado recibiendo por par�metro el nodo actual
	@param actual - nodo actual del arbol avl*/
	void rotationLL(NodoAVL* actual);
	/*Este m�todo es llamado por el m�todo checkOrder en caso de haber ocurrido un overflow.
	Su funci�n es hacer una rotaci�n RL del nodo afectado recibiendo por par�metro el nodo actual
	@param actual - nodo actual del arbol avl*/
	void rotationRL(NodoAVL* actual);
	/*Este m�todo es llamado por el m�todo checkOrder en caso de haber ocurrido un overflow.
	Su funci�n es hacer una rotaci�n LR del nodo afectado recibiendo por par�metro el nodo actual
	@param actual - nodo actual del arbol avl*/
	void rotationLR(NodoAVL* actual);
	/*Este elimina un producto del �rbol AVL de forma recursiva y hace un llamado alm�todo checkOrder
	para verificar el orden del �rbol. Para esto, se le env�a por par�metros un nodo y el c�digo del producto.
	@param node - nodo del codigo a elimir
	@param rut - rut del nodo a eliminar*/
	void deleteNodeRec(NodoAVL*& node, int rut);
	/*Este m�todo recibe por par�metros un nodo y un booleano.
	Este busca la �ltima hoja del �rbol (derecha o izquierda) y lo retorna
	@param node - nodo del arbol avl
	@param direction booleano de la direccion del nodo*/
	NodoAVL*& minimum(NodoAVL*& node, bool direction);
	/*Este m�todo recibe un Producto y hace un llamado a otro m�todo recursivo el cual
	busca este producto en el �rbol, recibiendo por par�metro el c�digo Producto y la
	ra�z del �rbol. Despu�s retorna el producto.*/
	Cliente* searchNodeRec(NodoAVL* node, int rut);
	/*Este elimina cada nodo del �rbol AVL de forma recursiva.
	Para esto, se le env�a por par�metros un nodo.*/
	void deleteTreeRec(NodoAVL* actual);
	/*Este va desplegando cada dato de los productos del �rbol AVL de forma recursiva.
	Para esto, se le env�a por par�metros un nodo, se accede al producto de este nodo
	y se imprimen los datos.*/
	void printTreeRec(NodoAVL*& node);


public:
	/*Constructor vacio de la clase ArbolAvl*/
	ArbolAvl();
	/*Destructor de la clase ArbolAvl*/
	~ArbolAvl();
	
	/*Este m�todo hace un llamado a dos m�todos, uno de inserci�n recursivo y otro el cual revisa el orden del �rbol AVL.
	@param cliente - clase cliente del nodo a insertar*/
	void insertNewNode(Cliente* cliente);
	/*Este m�todo hace un llamado a otro m�todo el cual elimina un producto de forma recursiva recibiendo por par�metro el c�digo Producto*/
	void deleteNode(int rut);
	/*Este busca un producto del �rbol AVL de forma recursiva.
	Para esto, se le env�a por par�metros un nodo y el c�digo del producto.
	Una vez encontrado el producto, este se retorn*/
	Cliente* searchNode(int rut);
	/*Este m�todo hace un llamado a otro m�todo el cual despliega los productos
	de forma recursiva, para esto env�a la ra�z como par�metro.*/
	void printTree();
	/*Este m�todo hace un llamado a otro m�todo el cual elimina el �rbol
	completo de forma recursiva. Se le env�a al m�todo recursivo la ra�z
	del �rbol como par�metro.*/
	void deleteTree();
};




