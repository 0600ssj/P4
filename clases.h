#ifndef CLASES
#define CLASES

#include <iostream>
#include <list>
#include <map>
#include <iostream>
#include <string>
#include <set>

using namespace std;

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

class DTRefer{
	private:
		string DOI;
		string titulo;
		DTFecha fecha;
		set<string> autores;
	public:
		DTRefer(string DOI, string titulo, DTFecha fecha);
		~DTRefer();
		string getDOI();
		string getTitulo();
		DTFecha getFecha();
		set<string> getAutores();
};

class Publicacion{
	protected:
		string DOI;
		string titulo;
		DTFecha fecha;
	public:
		DTRefer getDT();
		virtual bool contienePalabra(string palabra) = 0 ;
};

class ArticuloRevista : public Publicacion{
	private:
		string revista;
		string extracto;
	public:
		bool contienePalabra(string palabra);
};

class Libro : public Publicacion{
	private:
		string editorial;
		set<string> palabrasDestacadas;
	public:
		bool contienePalabra(string palabra);
};

class PaginaWeb : public Publicacion{
	private:
		string url;
		string contenidoExtraido;
	public:
		bool contienePalabra(string palabra);
};

class Investigador{
	private: 
		string ORCID;
		string nombre;
		string institucion;
	public:
		string toString();
		set<string> listaPublicaciones(DTFecha desde,string palabra);
};

#endif