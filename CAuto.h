#pragma once
#include "CImprimible.h"
class CAuto:public CImprimible
{
public:
	int velocidad;
	CAuto();
	virtual void acelerar()=0;
};

