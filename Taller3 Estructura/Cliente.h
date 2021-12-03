#pragma once
#include <iostream>
#include <string>
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
	string sala_cola;

public:
	Cliente();
	Cliente(string nombre, string apellido, string rut, string pelicula, int fila, int columna, string sala_Cola);

/*  Get's  de la clase Cliente  */
	string getNombre();
	string getApellido();
	string getRut();
	string getPelicula();
	int getFila();
	int getColumna();
	string getSala_cola();


/*  Set's de la clase Cliente
	@param */
	string setPelicula();
	int setFila();
	int setColumna();
	string setSala_columna();

};

