#ifndef CLASES
#define CLASES

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <set>

using namespace std;

class DTFecha{
	private:
		int dia,mes,anio;
	public:
		DTFecha();
		DTFecha(int d,int m,int a);
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
		DTRefer(string DOI, string titulo, DTFecha fecha, set<string> autores);
		~DTRefer();
		string getDOI();
		string getTitulo();
		DTFecha getFecha();
		set<string> getAutores();
		void setAutores(const set<string>& autores);

		//para mostrar DTRefer
		friend std::ostream& operator<<(std::ostream&, const DTRefer& refer);
		
};

class Publicacion{
	protected:
		string DOI;
		string titulo;
		DTFecha fecha;
		set<Investigador*> suInvestigador;
	public:
		Publicacion(string DOI, string titulo, DTFecha fecha);
		Publicacion();
		virtual ~Publicacion(); 
		// OPERACIONES //
		string getDOI();
		string getTitulo();
		DTFecha getFecha();
		DTRefer getDT();
		void agregarInvestigador(Investigador* investigador);
		virtual bool contienePalabra(string palabra) = 0 ;
};

class ArticuloRevista : public Publicacion{
	private:
		string revista;
		string extracto;
	public:	
		ArticuloRevista(string revista, string extracto);
		~ArticuloRevista();
		void setRevista(string revista);
		void setExtracto(string extracto);
		string getRevista();
		string getExtracto();
		bool contienePalabra(string palabra);
};

class Libro : public Publicacion{
	private:
		string editorial;
		set<string> palabrasDestacadas;
	public:
		Libro(string editorial, set<string> palDest);
		~Libro();	
		bool contienePalabra(string palabra);
};

class PaginaWeb : public Publicacion{
	private:
		string url;
		string contenidoExtraido;
	public:
		PaginaWeb(string url,string contExt);
		~PaginaWeb();
		bool contienePalabra(string palabra);
};

class Investigador{
	private: 
		string ORCID;
		string nombre;
		string institucion;
		set<Publicacion*> susPublicaciones;
	public:
		Investigador(string ORCID, string nombre, string institucion);
		string getORCID();
		string getNombre();
		string getInstitucion();
		// OPERACIONES //
		string toString();
		set<string> listaPublicaciones(DTFecha desde,string palabra);
};

#endif