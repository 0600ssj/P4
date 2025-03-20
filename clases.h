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
		// CONSTRUCTORES //
		DTFecha();
		DTFecha(int dia,int mes,int anio);
		~DTFecha();
		// GETTERS //
		int getDia();
		int getMes();
		int getAnio();
		// SETTERS //
		void setDia(int dia);
		void setMes(int mes);
		void setAnio(int anio);
};

class DTRefer{
	private:
		string DOI;
		string titulo;
		DTFecha fecha;
		set<string> autores;
	public:
		// CONSTRUCTORES //
		DTRefer();
		DTRefer(string DOI, string titulo, DTFecha fecha, set<string> autores);
		~DTRefer();
		// GETTERS //
		string getDOI();
		string getTitulo();
		DTFecha getFecha();
		set<string> getAutores();
		// SETTERS //
		void setDOI(string DOI);
		void setTitulo(string titulo);
		void setFecha(DTFecha fecha);
		void setAutores(const set<string>& autores); // ?
		// OPERACIONES //
		friend ostream& operator<<(ostream&, const DTRefer& refer);
};

class Publicacion{
	private:
		string DOI;
		string titulo;
		DTFecha fecha;
		set<Investigador*> suInvestigador;
	public:
		// CONSTRUCTORES //
		Publicacion();
		Publicacion(string DOI, string titulo, DTFecha fecha);
		virtual ~Publicacion(); // ?
		// GETTERS //
		string getDOI();
		string getTitulo();
		DTFecha getFecha();
		set<Investigador*> getSuInvestigador(); // Preguntar si va
		// SETTERS //
		void setDOI(string DOI);
		void setTitulo(string titulo);
		void setFecha(DTFecha fecha);
		void setSuInvestigador(set<Investigador*> suInvestigador); // Preguntar si va
		// OPERACIONES //
		DTRefer getDT();
		void agregarInvestigador(Investigador* investigador);
		virtual bool contienePalabra(string palabra) = 0 ;
};

class ArticuloRevista : public Publicacion{
	private:
		string revista;
		string extracto;
	public:	
		// CONSTRUCTORES //
		ArticuloRevista();
		ArticuloRevista(string revista, string extracto);
		~ArticuloRevista();
		// GETTERS //
		string getRevista();
		string getExtracto();
		// SETTERS //
		void setRevista(string revista);
		void setExtracto(string extracto);
		// OPERACIONES //
		bool contienePalabra(string palabra);
};

class Libro : public Publicacion{
	private:
		string editorial;
		set<string> palabrasDestacadas;
	public:
		// CONSTRUCTORES //
		Libro();
		Libro(string editorial, set<string> palDest);
		~Libro();
		// GETTERS //
		string getEditorial();
		set<string> getPalDest();
		// SETTERS //
		void setEditorial(string editorial);
		void setPalDest(set<string> palDest);
		// OPERACIONES //
		bool contienePalabra(string palabra);
};

class PaginaWeb : public Publicacion{
	private:
		string url;
		string contenidoExtraido;
	public:
		// CONSTRUCTORES //
		PaginaWeb();
		PaginaWeb(string url,string contExt);
		~PaginaWeb();
		// GETTERS //
		string getUrl();
		string getContenidoExtraido();
		// SETTERS //
		void setUrl(string url);
		void setContenidoExtraido(string contenidoExtraido);
		// OPERACIONES //
		bool contienePalabra(string palabra);

};

class Investigador{
	private: 
		string ORCID;
		string nombre;
		string institucion;
		set<Publicacion*> susPublicaciones;
	public:
		// CONSTRUCTORES //
		Investigador();
		Investigador(string ORCID, string nombre, string institucion);
		~Investigador();
		// GETTERS //
		string getORCID();
		string getNombre();
		string getInstitucion();
		set<Publicacion*> getSusPublicaciones(); // Preguntar si va
		// SETTERS //
		void setORCID(string ORCID);
		void setNombre(string nombre);
		void setInstitucion(string institucion);
		void setSusPublicaciones(string ORCID, string nombre, string institucion); // Preguntar si va
		// OPERACIONES //
		string toString();
		set<string> listaPublicaciones(DTFecha desde,string palabra);
};

#endif