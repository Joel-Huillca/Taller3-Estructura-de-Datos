#pragma once

#include <algorithm>
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <ostream>
#include "Pelicula.h"
#include "MatrizPP.h"
#include "ArbolAvl.h"


using namespace std;

class Sistema
{
private:
	queue<Cliente> cola;
	//queue<Cliente> cola_Esp;
	queue<string> colaNombrePelicula;
	Pelicula* pelicula;
	Cliente* cliente;
	MatrizPP* sala1 = new MatrizPP(20,30);
	MatrizPP* sala2 = new MatrizPP(20,30);
	MatrizPP* sala3 = new MatrizPP(20,30);
	Pelicula* peliculaSala1 = new Pelicula("Spiderman: No Way Home");
	Pelicula* peliculaSala2 = new Pelicula("The Lorax");
	Pelicula* peliculaSala3 = new Pelicula("John Wick");
	
	ArbolAvl* arbolAVL = new ArbolAvl();
public:
	Sistema();
	~Sistema();

	void menuPrincipal(); 
	
	char subMenu();

	void menuFilaEspera();

	void menuSalaCine();

	void menuEstadisticas();

	void lecturaClientes();

	void lecturaPeliculas();

	bool salir_Menu();

	string recibirPelicula(string peliculaCliente);


};

