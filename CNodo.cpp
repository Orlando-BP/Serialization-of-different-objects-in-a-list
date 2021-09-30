#include "CNodo.h"
#include "CSerializable.h"
void CNodo::InsertarAdelante(CSerializable* nd) {
    CNodo* PNuevo = nullptr;
    PNuevo = new CNodo;
    PNuevo->Psig = this->Psig;
    PNuevo->Pant = this;
    this->Psig->Pant = PNuevo;
    this->Psig = PNuevo;
    PNuevo->Dato = nd;
}

CSerializable* CNodo::EliminarSiguiente() {
    CNodo* PEliminar = nullptr;
    PEliminar = this->Psig;
    CSerializable* dato = this->Psig->Dato;
    PEliminar->Psig->Pant = this;
    this->Psig = PEliminar->Psig;
    delete PEliminar;
    return dato;
}