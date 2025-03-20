#include "clases.h"

//-------------------- Operaciones DTFecha ---------------------//
DTFecha::DTFecha(int d, int m, int a){
	this->dia = d;
	this->mes = m;
	this->anio = a;
};

DTFecha::DTFecha(){
	this->dia = 0;
	this->mes = 0;
	this->anio = 0;
};

int DTFecha::getDia(){
	return this->dia;
};

int DTFecha::getMes(){
	return this->mes;
};
int DTFecha::getAnio(){
	return this->anio;
};

DTFecha::~DTFecha(){};


//---------------------- Operaciones DTRefer ---------------------//
DTRefer::DTRefer(string DOI, string titulo, DTFecha fecha, set<string> autores){
	this->DOI = DOI;
	this->titulo = titulo;
	this->fecha = fecha;
	this->autores = autores;
};

DTRefer::~DTRefer(){}


 ostream& operator << (ostream& cout, DTRefer& ref){
	cout<<ref.getDOI()<<"->"<<ref.getTitulo()<<"("<<ref.getFecha().getDia()<<"/"<<ref.getFecha().getMes()<<"/"<<ref.getFecha().getAnio()<<")""/";
	
	set<string> autor_es = ref.getAutores();
    //cambio(usar el autor_es y no ref.getAutores (obviedad))
	auto it = autor_es.begin();
	while(it != autor_es.end()){
		cout<<*it;
		if(++it != autor_es.end()) cout << ",";
	}
	return cout;
}


string DTRefer::getDOI(){
	return this->DOI;
};

string DTRefer::getTitulo(){
	return this->titulo;
};

DTFecha DTRefer::getFecha(){
	return this->fecha;
};

set<string> DTRefer::getAutores(){
    return this->autores;
};



set<string> DTRefer::getAutores()  {
    return autores;
};

void DTRefer::setAutores(const set<string>& autores) {
    this->autores = autores;
};
//cambio//





//-------------------Operaciones Publicacion-----------------------//
//cambio//
Publicacion::Publicacion(string DOI, string titulo, DTFecha fecha){
	this->DOI = DOI;
	this->titulo = titulo;
	this->fecha = fecha;
};

// cambio IMPLEMENTACION GETDT //
DTRefer Publicacion::getDT(){
    DTRefer referencia = DTRefer(this->DOI,this->titulo,this->fecha,this->autores); 
    return referencia;
};

Publicacion::~Publicacion(){};

bool Publicacion::contienePalabra(string palabra){}




//---------------------------------- Operaciones ArticuloRevista --------------------------//
bool ArticuloRevista::contienePalabra(const string &palabra) const {
    return extracto.find(palabra) != std::string::npos;

}


// -------------------------------Operaciones contienePalabra ----------------------------//
bool Libro::contienePalabra(string palabra){};


//---------------------------------- Operaciones PaginaWeb ----------------------------------//
bool PaginaWeb::contienePalabra(string palabra){};


// ------------------------------ Operaciones Investigador -----------------------------------//
string Investigador::toString(){};
set<string> Investigador ::listaPublicaciones(DTFecha desde,string palabra){};