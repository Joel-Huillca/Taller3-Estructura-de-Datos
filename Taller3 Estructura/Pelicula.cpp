#include "Pelicula.h"

Pelicula::Pelicula()
{
	this->nombrePelicula = "";
	this->duracionHoras = 0;
	this->duracionMinutos =0;
	this->genero = "";
	this->puntuajePelicula = 0;
	this->clasificacion = "";
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

Pelicula::Pelicula(string nombrePelicula)
{
	this->nombrePelicula = nombrePelicula;
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

void Pelicula::setNombrePelicula(string nuevoNombrePelicula)
{
	this->nombrePelicula = nuevoNombrePelicula;

}
