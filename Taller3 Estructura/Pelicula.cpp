#include "Pelicula.h"

Pelicula::Pelicula()
{
}

Pelicula::Pelicula(string pelicula, int dura_Hora, int dura_Min, string genero, int puntuacion, string clasificacion)
{
	this->pelicula = pelicula;
	this->dura_Hora = dura_Hora;
	this->dura_Min = dura_Min;
	this->genero = genero;
	this->puntuacion = puntuacion;
	this->clasificacion = clasificacion;
}

string Pelicula::getPelicula()
{
	return this->pelicula;
}

int Pelicula::getDura_Hora()
{
	return this->dura_Hora;
}

int Pelicula::getDura_Min()
{
	return this->dura_Min;
}

string Pelicula::getGenero()
{
	return this->genero;
}

int Pelicula::getPuntuacion()
{
	return this->puntuacion;
}

string Pelicula::getClasificacion()
{
	return this->clasificacion;
}
