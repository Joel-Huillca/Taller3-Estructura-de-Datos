#pragma once
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include "Cliente.h"
#include "Pelicula.h"
#include "MatrizPP.h"
#include "ArbolAvl.h"


using namespace std;

class Sistema
{
private:
	queue<Cliente> cola;
	queue<Cliente> cola_Esp;
	Pelicula* pelicula;
	Cliente* cliente;
	MatrizPP* mpp;
	
public:
	Sistema();
	~Sistema();

	void menuPrincipal();

	bool subMenu();

	void menuFilaEspera();

	void menuSalaCine();

	void menuEstadisticas();

	void lecturaClientes();

	void lecturaPeliculas();
};

