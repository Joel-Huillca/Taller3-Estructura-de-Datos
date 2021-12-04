#include "NodoAVL.h"
using namespace std;
NodoAVL::NodoAVL()
{
}

NodoAVL::NodoAVL(Cliente* cliente)
{
    this-> cliente = cliente;
    this-> hijoIzq = nullptr;
    this-> hijoDer = nullptr;
    this-> factorBalance = 0;
}

void NodoAVL::agregar(Cliente* cliente)
{
	if (!this->cliente)
	{
		return;
	}
	if (this->cliente->getRut() == cliente->getRut())
	{
		return;
	}
	if (cliente->getRut() > this->cliente->getRut())
	{
		if (this->hijoDer)
		{
			this->hijoDer->agregar(cliente);
		}
		else {
			this->hijoDer = new NodoAVL(cliente);
		}
	}

	else
	{
		if (this->hijoIzq)
		{
			this->hijoIzq->agregar(cliente);
		}
		else {
			this->hijoIzq = new NodoAVL(cliente);
		}
	}
}

Cliente* NodoAVL::getCliente()
{
    return this->cliente;
}

void NodoAVL::setCliente(Cliente* cliente)
{
}

NodoAVL* NodoAVL::getHijoIzq()
{
	return this->hijoIzq;
}

NodoAVL* NodoAVL::getHijoDer()
{
	return this->hijoDer;
}

void NodoAVL::preOrden()
{
    cout << this->cliente->getRut() << endl;
    if (this->hijoIzq)
    {
        this->hijoIzq->preOrden();
    }
    if (this->hijoDer)
    {
        this->hijoDer->preOrden();
    }
}

void NodoAVL::inOrden()
{
    if (this->hijoIzq)
    {
        this->hijoIzq->inOrden();
    }
	//cout << "-" << this->getCliente()->getNombre() << endl;
    if (this->hijoDer)
    {
        this->hijoDer->inOrden();
    }
}

void NodoAVL::postOrden()
{
}





