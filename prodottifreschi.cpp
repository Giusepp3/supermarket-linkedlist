#include "alimentari.h"
#include "prodottifreschi.h"

using namespace std;

namespace supermarket{
	
	prodottifreschi::prodottifreschi() :alimentari(){
		dataConf = new char[1];
		strcpy(dataConf,"");
	}
	
	prodottifreschi::prodottifreschi(const char* cod, const char* desc, const int scad, const float price, const char* dataC)
				: alimentari(cod,desc,scad,price){
					dataConf = new char[strlen(dataC)+1];
					strcpy(dataConf,dataC);
	}
	
	
	prodottifreschi::prodottifreschi(const prodottifreschi& p) : alimentari(p){
		dataConf = new char[strlen(p.dataConf)+1];
		strcpy(dataConf,p.dataConf);
		
	}
	
	
	prodottifreschi& prodottifreschi::operator=(const prodottifreschi & p){
		if(this==&p) return *this;
		set_cod(p.get_cod());
		set_desc(p.get_desc());
		set_meseScad(p.get_scad());
		set_costo(p.get_costo());
		if(dataConf) delete [] dataConf;
		dataConf = new char[strlen(p.dataConf)+1];
		strcpy(dataConf,p.dataConf); 
	
		return *this;
	}
	
	
	prodottifreschi::~prodottifreschi(){
		delete [] dataConf;
	}
	
	void prodottifreschi::set_dataC(const char* d){
		if(dataConf) delete [] dataConf;
		dataConf = new char[strlen(d)+1];
		strcpy(dataConf,d); 
	}
	
	
	void prodottifreschi::stampa_dati()const{
		alimentari::stampa_dati();
		cout << dataConf << ' ';
	}
	
	
	void prodottifreschi::serialize(ofstream & of)const{
		alimentari::serialize(of);
		int len=strlen(dataConf)+1;
		of.write((char*)&len,sizeof(len));
		of.write(dataConf,len);
		
	}
	
	void prodottifreschi::memorizza_dati(const char* filename)const{
		ofstream of;
		of.open(filename, ios :: binary | ios::out);
		if(of.fail()) exit(5);
		serialize(of);
		of.close();
		
	}
	
	void prodottifreschi::deserialize(ifstream & in){
		alimentari::deserialize(in);
		int len;
		char* buffer;
		in.read((char*)&len,sizeof(len));
		buffer=new char[len];
		in.read(buffer,len);
		set_dataC(buffer);
		delete [] buffer;
	}
	
	
	void prodottifreschi::carica_dati(const char* filename){
		ifstream in;
		in.open(filename, ios::binary);
		if(in.fail()) exit(6);
		deserialize(in);
		in.close();
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}



