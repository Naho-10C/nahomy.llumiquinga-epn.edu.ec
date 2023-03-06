#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;

//Constantes globales
const string NLLNOMBRE_COMPLETO = "Nahomy Nayeli Llumiquinga Cando";
const int NLLCEDULA = 1725630204;

struct nllcoordenada
{
    int  nllCap;
    string  nllGeo;
    string  nllArsenal;
    nllcoordenada *nllIzq;
    nllcoordenada *nllDer;
    
};

void nllLoading()
{ 
    int ind =0;
    
    for(int i=0; i<= 100; i++)
    {   
        if(i % 4 ==0)
            ind =0;

        cout  << "\r" << i << "%";
        Sleep(30);
    }
}

void nllLeerArchivo(string pathFile) 
{
    string s;
    fstream f;
    f.open(pathFile, ios_base::in);
    if ( !f.is_open() ) 
        cout << "Error de abrir el archivo." << endl;
    
    else
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),2);
        cout << "[+] Leyendo Coordenados" << endl;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout << "Error: Cap, Geo,   Tipo Arsenal" << endl;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),2);
        do 
        {
            nllLoading();
            getline( f, s );
            cout << "\t";
            cout << s << endl;
        }while( !f.eof() );
    f.close();
}


int main()
{
    nllLeerArchivo("files/archivodetexto.txt");
    system("pause>nul");
    system("cls");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "[+] Informacion Arbol Binario de capacidad belica" << endl;
    cout << "Developer-Nombre: " << NLLNOMBRE_COMPLETO << endl;
    cout << "Developer-Cedula: " << NLLCEDULA << endl;
    cout << "Developer Belica: " << endl;
    cout << "Developer-Total: " << endl;
    cout << "Developer-Total: " << endl;
    return 0;
}