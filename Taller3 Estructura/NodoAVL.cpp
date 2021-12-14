#include "NodoAVL.h"
using namespace std;
NodoAVL::NodoAVL()
{
    this->cliente = cliente;
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->padre = NULL;
}

NodoAVL::NodoAVL(Cliente* cliente)
{
    this-> cliente = cliente;
    this-> hijoIzq = NULL;
    this-> hijoDer = NULL;
    this-> padre = NULL;
}


Cliente*& NodoAVL::getCliente()
{
    return this->cliente;
}

NodoAVL*& NodoAVL::getHijoIzq()
{
	return this->hijoIzq;
}

NodoAVL*& NodoAVL::getHijoDer()
{
	return this->hijoDer;
}

NodoAVL*& NodoAVL::getPadre()
{
    return this->padre;
}

void NodoAVL::setCliente(Cliente* cliente)
{
    this->cliente = cliente;
}

void NodoAVL::setHijoIzq(NodoAVL* hijoIzq)
{
    this->hijoIzq = hijoIzq;
}

void NodoAVL::setHijoDer(NodoAVL* hijoDer)
{
    this->hijoDer = hijoDer ;
}

void NodoAVL::setPadre(NodoAVL* padre)
{
    this->padre = padre;
}







