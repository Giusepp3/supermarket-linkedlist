#ifndef ALIMENTARI_H
#define ALIMENTARI_H
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

namespace supermarket{
	
	class alimentari{
		private:
			char* codice;
			char* descrizione;
			int meseScad;
			float costo;
		protected:
			virtual void print(ostream & os)const;
		public:
			alimentari(); //costruttore
			alimentari(const char* cod, const char* desc, const int scad, const float price);
			virtual ~alimentari(); //distruttore
			alimentari(const alimentari &);
			alimentari & operator=(const alimentari &);
			virtual void stampa_dati()const;
			virtual void memorizza_dati(const char* filename)const;
			virtual void carica_dati(const char* filename);
			virtual void serialize(ofstream & of)const;
			virtual void deserialize(ifstream & in);
			friend ostream & operator<<(ostream & os, const alimentari &);
			char* get_cod()const{return codice;}
			char* get_desc()const{return descrizione;}
			int get_scad()const{return meseScad;}
			float get_costo()const{return costo;}
			void set_cod(const char*);
			void set_desc(const char*);
			void set_meseScad(const int);
			void set_costo(const float);
			
		
	};
	
	
	
	
	
	
	
	
}

#endif //ALIMENTARI_H
