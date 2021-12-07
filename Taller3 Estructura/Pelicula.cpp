#include "Pelicula.h"

Pelicula::Pelicula()
{
}

Pelicula::Pelicula(string pelicula, int duracionHoras, int duracionMinutos, string genero, int puntajePelicula, string clasificacion)
{
	this->pelicula = pelicula;
	this->duracionHoras = duracionHoras;
	this->duracionMinutos= duracionMinutos;
	this->genero = genero;
	this->puntuajePelicula = puntajePelicula;
	this->clasificacion = clasificacion;
}

string Pelicula::getPelicula()
{
	return this->pelicula;
}

int Pelicula::getDuracionHoras()
{
	return this->duracionHoras;
}

int Pelicula::getDuracionMinutos()
{
	return this->duracionMinutos;
}

string Pelicula::getGenero()
{
	return this->genero;
}

int Pelicula::getPuntajePelicula()
{
	return this->puntuajePelicula;
}

string Pelicula::getClasificacion()
{
	return this->clasificacion;
}
