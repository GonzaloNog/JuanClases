/*


*/
#include <iostream>
#include <vector>
#include<fstream>
#include <string>

using namespace std;
int main()
{
    bool agregando = true;
    string nota;
    float num;
    vector<float> notasReprobadas;
    vector<float> notasAprobadas;

    float mejorNota = 0;
    float peorNota = 5;

    float aprNum = 0;
    while (agregando) 
    {
        getline(cin, nota);
        try{
            num = stof(nota);
            if (num != -1) {
                if (num >= 5 && num <= 10) {
                    notasAprobadas.push_back(num);
                }
                else if (num < 5 && num >= 0) {
                    notasReprobadas.push_back(num);
                }
                else
                    std::cout << "No ingreso una nota valida tiene que ser un numero entre 0 y 10 (-1 para deajr de agregar notas)" << std::endl;
            }
            else
                agregando = false;
            throw (nota);
        }
        catch(string nota) {
            //std::cout << "Tiene que ingresar un numero: "<< nota <<" no es un numero" << std::endl;
        }
        
    }

    //notas.push_back(10);
    


    std::cout << "Aprobadas" << std::endl;
    for (float nota : notasAprobadas)
    {
        aprNum += nota;
        if (nota > mejorNota) {
            mejorNota = nota;
        }
    }
    aprNum = aprNum / notasAprobadas.size();
    cout << "Promedio Notas Aprobadas: "<< aprNum << std::endl;
    cout << "MejorNota: " << mejorNota << std::endl;

    std::cout << "Desaprobadas" << std::endl;
    for (float nota : notasReprobadas)
    {
        aprNum += nota;
        if (nota < peorNota) {
            peorNota = nota;
        }
    }
    aprNum = aprNum / notasReprobadas.size();
    cout << "Promedio Notas Reprobadas: " << aprNum << std::endl;
    cout << "Peor nota: " << peorNota << std::endl;
}


