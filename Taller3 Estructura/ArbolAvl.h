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

	/*Metodo que hace un llamado a dos métodos, uno de inserción recursivo y otro el cual revisa el orden del árbol AVL
	@param actual - actual nodo del arbol avl
	@param newNode - nuevo nodo a insertar del arbol avl*/
	void insertNewNodeRec(NodoAVL*& actual, NodoAVL& newNode);
	/*Este método verifica el orden de cada nodo dentro del árbol. En el caso que el FB  de un nodo en específico genere un overflow,
	@param newNode - nuevo nodo del arbol avl
	@param rut - dato del nodo tipo rut*/
	int checkOrder(NodoAVL* newNode, int rut);
	/*Este método mide la altura del árbol AVL recibiendo por parámetro un nodo
	@param node - nodo del arbol avl*/
	int height(NodoAVL* node);
	/*Este método calcula el FB del árbol AVL recibiendo por parámetro un nodo
	@param node - nodo del arbol avl*/
	int calculateOrder(NodoAVL* node);
	/*Este método es llamado por el método checkOrder en caso de haber ocurrido un overflow.
	Su función es hacer una rotación RR del nodo afectado recibiendo por parámetro el nodo actual
	@param actual - nodo actual del arbol avl*/
	void rotationRR(NodoAVL* actual);
	/*Este método es llamado por el método checkOrder en caso de haber ocurrido un overflow.
	Su función es hacer una rotación LL del nodo afectado recibiendo por parámetro el nodo actual
	@param actual - nodo actual del arbol avl*/
	void rotationLL(NodoAVL* actual);
	/*Este método es llamado por el método checkOrder en caso de haber ocurrido un overflow.
	Su función es hacer una rotación RL del nodo afectado recibiendo por parámetro el nodo actual
	@param actual - nodo actual del arbol avl*/
	void rotationRL(NodoAVL* actual);
	/*Este método es llamado por el método checkOrder en caso de haber ocurrido un overflow.
	Su función es hacer una rotación LR del nodo afectado recibiendo por parámetro el nodo actual
	@param actual - nodo actual del arbol avl*/
	void rotationLR(NodoAVL* actual);
	/*Este elimina un producto del árbol AVL de forma recursiva y hace un llamado almétodo checkOrder
	para verificar el orden del árbol. Para esto, se le envía por parámetros un nodo y el código del producto.
	@param node - nodo del codigo a elimir
	@param rut - rut del nodo a eliminar*/
	void deleteNodeRec(NodoAVL*& node, int rut);
	/*Este método recibe por parámetros un nodo y un booleano.
	Este busca la última hoja del árbol (derecha o izquierda) y lo retorna
	@param node - nodo del arbol avl
	@param direction booleano de la direccion del nodo*/
	NodoAVL*& minimum(NodoAVL*& node, bool direction);
	/*Este método recibe un Producto y hace un llamado a otro método recursivo el cual
	busca este producto en el Árbol, recibiendo por parámetro el código Producto y la
	raíz del Árbol. Después retorna el producto.*/
	Cliente* searchNodeRec(NodoAVL* node, int rut);
	/*Este elimina cada nodo del árbol AVL de forma recursiva.
	Para esto, se le envía por parámetros un nodo.*/
	void deleteTreeRec(NodoAVL* actual);
	/*Este va desplegando cada dato de los productos del árbol AVL de forma recursiva.
	Para esto, se le envía por parámetros un nodo, se accede al producto de este nodo
	y se imprimen los datos.*/
	void printTreeRec(NodoAVL*& node);


public:
	/*Constructor vacio de la clase ArbolAvl*/
	ArbolAvl();
	/*Destructor de la clase ArbolAvl*/
	~ArbolAvl();
	
	/*Este método hace un llamado a dos métodos, uno de inserción recursivo y otro el cual revisa el orden del árbol AVL.
	@param cliente - clase cliente del nodo a insertar*/
	void insertNewNode(Cliente* cliente);
	/*Este método hace un llamado a otro método el cual elimina un producto de forma recursiva recibiendo por parámetro el código Producto*/
	void deleteNode(int rut);
	/*Este busca un producto del árbol AVL de forma recursiva.
	Para esto, se le envía por parámetros un nodo y el código del producto.
	Una vez encontrado el producto, este se retorn*/
	Cliente* searchNode(int rut);
	/*Este método hace un llamado a otro método el cual despliega los productos
	de forma recursiva, para esto envía la raíz como parámetro.*/
	void printTree();
	/*Este método hace un llamado a otro método el cual elimina el árbol
	completo de forma recursiva. Se le envía al método recursivo la raíz
	del Árbol como parámetro.*/
	void deleteTree();
};




