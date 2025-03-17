#include <iostream>
#include <list>
#include <map>
#include <iostream>
#include <string>
#include <set>

std::list<Publicacion*> publicaciones;
std::map<std::string, Publicacion*> map_publicaciones;

std::list<Investigador*> investigadores;
std::map<std::string, Investigador*> map_investigadores;

class DTFecha{
	private:
		int dia,mes,anio;
	public:
		DTFecha(int,int,int);
		~DTFecha();
		int getDia();
		int getMes();
		int getAnio();	
};

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

class DTRefer{
	private:
		string DOI;
		string titulo;
		DTFecha fecha;
		Set(string) autores;
	public:
		DTRefer(string DOI, string titulo, DTFecha fecha);
		~DTRefer();
		string getDOI();
		string getTitulo();
		DTFecha getFecha();
		Set(string) getAutores();
};

string DTRefer::getDOI(){
	return this->DOI;
}

string DTRefer::getTitulo(){
	return this->titulo;
}

DTFecha DTRefer::getFecha(){
	return this->fecha;
}

Set(string) DTRefer::getAutores(){}

DTRefer:: DTRefer(string DOI, string titulo, DTFecha fecha){
	this->DOI = DOI;
	this->titulo = titulo;
	this->fecha = fecha;
}

DTRefer::~DTRefer(){};

class Publicacion{
	protected:
		string DOI;
		string titulo;
		DTFecha fecha;
	public:
		DTRefer getDT();
		virtual bool contienePalabra(palabra: string) = 0 ;
};

DTRefer Publicacion::getDT(){}

class ArticuloRevista : public Publicacion{
	private:
		string revista;
		string extracto;
	public:
		bool contienePalabra(palabra: string);
}

bool ArticuloRevista::contienePalabra(palabra: string){}

class Libro : public Publicacion{
	private:
		string editorial;
		Set(string) palabrasDestacadas;
	public:
		bool contienePalabra(palabra: string);
}

bool Libro::contienePalabra(palabra: string){}

class PaginaWeb : public Publicacion{
	private:
		string url;
		string contenidoExtraido;
	public:
		bool contienePalabra(palabra: string);
}
bool PaginaWeb::contienePalabra(palabra: string){}

class Investigador{
	private: 
		string ORCID;
		string nombre;
		string institucion;
	public:
		string toString();
		Set(String) listaPublicaciones(desde: DTFecha,palabra: String);
}
string Investigador::toString(){}
Set(String) Investigador ::listaPublicaciones(desde: DTFecha,palabra: String){}

void coleccion_guardarPublicacion(Publicacion* pub){
	publicaciones.push_back(pub);
	std::pair<std::string, Publicacion*> entry(pub->getDOI(), pub);
    map_publicaciones.insert(entry);
}
void coleccion_eliminarPublicacion(Publicacion* pub){
	publicaciones.remove(pub);
	map_publicaciones.erase(pub->getDOI());
}

void coleccion_guardarInvestigador(Investigador* inv){
	investigadores.push_back(inv);
	std::pair<std::string, Investigador*> entry(inv->getORCID(), inv);
    map_investigadores.insert(entry);
}

Investigador* coleccion_getInvestigador(std::string ORCID){
	return map_investigadores[ORCID];
}

Publicacion* coleccion_getPublicacion(std::string DOI){
	return map_publicaciones[DOI];
}

void parte_a(){
}

void parte_b(){
}

void parte_c(){
}

void parte_d(){
}

void parte_e(){
}

void parte_f(){
}

void parte_g(){
}

void parte_h(){
}

void parte_i(){
}

void parte_j(){
}

void parte_k(){
}


int main() {
	std::cout << "parte_a" <<  std::endl;
	parte_a();
	std::cout << "parte_b" <<  std::endl;
	parte_b();
	std::cout << "parte_c" <<  std::endl;
	parte_c();
	std::cout << "parte_d" <<  std::endl;
	parte_d();
	std::cout << "parte_e" <<  std::endl;
	parte_e();
	std::cout << "parte_f" <<  std::endl;
	parte_f();
	std::cout << "parte_g" <<  std::endl;
	parte_g();
	std::cout << "parte_h" <<  std::endl;
	parte_h();
	std::cout << "parte_i" <<  std::endl;
	parte_i();
	std::cout << "parte_j" <<  std::endl;
	parte_j();
	std::cout << "parte_k" <<  std::endl;
	parte_k();
	std::cout << "cleanUp" <<  std::endl;
	cleanUp();
	std::cout << "fin" <<  std::endl;

	return 0;
}