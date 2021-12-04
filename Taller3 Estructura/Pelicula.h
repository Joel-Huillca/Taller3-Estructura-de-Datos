#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pelicula
{
private:
	string pelicula;
	int dura_Hora;
	int dura_Min;
	string genero;
	int puntuacion;
	string clasificacion;

public:
	Pelicula();
	Pelicula(string pelicula, int dura_Hora, int dura_Min, string genero, int puntuacion, string clasificacion);

	string getPelicula();
	int getDura_Hora();
	int getDura_Min();
	string getGenero();
	int getPuntuacion();
	string getClasificacion();


};

