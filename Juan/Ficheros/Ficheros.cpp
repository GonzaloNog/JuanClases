#include <iostream>
#include<fstream>
#include <string>

using namespace std;

int main()
{

//Escritura
/*
    ofstream fichero("prueba.txt");
    fichero << "Esto es una línea" << endl;
    fichero << "Esto es otra";
    fichero << " y esto es continuación de la anterior" << endl;
    fichero.close();
*/
//Lectura unica palabra
/*
    ifstream fichero("prueba.txt");
    string linea;

    fichero >> linea;

    cout << "Se ha leido: " << endl;
    cout << linea << endl;

    fichero.close();
*/
    cout << "Dime el nombre del fichero: ";
    string nombre;
    getline(cin, nombre);

    ifstream fichero(nombre.c_str());
    string linea;

    getline(fichero, linea);
    cout << "Se ha leido: " << endl;
    cout << linea << endl;

    fichero.close();
    return 0;
}

