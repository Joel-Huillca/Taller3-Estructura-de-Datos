#include "Cliente.h"

Cliente::Cliente()
{
}

Cliente::Cliente(string nombre, string apellido, string rut, string pelicula)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->rut = rut;
	this->pelicula = pelicula;
	
}

Cliente::Cliente(string nombre, string apellido, string rut, string pelicula, int fila, int columna, string salaCola)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->rut = rut;
	this->pelicula = pelicula;
	this->fila = fila;
	this->columna = columna;
	this->salaCola = salaCola;

}

string Cliente::getNombre()
{
	return this->nombre;
}

string Cliente::getApellido()
{
	return this->apellido;
}

string Cliente::getRut()
{
	return this->rut;
}

string Cliente::getPelicula()
{
	return this->pelicula;
}

int Cliente::getFila()
{
	return this->fila;
}

int Cliente::getColumna()
{
	return this->columna;
}

string Cliente::getSalaCola()
{
	return this->salaCola;
}

int Cliente::getRutNumero()
{   
	string rutAux = this->rut;
	//Eliminan los ' 'y'.'
	rutAux.erase(remove(rutAux.begin(), rutAux.end(), ' '));
	rutAux.erase(remove(rutAux.begin(), rutAux.end(), '.'));
	rutAux.erase(8); //Solo quedan los primeros 6 digitos
	int rutInt = stoi(rut);
	return rutInt;
}

void Cliente::printCliente()
{
	cout << "\nNombre: " << this->nombre << ", Apellido: "<< this->apellido << ", Rut: " << this->rut << ", Pelicula: " << this->pelicula << endl;
}


string Cliente::setPelicula(string new_pelicula)
{
	return this->pelicula = new_pelicula;
}

string Cliente::setSala_columna(string new_sala_Columna)
{
	return this->salaCola = new_sala_Columna;
}

Cliente::~Cliente()
{
}

int Cliente::setFila(int new_fila)
{
	return this->fila = new_fila;
}

int Cliente::setColumna(int new_columna)
{
	return this->columna = new_columna;
}
