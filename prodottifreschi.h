#ifndef PRODOTTI_H
#define PRODOTTI_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "duplicato.h"
#include "alimentari.h"

using namespace std;

namespace supermarket{
	
	class prodottifreschi : public alimentari{
		private:
			char* dataConf;
			
		public:
			prodottifreschi(); // costruttore
			prodottifreschi(const char* cod, const char* desc, const int scad, const float price, const char* dataC);
			prodottifreschi(const prodottifreschi &);
			prodottifreschi & operator=(const prodottifreschi & p);
			virtual ~prodottifreschi(); //distruttore
			virtual void stampa_dati()const;
			virtual void memorizza_dati(const char* filename)const;
			virtual void carica_dati(const char* filename);
			virtual void serialize(ofstream & of)const;
			virtual void deserialize(ifstream & in);
			void set_dataC(const char* d);
			char* get_dataC()const{return dataConf;}
			float offerta()const;
	};
	
	
	
	
	
	
	
	
	
	
	
}

#endif //PRODOTTI_H
