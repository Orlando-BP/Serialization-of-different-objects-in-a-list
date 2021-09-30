#pragma once
#include "CSerializable.h"
class CNodo
{
friend class CLista;
friend class CSerializable;
private:
    CNodo* Psig;
    CNodo* Pant;
    CSerializable* Dato;

    void InsertarAdelante(CSerializable* nd);
    CSerializable* EliminarSiguiente();
};

