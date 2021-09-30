#include "CBocho.h"
#include <iostream>
#include <fstream>
using namespace std;

#define CLSID_Bocho 2

void CBocho::acelerar() {
	velocidad += 10;
}

void CBocho::Imprimir() {
	cout << "Soy un Bocho" << endl;
	cout << "mi velocidad es: " << velocidad << endl;
}
void CBocho::Salvar(fstream& out) {
	out << CLSID_Bocho << endl;
	out << velocidad << endl;
}
void CBocho::Cargar(fstream& in) {
	in >> velocidad;
}
int CBocho::getCLSID()
{
	return CLSID_Bocho;
}
