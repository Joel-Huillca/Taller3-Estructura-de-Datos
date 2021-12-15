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
	/*Constructor de la clase Sistema*/
	Sistema();
	/*Destructor de la clase Sistema*/
	~Sistema();
	/*Menu principal de la aplicacion*/
	void menuPrincipal(); 
	/*Sub menu para el menu sala de cine,retorna un char*/
	char subMenu();
	/*Menu fila de espera para operar con la fila*/
	void menuFilaEspera();
	/* Menu sala de cine para operar con la sala de cine*/
	void menuSalaCine();
	/*Menu estadisticas para obtener las estadisticas solicitadas*/
	void menuEstadisticas();
	/*Metodo para leer y guardar los clientes del txt*/
	void lecturaClientes();
	/*Metodo para leer y guardas las peliculas del txt*/
	void lecturaPeliculas();
	/*Menu para salir y desplegar el archivo de salida*/
	bool salir_Menu();
	/*Metodo para comparar si la pelicula que ingresa el cliente esta en el sistema
	@param peliculaCliente - pelicula que el cliente quiere ver*/
	string recibirPelicula(string peliculaCliente);
};

