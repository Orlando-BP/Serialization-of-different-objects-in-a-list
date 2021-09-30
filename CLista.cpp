#include <iostream>
#include "CLista.h"
#include "CNodo.h"
#include "CSerializable.h"
#include "CImprimible.h"
#include "CPersona.h"
#include "CBocho.h"
#include "CTaxi.h"

#define CLSID_Persona 1
#define CLSID_Bocho 2
#define CLSID_Taxi 3
#define CLSID_Lista 10

using namespace std;
void CLista::InsertarAlInicio(CSerializable* nd)
{
    Inicio.InsertarAdelante(nd);
}

void CLista::InsertarAlFinal(CSerializable* nd)
{
    Final.Pant->InsertarAdelante(nd);
}

CSerializable* CLista::EliminarAlInicio()
{
    return Inicio.EliminarSiguiente();
}

CSerializable* CLista::EliminarAlFinal()
{
    return Final.Pant->Pant->EliminarSiguiente();
}

void CLista::Imprimir()
{
    CNodo* AUX = Inicio.Psig;
    while (AUX != &Final) {
        ((CImprimible*)(AUX->Dato))->Imprimir();
        cout << endl;
        AUX = AUX->Psig;
    }
}

void CLista::Vaciar()
{

    while (Inicio.Psig != &Final) {
        Inicio.EliminarSiguiente();
    }
}

int CLista::Size()
{
    CNodo* AUX = Inicio.Psig;
    int N = 0;
    while (AUX != &Final) {
        N++;
        AUX = AUX->Psig;
    }
    return N;
}

bool CLista::IsEmpty()
{
    return (Inicio.Psig == &Final);
}

bool CLista::IsFull()
{
    return false;
}

void CLista::Salvar(fstream& out)
{
    out << CLSID_Lista << endl;
    out << Size() << endl;
    CNodo* AUX = Inicio.Psig;
    while (AUX != &Final) {
        (AUX->Dato)->Salvar(out);
        AUX = AUX->Psig;
    }
}

void CLista::Cargar(fstream& in)
{
    int tam,record,caso;
    in >> tam;
    for (record = 0; record < tam; record++) {
        in >> caso;
        switch (caso) {
        case CLSID_Persona:
        {
            CSerializable * P = new CPersona(0,0);
            P->Cargar(in);
            InsertarAlFinal(P);
        }
            break;
        case CLSID_Bocho:
        {
            CSerializable* B = new CBocho();
            B->Cargar(in);
            InsertarAlFinal(B);
        }
            break;
        case CLSID_Taxi:
        {
            CSerializable* T = new CTaxi();
            T->Cargar(in);
            InsertarAlFinal(T);
        }
            break;
        case CLSID_Lista:
        {
            CSerializable* L = new CLista();
            L->Cargar(in); 
            InsertarAlFinal(L);
        }
            break;
        default:
            cout << "Error desconocido" << endl;
            break;
        }
    }
}

int CLista::getCLSID() {
    return CLSID_Lista;
}

CLista::CLista()
{
    Inicio.Dato = 0;
    Final.Dato = 0;
    Inicio.Psig = &Final;
    Final.Pant = &Inicio;
}

CLista::~CLista()
{
    Vaciar();
}
