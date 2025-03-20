#include "clases.h"

//-------------------- Operaciones DTFecha ---------------------//
DTFecha::DTFecha(){
	this->dia = 0;
	this->mes = 0;
	this->anio = 0;
};

DTFecha::DTFecha(int dia, int mes, int anio){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
};

DTFecha::~DTFecha(){};

int DTFecha::getDia(){
	return dia;
};

int DTFecha::getMes(){
	return mes;
};
int DTFecha::getAnio(){
	return anio;
};

void DTFecha::setDia(int dia){
	this->dia = dia;
};

void DTFecha::setMes(int mes){
	this->mes = mes;
};

void DTFecha::setAnio(int anio){
	this->anio = anio;
}

//---------------------- Operaciones DTRefer ---------------------//
DTRefer::DTRefer(){};

DTRefer::DTRefer(string DOI, string titulo, DTFecha fecha, set<string> autores){
	this->DOI = DOI;
	this->titulo = titulo;
	this->fecha = fecha;
	this->autores = autores;
};

DTRefer::~DTRefer(){}

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

void DTRefer::setDOI(string DOI){
    this->DOI = DOI;
};

void DTRefer::setTitulo(string titulo){
    this->titulo = titulo;
};

void DTRefer::setFecha(DTFecha fecha){
    this->fecha = fecha;
};

void DTRefer::setAutores(const set<string>& autores){
    this->autores = autores;
};

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
};

//-------------------Operaciones Publicacion-----------------------//
Publicacion::Publicacion(){};

Publicacion::Publicacion(string DOI, string titulo, DTFecha fecha){
	this->DOI = DOI;
	this->titulo = titulo;
	this->fecha = fecha;
};

Publicacion::~Publicacion(){};

string Publicacion::getDOI(){ 
	return DOI;
};

string Publicacion::getTitulo(){ 
	return titulo; 
};

DTFecha Publicacion::getFecha(){ 
	return fecha;
};

set<Investigador*> Publicacion::getSuInvestigador(){
	return suInvestigador;
};

void Publicacion::setDOI(string DOI){
	this->DOI = DOI;
};

void Publicacion::setTitulo(string titulo){
	this->titulo = titulo;
};

void Publicacion::setFecha(DTFecha fecha){
	this->fecha = fecha;
};

void Publicacion::setSuInvestigador(set<Investigador*> suInvestigador){
	this->suInvestigador = suInvestigador;
};

DTRefer Publicacion::getDT() {
    set<string> nombresAutores;
    for (Investigador* autor : inv) {
        nombresAutores.insert(autor->toString());
    }
    return DTRefer(DOI, titulo, fecha, nombresAutores);
};

void Publicacion::agregarInvestigador(Investigador* investigador){
    inv.insert(investigador);
};

bool Publicacion::contienePalabra(string palabra){}; // Operacion abstracta


// ---------------------------------- Operaciones ArticuloRevista --------------------------//
ArticuloRevista::ArticuloRevista(){};

ArticuloRevista::ArticuloRevista(string revista, string extracto){
	this->revista = revista;
	this->extracto = extracto;
}

ArticuloRevista::~ArticuloRevista(){};

void ArticuloRevista::setRevista(string revista){
	this->revista = revista;
};

void ArticuloRevista::setExtracto(string extracto){
	this->extracto = extracto;
};

string ArticuloRevista::getRevista(){
	return revista;	
};

string ArticuloRevista::getExtracto(){
	return extracto;	
};

bool ArticuloRevista::contienePalabra(string palabra) {
    return extracto.find(palabra) != std::string::npos;
}


// -------------------------------Operaciones Libro ----------------------------//
Libro::Libro(){};

Libro::Libro(string editorial, set<string> palDest){
	this->editorial = editorial;
	this->palabrasDestacadas = palDest;
};

Libro::~Libro(){};

void Libro::setEditorial(string editorial){
	this->editorial = editorial;
};

void Libro::setPalDest(set<string> palDest){
	this->palabrasDestacadas = palDest;
};

string Libro::getEditorial(){
	return editorial;	
};

set<string> Libro::getPalDest(){
	return palabrasDestacadas;	
};

bool Libro::contienePalabra(string palabra){
	return palabrasDestacadas.find(palabra) != palabrasDestacadas.end();
};


//---------------------------------- Operaciones PaginaWeb ----------------------------------//
PaginaWeb::PaginaWeb(){};

PaginaWeb::PaginaWeb(string url,string contExt){
	this->url = url;
	this->contenidoExtraido = contExt;
};

PaginaWeb::~PaginaWeb(){};

bool PaginaWeb::contienePalabra(string palabra){
	return contenidoExtraido.find(palabra) != std::string::npos;
};

string PaginaWeb::getUrl(){
	return url;
};

string PaginaWeb::getContenidoExtraido(){
	return contenidoExtraido;
};

void PaginaWeb::setUrl(string url){
	this->url = url;
};

void PaginaWeb::setContenidoExtraido(string contenidoExtraido){
	this->contenidoExtraido = contenidoExtraido;
};

// ------------------------------ Operaciones Investigador -----------------------------------//
Investigador::Investigador(){};

Investigador::Investigador(string ORCID, string nombre, string institucion){
	this->ORCID = ORCID;
	this->nombre = nombre;
	this->institucion = institucion;
};

Investigador::~Investigador(){};

string Investigador::getORCID(){
	return ORCID;
};

string Investigador::getNombre(){
	return nombre;
};

string Investigador::getInstitucion(){
	return institucion;
};

set<Publicacion*> Investigador::getSusPublicaciones(){
	return susPublicaciones;
}

void Investigador::setORCID(string ORCID){
	this->ORCID = ORCID;
};

void Investigador::setNombre(string nombre){
	this->nombre = nombre;
};

void Investigador::setInstitucion(string institucion){
	this->institucion = institucion;
};

void Investigador::setSusPublicaciones(string ORCID, string nombre, string institucion){
	this->susPublicaciones = susPublicaciones;
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
	// set<string> nuevoSet;
    // for (const string& pub : susPublis) {
	// 	if(dynamic_cast(Libro)(pub)){
			
	// 	}
	// }
    // return DTRefer(DOI, titulo, fecha, nombresAutores);
};