#include <iostream>

using namespace std;


void changeNumPunt(int* punt) {
    *punt = 30;
}

int changeNum(int num) {
    num = 0;
    return num;
}

int main()
{
    int variable; //Creamos un entero
    int* apuntador = &variable;//Creamos una apuntador a la posición en memoria de "variable"
    *apuntador = 20; //Le asignamos un valor a esa posición de memoria.

    cout<<"Puntero: "<< apuntador<<" Valor: "<<*apuntador << endl;

    *apuntador = changeNum(*apuntador);

    cout << "Puntero: " << apuntador << " Valor: " << *apuntador << endl;

    changeNumPunt(apuntador);

    cout << "Puntero: " << apuntador << " Valor: " << *apuntador << endl;

    apuntador++;

    cout << "Puntero: " << apuntador << " Valor: " << *apuntador << endl;
    //delete apuntador; //Después de operar con punteros es necesario liberar la memoria. puntero = NULL;
}

