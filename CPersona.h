#pragma once
#include "CImprimible.h"
#include <fstream>
using namespace std;
class CPersona:public CImprimible
{
private:
	int edad;
	float estatura;
public:
	CPersona(int ed,float es);
	void Imprimir();
	void Salvar(fstream& out);
	void Cargar(fstream& in);
	int getCLSID();
};

