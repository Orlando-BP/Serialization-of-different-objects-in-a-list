#include <iostream>
#include "CLista.h"
#include "CBocho.h"
#include "CTaxi.h"
#include "CPersona.h"
#include <fstream>

using namespace std;
int main()
{
    CLista Lista;
    CLista* Lista2 =new CLista;
    CLista* Lista3 = new CLista;
    CPersona* Orlando=new CPersona(20, 1.8);
    CTaxi* B_D_joe=new CTaxi;
    B_D_joe->acelerar();
    B_D_joe->acelerar();
    CBocho* Escarabajo= new CBocho;
    Escarabajo->acelerar();

    Lista.InsertarAlInicio(Orlando);
    Lista.InsertarAlFinal(B_D_joe);
    Lista.InsertarAlFinal(Escarabajo);
    Lista2->InsertarAlInicio(Orlando);
    Lista2->InsertarAlFinal(B_D_joe);
    Lista.InsertarAlFinal(Lista2);
    cout << endl;

    fstream out;
    out.open("Archivo.txt", ios::out);
    if (out.is_open()) {
        Lista.Salvar(out);
        out.close();
    }
    else
        cout << "No se pudo abrir el archivo." << endl;

    fstream in;
    in.open("Archivo.txt", ios::in);
    if (in.is_open()) {
        int i;
        in >> i;
        if(i==10){
            Lista3->Cargar(in);
        }
        in.close();
    }
    else
        cout << "No se pudo abrir el archivo." << endl;

    Lista3->Imprimir();
    return 0;
}
