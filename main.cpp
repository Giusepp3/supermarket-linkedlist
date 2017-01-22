//Giuseppe Ferrara

#include <iostream>
#include <fstream>
#include <cstring>
#include "alimentari.h"
#include "prodottifreschi.h"

using namespace std;
using namespace supermarket;


int main() {
	
	prodottifreschi p2;

	p2.carica_dati("prodottifreschi.bin");
	
	p2.stampa_dati();

	return 0;
}
