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
	cout<<ref.getDOI()<<"->"<<ref.getTitulo()<<"("
	<<ref.getFecha().getDia()<<"/"
	<<ref.getFecha().getMes()<<"/"
	<<ref.getFecha().getAnio()<<")""/";
	
	set<string> autor_es = ref.getAutores();
	set<string>:: iterator it = autor_es.begin();
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

void DTRefer::setAutores(const set<string>& autores) {
    this->autores = autores;
};

//-------------------Operaciones Publicacion-----------------------//
Publicacion::Publicacion(string DOI, string titulo, DTFecha fecha){
	this->DOI = DOI;
	this->titulo = titulo;
	this->fecha = fecha;
};

Publicacion::Publicacion(){};

string Publicacion::getDOI() { 
	return DOI;
}

string Publicacion::getTitulo() { 
	return titulo; 
}

DTFecha Publicacion::getFecha() { 
	return fecha;
}

DTRefer Publicacion::getDT() {
    set<string> nombresAutores;
    for (Investigador* autor : inv) {
        nombresAutores.insert(autor->toString());
    }
    return DTRefer(DOI, titulo, fecha, nombresAutores);
}

void Publicacion::agregarInvestigador(Investigador* investigador) {
    inv.insert(investigador);
}


Publicacion::~Publicacion(){};

bool Publicacion::contienePalabra(string palabra){}


// ---------------------------------- Operaciones ArticuloRevista --------------------------//
ArticuloRevista::ArticuloRevista(string revista, string extracto){
	this->revista = revista;
	this->extracto = extracto;
}

ArticuloRevista::~ArticuloRevista(){};

bool ArticuloRevista::contienePalabra(string palabra) {
    return extracto.find(palabra) != std::string::npos;
}


// -------------------------------Operaciones Libro ----------------------------//
Libro::Libro(string editorial, set<string> palDest){
	this->editorial = editorial;
	this->palabrasDestacadas = palDest;
};

Libro::~Libro(){};

bool Libro::contienePalabra(string palabra){
	return palabrasDestacadas.find(palabra) != palabrasDestacadas.end();
};


//---------------------------------- Operaciones PaginaWeb ----------------------------------//
PaginaWeb::PaginaWeb(string url,string contExt){
	this->url = url;
	this->contenidoExtraido = contExt;
};

PaginaWeb::~PaginaWeb(){};

bool PaginaWeb::contienePalabra(string palabra){
	return contenidoExtraido.find(palabra) != std::string::npos;
};

// ------------------------------ Operaciones Investigador -----------------------------------//

Investigador::Investigador(string ORCID, string nombre, string institucion) {
	ORCID = this->ORCID;
	nombre = this->nombre;
	institucion = this->institucion;
};

string Investigador :: getORCID(){
	return ORCID;
};

string Investigador :: getNombre(){
	return nombre;
};

string Investigador :: getInstitucion(){
	return institucion;
};

string Investigador::toString(){
	return ORCID + "->" + nombre + "/" + institucion;
};

// class Publicacion{
// 	protected:
// 		string DOI;
// 		string titulo;
// 		DTFecha fecha;
// 		set<Investigador*> inv;
// 	public:
// 		Publicacion(string DOI, string titulo, DTFecha fecha);
// 		virtual ~Publicacion(); 
// 		// OPERACIONES //
// 		string getDOI();
// 		string getTitulo();
// 		DTFecha getFecha();
// 		DTRefer getDT();
// 		void agregarInvestigador(Investigador* investigador);
// 		virtual bool contienePalabra(string palabra) = 0 ;
// };
set<string> Investigador ::listarPublicaciones(DTFecha desde,string palabra){
	set<string> nuevoSet;
    for (const string& pub : susPublis) {
		if(dynamic_cast(Libro)(pub)){
			
		}
	}
    return DTRefer(DOI, titulo, fecha, nombresAutores);
};