#include "clases.h"

// Operaciones DTFecha //
DTFecha::DTFecha(int a, int b, int c){
	this->dia = a;
	this->mes = b;
	this->anio = c;
}

DTFecha::~DTFecha(){}

int DTFecha::getDia(){
	return this->dia;
}
int DTFecha::getMes(){
	return this->mes;
}
int DTFecha::getAnio(){
	return this->anio;
}

//cambio//
Publicacion::Publicacion(string DOI, string titulo, DTFecha fecha){
		this->DOI = DOI;
		this->titulo = titulo;
		this->fecha = fecha;
}

Publicacion::~Publicacion() {}

set<string> DTRefer::getAutores() const {
    return autores;
}

void DTRefer::setAutores(const set<string>& autores) {
    this->autores = autores;
}
//cambio//

// cambio IMPLEMENTACION GETDT //
DTRefer Publicacion::getDT(const Publicacion& publicada){
    DTRefer referencia(publicada.getDOI(),publicada.getTitulo(),publicada.getFecha());
    referencia.setAutores(publicada.getAutores());
    return referencia;
};
// cambio IMPLEMENTACION GETDT //

// Operaciones DTRefer //
DTRefer:: DTRefer(string DOI, string titulo, DTFecha fecha){
	this->DOI = DOI;
	this->titulo = titulo;
	this->fecha = fecha;
}

DTRefer::~DTRefer(){}

string DTRefer::getDOI(){
	return this->DOI;
}

string DTRefer::getTitulo(){
	return this->titulo;
}

DTFecha DTRefer::getFecha(){
	return this->fecha;
}

Set<string> DTRefer::getAutores(){
    return this->autores;
}


// Operaciones Publicacion //
DTRefer Publicacion::getDT(){}


// Operaciones ArticuloRevista //
bool ArticuloRevista::contienePalabra(string palabra){}


// Operaciones contienePalabra //
bool Libro::contienePalabra(string palabra){}


// Operaciones PaginaWeb //
bool PaginaWeb::contienePalabra(string palabra){}


// Operaciones Investigador //
string Investigador::toString(){}
set<string> Investigador ::listaPublicaciones(DTFecha desde,string palabra){}