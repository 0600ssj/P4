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
		// cambio //
		set<string> autores;
		// cambio //
	public:
		// cambio //
		Publicacion(string DOI, string titulo, DTFecha fecha);
		virtual ~Publicacion(); 
		set<string> getAutores() const;
		// cambio //	
		DTRefer getDT();
		virtual bool contienePalabra(string palabra) = 0 ;
};

class ArticuloRevista : public Publicacion{
	private:
		string revista;
		string extracto;
	public:
		bool contienePalabra(const string &palabra) const;
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