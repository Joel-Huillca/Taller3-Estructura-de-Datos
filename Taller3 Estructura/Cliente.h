#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Cliente
{

private:
	string nombre;
	string apellido;
	string rut;
	string pelicula;
	int fila;
	int columna;
	string salaCola;

public:
	/*Constructor vacio de la clase cliente*/
	Cliente();
	/*Constructor de la clase cliente
	@param nombre - nombre del cliente
	@param apellido - apellido del cliente
	@param rut - rut del cliente
	@param pelicula - pelicula que quiere ver el cliente*/
	Cliente(string nombre, string apellido, string rut, string pelicula);
	/*Constructor de la clase cliente
	@param nombre - nombre del cliente
	@param apellido - apellido del cliente
	@param rut - rut del cliente
	@param pelicula - pelicula que quiere ver el cliente
	@param fila - coordenada fila que el cliente desea
	@param columna - coordenada columna que el cliente desea
	@param salaCola - caracter que designa si va a sala de cine o a la cola de espera*/
	Cliente(string nombre, string apellido, string rut, string pelicula, int fila, int columna, string salaCola);

/*  Get's  de la clase Cliente  */
	string getNombre();
	string getApellido();
	string getRut();
	string getPelicula();
	int getFila();
	int getColumna();
	string getSalaCola();
	/*Metodo publico para devolver el rut sin el digito verificador*/
	int getRutNumero();

	/*Metodo publico para imprimir los datos del cliente*/
	void printCliente();

/*  Set's de la clase Cliente
	@param new_pelicula - nueva pelicula que se desea asignar
	@param new_fila - nueva fila que se desea asignar
	@param new columnaa - nueva columna que se desea asignar
	@param new_sala_Columna - nuevo caracter sala columna que se desea asignar*/
	string setPelicula(string new_pelicula);
	int setFila(int new_fila);
	int setColumna(int new_columna);
	string setSala_columna(string new_sala_Columna);

	/*Destructor de la clase Cliente*/
	~Cliente();
};

