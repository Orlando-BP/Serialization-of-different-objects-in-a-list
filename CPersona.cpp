#include "CPersona.h"
#include <iostream>
#include <fstream>
using namespace std;

#define CLSID_Persona 1

CPersona::CPersona(int ed, float es) {
	edad = ed;
	estatura = es;
}
void CPersona::Imprimir() {
	cout << "Soy una persona" << endl;
	cout << "mi edad es: " << edad << endl;
	cout << "mi estatura es: " << estatura << endl;
}

void CPersona::Salvar(fstream& out) {
	out << CLSID_Persona << endl;
	out << edad << endl;
	out << estatura << endl;
}
void CPersona::Cargar(fstream& in) {
	in >> edad;
	in >> estatura;
}

int CPersona::getCLSID() {
	return CLSID_Persona;
}