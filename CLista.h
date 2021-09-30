#pragma once
#include "CNodo.h"
#include "CSerializable.h"
#include "CImprimible.h"
#include <fstream>
class CLista : public CImprimible
{
    //friend class CNodo;
private:
    CNodo Inicio;
    CNodo Final;

public:
    void InsertarAlInicio(CSerializable* nd);
    void InsertarAlFinal(CSerializable* nd);
    CSerializable* EliminarAlInicio();
    CSerializable* EliminarAlFinal();
    void Imprimir();
    void Vaciar();
    int Size();
    bool IsEmpty();
    bool IsFull();
    void Salvar(fstream& out);
    void Cargar(fstream& in);
    int getCLSID();
    CLista();
    ~CLista();
};

