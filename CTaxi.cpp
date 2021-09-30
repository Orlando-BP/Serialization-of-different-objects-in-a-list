#include "CTaxi.h"
#include <iostream>
#include <fstream>
using namespace std;

#define CLSID_Taxi 3

void CTaxi::acelerar() {
	velocidad += 50;
}

void CTaxi::Imprimir() {
	cout << "Soy un Taxi" << endl;
	cout << "mi velocidad es: " << velocidad << endl;
}

void CTaxi::Salvar(fstream& out) {
	out << CLSID_Taxi << endl;
	out << velocidad<<endl;
}
void CTaxi::Cargar(fstream& in) {
	in >> velocidad;
}
int CTaxi::getCLSID() {
	return CLSID_Taxi;
}