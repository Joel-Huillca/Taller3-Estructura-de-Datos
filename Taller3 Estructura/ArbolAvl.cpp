#include "ArbolAvl.h"

ArbolAvl::ArbolAvl()
{
	this->raiz = nullptr;
}


ArbolAvl::~ArbolAvl()
{
	
}




void ArbolAvl::insertNewNode(Cliente* cliente)
{
	NodoAVL* newNode = new NodoAVL(cliente);
	insertNewNodeRec(this->raiz, *newNode);
	checkOrder(newNode, newNode->getCliente()->getRutNumero());
}

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

void ArbolAvl::deleteNode(int rut)
{
	deleteNodeRec(this->raiz, rut);
}

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

Cliente* ArbolAvl::searchNode(int rut)
{
	return searchNodeRec(this->raiz, rut);
}

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
void ArbolAvl::printTree()
{
	printTreeRec(this->raiz);
}

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

void ArbolAvl::deleteTree()
{
	deleteTreeRec(this->raiz);
}

void ArbolAvl::deleteTreeRec(NodoAVL* actual) {
	if (actual) {
		deleteTreeRec(actual->getHijoIzq());
		deleteTreeRec(actual->getHijoDer());
		delete actual;
		actual = NULL;
	}
	return;
}
