#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pelicula
{
private:
	string pelicula;
	int duracionHoras;
	int duracionMinutos;
	string genero;
	int puntuajePelicula;
	string clasificacion;

public:
	Pelicula();
	Pelicula(string pelicula, int duracionHoras, int duracionMinutos, string genero, int puntajePelicula, string clasificacion);

	string getPelicula();
	int getDuracionHoras();
	int getDuracionMinutos();
	string getGenero();
	int getPuntajePelicula();
	string getClasificacion();


};

