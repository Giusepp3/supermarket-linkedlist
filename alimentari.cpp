#include "alimentari.h"

using namespace std;

namespace supermarket{
	
	alimentari::alimentari(){
		codice = new char[1];
		strcpy(codice,"");
		descrizione = new char[1];
		strcpy(descrizione,"");
		meseScad = 0;
		costo = 0;
		
	}
	
	alimentari::alimentari(const char* cod, const char* desc, const int scad, const float price){
		codice = new char[strlen(cod)+1];
		strcpy(codice,cod);
		descrizione = new char[strlen(desc)+1];
		strcpy(descrizione,desc);
		meseScad = scad;
		costo = price;
		
	}
	
	
	alimentari::alimentari(const alimentari & a){
		codice = new char[strlen(a.codice)+1];
		strcpy(codice,a.codice);
		descrizione = new char[strlen(a.descrizione)+1];
		strcpy(descrizione,a.descrizione);
		meseScad = a.meseScad;
		costo = a.costo;
		
	}
	
	alimentari::~alimentari(){
		delete [] codice;
		delete [] descrizione;
		
	}
	
	alimentari & alimentari::operator=(const alimentari & a){
		if(this==&a) return *this;
		codice = new char[strlen(a.codice)+1];
		strcpy(codice,a.codice);
		descrizione = new char[strlen(a.descrizione)+1];
		strcpy(descrizione,a.descrizione);
		meseScad = a.meseScad;
		costo = a.costo;
		return *this;
	}
	
	void alimentari::set_cod(const char* c){
		if(codice) delete [] codice;
		codice = new char[strlen(c)+1];
		strcpy(codice,c);
	}
	
	void alimentari::set_desc(const char* d){
		if (descrizione) delete [] descrizione;
		descrizione = new char[strlen(d)+1];
		strcpy(descrizione,d);
		
	}
	
	void alimentari::set_meseScad(const int m){
		meseScad = m;
	}
	
	void alimentari::set_costo(const float p){
		costo = p;
	}
	
	
	void alimentari::print(ostream & os)const{
		os << codice << ' ' << descrizione << ' ' << meseScad << ' ' << costo << ' ';
	}
	
	ostream & operator<<(ostream & os, const alimentari & a){
		a.print(os);
		return os;
	}
	
	void alimentari::stampa_dati()const{
		cout << codice << ' ' << descrizione << ' ' << meseScad << ' ' << costo << ' ';
	}
	
	void alimentari::serialize(ofstream & of)const{
		int len1,len2;
		len1=strlen(codice)+1;
		len2=strlen(descrizione)+1;
		of.write((char*)&len1,sizeof(len1));
		of.write(codice,len1);
		of.write((char*)&len2,sizeof(len2));
		of.write(descrizione,len2);
		of.write((char*)&meseScad,sizeof(meseScad));
		of.write((char*)&costo,sizeof(costo));
	}
	
	void alimentari::memorizza_dati(const char* filename)const{
		ofstream of;
		of.open(filename, ios::binary | ios::out);
		if(of.fail()) exit(5);
		serialize(of);
		of.close();
	}
	
	void alimentari::deserialize(ifstream & in){
		char* buffer;
		int len;
		in.read((char*)&len,sizeof(len));
		buffer = new char[len];
		in.read(buffer,len);
		set_cod(buffer);
		delete [] buffer;
		in.read((char*)&len,sizeof(len));
		buffer= new char[len];
		in.read(buffer,len);
		set_desc(buffer);
		delete [] buffer;
		in.read((char*)&meseScad,sizeof(meseScad));
		in.read((char*)&costo,sizeof(costo));
		
	}
	
	
	void alimentari::carica_dati(const char* filename){
		ifstream  in;
		in.open("alimentari.bin",ios::binary);
		if(in.fail()) exit(6);
		deserialize(in);
		in.close();
	}
	
	
	
	
}
