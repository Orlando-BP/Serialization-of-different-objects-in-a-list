#pragma once
#include <fstream>
using namespace std;
class CSerializable
{
public:
	virtual void Salvar(fstream& out) = 0;
	virtual void Cargar(fstream& in) = 0;
	virtual int getCLSID() = 0;
};

