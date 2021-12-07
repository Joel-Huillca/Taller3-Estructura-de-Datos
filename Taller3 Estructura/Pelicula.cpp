#include "Pelicula.h"

Pelicula::Pelicula()
{
}

Pelicula::Pelicula(string nombrePelicula, int duracionHoras, int duracionMinutos, string genero, int puntajePelicula, string clasificacion)
{
	this->nombrePelicula = nombrePelicula;
	this->duracionHoras = duracionHoras;
	this->duracionMinutos= duracionMinutos;
	this->genero = genero;
	this->puntuajePelicula = puntajePelicula;
	this->clasificacion = clasificacion;
}

string Pelicula::getNombrePelicula()
{
	return this->nombrePelicula;
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
