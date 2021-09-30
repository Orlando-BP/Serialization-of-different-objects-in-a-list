#pragma once
#include "CAuto.h"
#include <fstream>
using namespace std;
class CBocho:public CAuto
{
public:
	void acelerar();
	void Imprimir();
	void Salvar(fstream& out);
	void Cargar(fstream& in);
	int getCLSID();
};

