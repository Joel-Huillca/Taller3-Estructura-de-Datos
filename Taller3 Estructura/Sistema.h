#pragma once
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;

class Sistema
{
public:
	Sistema();
	~Sistema();

	void menuPrincipal();

	void menuFilaEspera();

	void menuSalaCine();

	void menuEstadisticas();

	void lecturaClientes();

	void lecturaPeliculas();
};

