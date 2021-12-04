#include "ArbolAvl.h"

ArbolAvl::ArbolAvl()
{
	this->raiz = nullptr;
}

NodoAVL* ArbolAvl::getRaiz()
{
	return this->raiz;
}

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
}

int ArbolAvl::cantClientes()
{
	return cantNodos(raiz);
}

int ArbolAvl::cantNodos(NodoAVL* cliente)
{
	if (cliente)
	{
		int izq = cantNodos(cliente->getHijoIzq());
		int der = cantNodos(cliente->getHijoDer());
		int medio = 1;
		return izq + der + medio;
	}
	return 0;

}

ArbolAvl::~ArbolAvl()
{
}
