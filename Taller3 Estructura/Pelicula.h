#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pelicula
{
private:
	string nombrePelicula;
	int duracionHoras;
	int duracionMinutos;
	string genero;
	int puntuajePelicula;
	string clasificacion;

public:
	/*Constructor vacio de la clase Pelicula*/
	Pelicula();
	/*Constructor de la clase Pelicula
	@param nombrePelicula - nombre de la pelicula
	@param duracionHoras - duracion en horas de la pelicula
	@param duracionMinutos - duracion en minutos de la pelicula
	@param genero - genero de la pelicula
	@param puntajePelicula - puntaje de la pelicula
	@param clasificacion - clasificacion de la pelicula*/
	Pelicula(string nombrePelicula, int duracionHoras, int duracionMinutos, string genero, int puntajePelicula, string clasificacion);
	/*Constructor de la clase Pelicula
	@param nombrePelicula  nombre de la pelicula*/
	Pelicula(string nombrePelicula);
	/*Gets de la clase Pelicula*/
	string getNombrePelicula();
	int getDuracionHoras();
	int getDuracionMinutos();
	string getGenero();
	int getPuntajePelicula();
	string getClasificacion();
	/*Sets de la clase Pelicula
	@param nombrePelicula - nuevo nombre de la pelicula que se desea asignar*/
	void setNombrePelicula(string nombrePelicula);
	/*Destructor de la clase Pelicula*/
	~Pelicula();
};


