#include "ArbolAvl.h"

ArbolAvl::ArbolAvl()
{
	this->raiz = nullptr;
}
/*
NodoAVL* ArbolAvl::getRaiz()
{
	return this->raiz;
}*/
/*
void ArbolAvl::agregarCliente(Cliente* cliente)
{
	if (!this->raiz) //Mientras que se la Raiz = nullptr
	{
		this->raiz = new NodoAVL(cliente);
	}
	else
	{
		this->raiz->agregar(cliente);
	}
}*/

ArbolAvl::~ArbolAvl()
{
	
}



/*
Este m�todo hace un llamado a dos m�todos, uno de inserci�n recursivo y otro el cual revisa el orden del �rbol AVL.
Para ambos m�todos se env�a el nuevo nodo. Este m�todo recibe por par�metro un Producto.
*/
void ArbolAvl::insertNewNode(Cliente* cliente)
{
	NodoAVL* newNode = new NodoAVL(cliente);
	insertNewNodeRec(this->raiz, *newNode);
	checkOrder(newNode, newNode->getCliente()->getRutNumero());
}
/*
Este va insertando cada nodo de forma recursiva dentro del �rbol AVL. Para esto, se le env�a por par�metros el nodo actual y el nuevo nodo.
*/
void ArbolAvl::insertNewNodeRec(NodoAVL*& actual, NodoAVL& newNode)
{
	if (actual) {
		if (newNode.getCliente()->getRutNumero() < actual->getCliente()->getRutNumero()) {
			insertNewNodeRec(actual->getHijoIzq(), newNode);
			actual->getHijoIzq()->setPadre(actual) ;

			return;
		}
		else {
			if (newNode.getCliente()->getRutNumero() > actual->getCliente()->getRutNumero()) {
				insertNewNodeRec(actual->getHijoDer(), newNode);
				actual->getHijoDer()->setPadre(actual);

				return;
			}
		}
	}
	*&actual = &newNode;
}
/*
Este m�todo mide la altura del �rbol AVL recibiendo por par�metro un nodo.
*/
int ArbolAvl::height(NodoAVL* node)
{
	int h = 0;
	if (node != NULL)
	{
		int heightLeft = height(node->getHijoIzq());
		int heightRight = height(node->getHijoDer());
		if (heightRight > heightLeft) {
			return heightRight + 1;
		}
		return heightLeft + 1;
	}
	return 0;
}
/*
Este m�todo calcula el FB del �rbol AVL recibiendo por par�metro un nodo.
*/
int ArbolAvl::calculateOrder(NodoAVL* node)
{
	if (!node->getHijoDer() && !node->getHijoIzq()) {
		return 0;
	}
	else {

		int A = 0;
		int B = 0;

		if (node->getHijoDer()!= NULL) {
			A = height(node->getHijoDer() );
		}
		if (node->getHijoIzq() != NULL) {
			B = height(node->getHijoIzq());
		}
		return B - A;
	}
}
/*
Este m�todo verifica el orden de cada nodo dentro del �rbol. En el caso que el FB  de un nodo en espec�fico genere un overflow,
este m�todo llamar� los m�todos de rotaci�n. Este m�todo recibe por par�metro un nodo y el c�digo de un producto.
*/
int ArbolAvl::checkOrder(NodoAVL* newNode, int rut)
{
	int order;

	if (newNode == this->raiz) {
		order = calculateOrder(&*newNode);
		goto inCase;
	}
	if (calculateOrder(&*newNode->getPadre()) != 2 && calculateOrder(&*newNode->getPadre()) != -2) {

		return checkOrder(&*newNode->getPadre(), rut);
	}
	else {
		order = calculateOrder(&*newNode->getPadre());
		newNode = newNode->getPadre();

	inCase:

		if (order == 2) {

			if (newNode->getHijoIzq()->getCliente()->getRutNumero() > rut) {
				//ll
				rotationLL(newNode);
				return rut;
			}
			else {
				//lr
				rotationLR(newNode);
				return rut;
			}
		}
		if (order == -2) {
			if (newNode->getHijoDer()->getCliente()->getRutNumero() < rut) {
				//rr
				rotationRR(newNode);
				return rut;
			}
			else {
				//rl
				rotationRL(newNode);
				return rut;
			}
		}
	}
}
/*
Este m�todo es llamado por el m�todo checkOrder en caso de haber ocurrido un overflow.
Su funci�n es hacer una rotaci�n RR del nodo afectado recibiendo por par�metro el nodo actual.
*/
void ArbolAvl::rotationRR(NodoAVL* actual)
{
	NodoAVL* aux1 = actual;
	NodoAVL* aux2 = actual->getHijoDer();
	NodoAVL* aux3 = actual->getHijoDer()->getHijoDer();


	if (aux1 == this->raiz) {

		if (aux2->getHijoIzq()) {
			aux1->getHijoDer() = aux2->getHijoIzq();
			aux1->getHijoDer()->getPadre() = aux1;
		}
		else {
			aux1->getHijoDer() = nullptr;
		}
		this->raiz = aux2;
		aux2->getPadre() = nullptr;
		this->raiz->getHijoIzq() = aux1;
		aux1->getPadre() = aux2;
		return;

	}
	else if (aux1->getPadre()->getHijoDer() == actual) {

		if (aux2->getHijoIzq()) {
			aux1->getHijoDer() = aux2->getHijoIzq();
			aux1->getHijoDer()->getPadre() = aux1;
		}
		else {
			aux1->getHijoDer() = nullptr;
		}

		aux1->getPadre()->getHijoDer() = aux2;
		aux2->getPadre() = aux1->getPadre();
		aux2->getHijoIzq() = aux1;
		aux1->getPadre() = aux2;

		return;
	}
	else {


		if (aux2->getHijoIzq()) {
			aux1->getHijoDer() = aux2->getHijoIzq();
			aux1->getHijoDer()->getPadre() = aux1;
		}
		else {
			aux1->getHijoDer() = nullptr;
		}

		aux1->getPadre()->getHijoIzq() = aux2;
		aux2->getPadre() = aux1->getPadre();
		aux2->getHijoIzq() = aux1;
		aux1->getPadre() = aux2;

		return;

	}
}
/*
Este m�todo es llamado por el m�todo checkOrder en caso de haber ocurrido un overflow.
Su funci�n es hacer una rotaci�n LL del nodo afectado recibiendo por par�metro el nodo actual.
*/
void ArbolAvl::rotationLL(NodoAVL* actual)
{
	NodoAVL* aux1 = actual;
	NodoAVL* aux2 = actual->getHijoIzq();
	NodoAVL* aux3 = actual->getHijoIzq()->getHijoIzq();

	if (aux1 == this->raiz) {
		if (aux2->getHijoDer()) {
			aux1->getHijoIzq() = aux2->getHijoDer();
			aux1->getHijoIzq()->getPadre() = aux1;
		}
		else {
			aux1->getHijoIzq() = nullptr;
		}
		this->raiz = aux2;
		aux2->getPadre() = nullptr;
		this->raiz->getHijoDer() = aux1;
		aux1->getPadre() = aux2;
		return;
	}
	else if (aux1->getPadre()->getHijoIzq() == actual) {

		if (aux2->getHijoDer()) {
			aux1->getHijoIzq() = aux2->getHijoDer();
			aux1->getHijoIzq()->getPadre() = aux1;
		}
		else {
			aux1->getHijoIzq() = nullptr;
		}

		aux1->getPadre()->getHijoIzq() = aux2;
		aux2->getPadre() = aux1->getPadre();
		aux2->getHijoDer() = aux1;
		aux1->getPadre() = aux2;

		return;
	}
	else {

		if (aux2->getHijoDer()) {
			aux1->getHijoIzq() = aux2->getHijoDer();
			aux1->getHijoIzq()->getPadre() = aux1;
		}
		else {
			aux1->getHijoIzq() = nullptr;
		}

		aux1->getPadre()->getHijoDer() = aux2;
		aux2->getPadre() = aux1->getPadre();
		aux2->getHijoDer() = aux1;
		aux1->getPadre() = aux2;

		return;
	}
}
/*
Este m�todo es llamado por el m�todo checkOrder en caso de haber ocurrido un overflow.
Su funci�n es hacer una rotaci�n RL del nodo afectado recibiendo por par�metro el nodo actual.
*/
void ArbolAvl::rotationRL(NodoAVL* actual)
{
	NodoAVL* aux1 = actual;
	NodoAVL* aux2 = actual->getHijoDer();
	NodoAVL* aux3 = actual->getHijoDer()->getHijoIzq();



	if (aux1 == this->raiz) {

		this->raiz = aux3;
		aux3->getPadre() = nullptr;
		aux3->getHijoIzq() = aux1;
		aux1->getPadre() = aux3;
		aux3->getHijoDer() = aux2;
		aux2->getPadre() = aux3;
		aux1->getHijoDer() = nullptr;
		aux2->getHijoIzq() = nullptr;
		return;
	}
	else if (aux1->getPadre()->getHijoIzq() == actual) {

		aux1->getPadre()->getHijoIzq() = aux3;
		aux3->getPadre() = aux1->getPadre();
		aux3->getHijoIzq() = aux1;
		aux1->getPadre() = aux3;
		aux1->getHijoDer() = nullptr;
		aux3->getHijoDer() = aux2;
		aux2->getPadre() = aux3;
		aux2->getHijoIzq() = nullptr;
		return;
	}
	else {

		aux1->getPadre()->getHijoDer() = aux3;
		aux3->getPadre() = aux1->getPadre();
		aux3->getHijoDer() = aux2;
		aux1->getPadre() = aux3;
		aux1->getHijoIzq() = nullptr;
		aux3->getHijoIzq() = aux1;
		aux2->getPadre() = aux3;
		aux2->getHijoDer() = nullptr;
		return;
	}
}
/*
Este m�todo es llamado por el m�todo checkOrder en caso de haber ocurrido un overflow.
Su funci�n es hacer una rotaci�n LR del nodo afectado recibiendo por par�metro el nodo actual.
*/
void ArbolAvl::rotationLR(NodoAVL* actual)
{
	NodoAVL* aux1 = actual;
	NodoAVL* aux2 = actual->getHijoIzq();
	NodoAVL* aux3 = actual->getHijoIzq()->getHijoDer();

	if (aux1 == this->raiz) {

		this->raiz = aux3;
		aux3->getPadre() = nullptr;
		aux3->getHijoDer() = aux1;
		aux1->getPadre() = aux3;
		aux3->getHijoIzq() = aux2;
		aux2->getPadre() = aux3;
		aux1->getHijoIzq() = nullptr;
		aux2->getHijoDer() = nullptr;
		return;
	}
	else if (aux1->getPadre()->getHijoIzq() == actual) {

		aux1->getPadre()->getHijoIzq() = aux3;
		aux3->getPadre() = aux1->getPadre();
		aux3->getHijoIzq() = aux2;
		aux1->getPadre() = aux3;
		aux1->getHijoDer() = nullptr;
		aux3->getHijoDer() = aux1;
		aux2->getPadre() = aux3;
		aux2->getHijoIzq() = nullptr;
		return;
	}
	else {

		aux1->getPadre()->getHijoDer() = aux3;
		aux3->getPadre() = aux1->getPadre();
		aux3->getHijoDer() = aux1;
		aux1->getPadre() = aux3;
		aux1->getHijoIzq() = nullptr;
		aux3->getHijoIzq() = aux2;
		aux2->getPadre() = aux3;
		aux2->getHijoDer() = nullptr;
		return;
	}
}
/*
Este m�todo hace un llamado a otro m�todo el cual elimina un producto de forma recursiva recibiendo
por par�metro el c�digo Producto
*/
void ArbolAvl::deleteNode(int rut)
{
	deleteNodeRec(this->raiz, rut);
}
/*
Este elimina un producto del �rbol AVL de forma recursiva y hace un llamado alm�todo checkOrder
para verificar el orden del �rbol. Para esto, se le env�a por par�metros un nodo y el c�digo del producto.
*/
void ArbolAvl::deleteNodeRec(NodoAVL*& node, int rut)
{
	if (!node)
		return;
	if (node->getCliente()->getRutNumero() == this->raiz->getCliente()->getRutNumero() && !node->getHijoIzq() && !node->getHijoDer()) {
		node = NULL;
		delete node;
	}
	else if (rut < node->getCliente()->getRutNumero())
		deleteNodeRec(node->getHijoIzq(),rut);
	else if (rut > node->getCliente()->getRutNumero())
		deleteNodeRec(node->getHijoDer(), rut);
	else
	{
		if (!node->getHijoDer() && !node->getHijoIzq()) {
			NodoAVL* aux = node->getPadre();
			node = NULL;
			delete node;
			checkOrder(aux, aux->getCliente()->getRutNumero());
		}
		else if (node->getHijoIzq()) {
			NodoAVL*& auxMinor = minimum(node->getHijoIzq(), true);
			if (node->getHijoIzq()->getCliente()->getRutNumero() == auxMinor->getCliente()->getRutNumero()) {
				node->setCliente(auxMinor->getCliente());
				node->setHijoIzq(NULL);
			}
			else {
				node->setCliente(auxMinor->getCliente());
				auxMinor->getPadre()->setHijoDer(NULL);
			}
			auxMinor = NULL;
			delete auxMinor;
			checkOrder(node, node->getCliente()->getRutNumero());
		}
		else {
			NodoAVL*& auxMinor = minimum(node->getHijoDer(), false);
			if (node->getHijoDer()->getCliente()->getRutNumero() == auxMinor->getCliente()->getRutNumero()) {
				node->setCliente(auxMinor->getCliente());
				node->setHijoDer(NULL);
			}
			else {
				node->setCliente(auxMinor->getCliente());
				auxMinor->getPadre()->setHijoIzq(NULL);
			}
			auxMinor = NULL;
			delete auxMinor;
			checkOrder(node, node->getCliente()->getRutNumero());
		}
	}
}
/*
Este m�todo recibe por par�metros un nodo y un booleano.
Este busca la �ltima hoja del �rbol (derecha o izquierda) y lo retorna.
*/
NodoAVL*& ArbolAvl::minimum(NodoAVL*& node, bool direction)
{
	if (direction) {
		if (!node)
			return node;
		if (node->getHijoDer()) {
			return minimum(node->getHijoDer(), true);
		}
		else {
			return node;
		}
	}
	if (!node)
		return node;
	if (node->getHijoIzq()) {
		return minimum(node->getHijoIzq(), true);
	}
	else {
		return node;
	}
}
/*
Este m�todo recibe un Producto y hace un llamado a otro m�todo recursivo el cual
busca este producto en el �rbol, recibiendo por par�metro el c�digo Producto y la
ra�z del �rbol. Despu�s retorna el producto.
*/
Cliente* ArbolAvl::searchNode(int rut)
{
	return searchNodeRec(this->raiz, rut);
}
/*
Este busca un producto del �rbol AVL de forma recursiva.
Para esto, se le env�a por par�metros un nodo y el c�digo del producto.
Una vez encontrado el producto, este se retorna.
*/
Cliente* ArbolAvl::searchNodeRec(NodoAVL* node, int rut)
{
	if (!node)
		return NULL;
	if (rut == node->getCliente()->getRutNumero())
		return node->getCliente();
	if (rut < node->getCliente()->getRutNumero())
		return searchNodeRec(node->getHijoIzq(), rut);
	return searchNodeRec(node->getHijoDer(), rut);
}
/*
Este m�todo hace un llamado a otro m�todo el cual despliega los productos
de forma recursiva, para esto env�a la ra�z como par�metro.
*/
void ArbolAvl::printTree()
{
	printTreeRec(this->raiz);
}
/*
Este va desplegando cada dato de los productos del �rbol AVL de forma recursiva.
Para esto, se le env�a por par�metros un nodo, se accede al producto de este nodo
y se imprimen los datos.
*/
void ArbolAvl::printTreeRec(NodoAVL*& node)
{
	if (!node) {
		return;
	}
	else {
		printTreeRec(node->getHijoDer());
		node->getCliente()->printCliente();
		printTreeRec(node->getHijoIzq());
	}
}
/*
Este m�todo hace un llamado a otro m�todo el cual elimina el �rbol
completo de forma recursiva. Se le env�a al m�todo recursivo la ra�z
del �rbol como par�metro.
*/
void ArbolAvl::deleteTree()
{
	deleteTreeRec(this->raiz);
}
/*
Este elimina cada nodo del �rbol AVL de forma recursiva.
Para esto, se le env�a por par�metros un nodo.
*/
void ArbolAvl::deleteTreeRec(NodoAVL* actual) {
	if (actual) {
		deleteTreeRec(actual->getHijoIzq());
		deleteTreeRec(actual->getHijoDer());
		delete actual;
		actual = NULL;
	}
	return;
}
