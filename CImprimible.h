#pragma once
#include "CNodo.h"
#include <fstream>
#include "CSerializable.h"
using namespace std;
class CImprimible: public CSerializable
{
	friend class CNodo;
public:
	virtual void Imprimir() = 0;
};

