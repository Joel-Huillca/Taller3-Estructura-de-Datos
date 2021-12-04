#include "Cliente.h"

Cliente::Cliente()
{
}

Cliente::Cliente(string nombre, string apellido, string rut, string pelicula, int fila, int columna, string sala_Cola)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->rut = rut;
	this->pelicula = pelicula;
	this->fila = fila;
	this->columna = columna;
	this->sala_cola = sala_Cola;

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

string Cliente::getSala_cola()
{
	return this->sala_cola;
}

string Cliente::setPelicula(string new_pelicula)
{
	return this->pelicula = new_pelicula;
}

string Cliente::setSala_columna(string new_sala_Columna)
{
	return this->sala_cola = new_sala_Columna;
}

int Cliente::setFila(int new_fila)
{
	return this->fila = new_fila;
}

int Cliente::setColumna(int new_columna)
{
	return this->columna = new_columna;
}







